# CHIP 8/2

Points: **383 Points**

I made this sweet web-based chip8 emulator.
The last 512 bytes of memory are protected!

http://167.172.165.153:60003/

Note: This challenge can bee solved using only chip8 instructions.

## Solve

The web page was the same of the [CHIP 8/1](https://github.com/ShingekiNoChikungunya/write-ups/tree/master/HackTM-CTF-2020/CHIP_8_%231). That being said, the difference was that the chall description hints us that the flag is in the last bytes of the memory.

The protected area started at hex(4096 - 512) = 0xE00. As expected if we tried to put *I* register at that adress we get an error: 

```
SECURITY VIOLATION DETECTED: Can not set I outside of legal memory range.
```

So again, our goal was to find a way to bypass this memory protection.

The instruction FX29 couldn't take us there since the register V[0-F] could only store values from 0 to 255, and following the math displayed in the last chall:

```
I = VX * 5, where VX = max(VX). So I = 1275
```

far from the desired 3584 (0xE00) adress.

We didn't know if we needed to get PC past 0xE00 or I.
At first we tought of getting PC past the memory protection and then pointing I to PC, as a way of start drawing the protected memory again. But we couldn't find any instructions for that.

Anyway, our first guess was at the instruction B *NNN*: PC = V0 + *NNN*.

```
6001 ; V0=01
BDFF ; PC = V0 + 3583
```

**RUN**. But suddenly, Error: **Invalid instruction: 5F61**. What? As soon as we checked the other registers.

```
PC = 3922 (0x0F52)
Cycles = 170
Last instruction = 7279
```

Woah.
We're in >:). But better than that, we branched to the protected memory and started executing code in there as if it was our code. Sick.

As the last instruction was represented like Hex. We executed the program step at step and taking notes about what the last instruction looked like. We ended up with something like that before the crash:

```
AAAA
AAAA
....
AAAA
AA48
6163
6B54
4D7B
6436
655F
6A75
7279
5F61 <- the crash
```

We copied the bytes from AA48 until 5F61 and decoded it. Output:

```
ªHackTM{d6e_jury_a
```

We were at the right track.

But, we couldn't continue with the last payload, at least we tought, we tought we couldn't set adress bigger than 0xDFF, e.g.: BE00 in the instruction because of the memory protection, and with that adress fixed at 0xDFF we could only go up until 0xDFF + 0xFF (255) = 0xEFE (3838), but we crashed at 3922. So we started looking at another approach.

By testing another methods again, we noticed that we could direct jump by calling a subroutine, 2 *NNN*. 2F40 would point  PC to 0x0F40.
**Observation**: as each instruction is composed of a byte (0x00-0xFF), to go the next instruction we should add 2.

We jumped to the line where the error started, got some more errors while pressing step, but in the end we got:

```
AA48
6163
6B54
4D7B
6436
655F
6A75
7279
5F61 
6E64
5F33
7833
6375
7431
6F6E
7DAA
```

That removing the 0xAA byte at the end and at the start, we got:

```
HackTM{d6e_jury_and_3x3cut1on}
```

Sends flag.
**Incorrect.**

Looking at the flag, it looks odd indeed. Is that 6 supposed to be there? d6e doesn't look like a word.

The line that produced that 6 was: 6436.

It looks like it is supposed to be that way. And then, boom, the last line was **4D7B**, and what with that? 4D7B is a branch instruction, 4 *X NN*,

```
if (VX != NN) jump next instruction
```

as V13 was not 123 (0x7B), we jumped the next instruction. This all could be avoided if we inserted each adress manually with 2NNN, but as we didn't get any error until 0x0F50, we jumped to 0x0F40 and would go step by step totally forgetting that in fact, **WE WERE EXECUTING CODE**.

By going step-by-step we noticed that we were jumping the instruction at 0x0F48. That reveals store 6A75. That decoded is "ju". So the final flag is:

```
HackTM{jud6e_jury_and_3x3cut1on}
```

and the final payload was:

```
2F40 ; execute two steps, check last instruction, RESET, and add 2 in F40
```