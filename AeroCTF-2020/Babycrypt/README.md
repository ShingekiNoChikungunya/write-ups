# Babycrypt

Points: **326 Points**

>"We develope our own program for encrypting text.
But it is not very convenient and seems to encrypt not secure. 
Try a plaintext attack to get key and decode flag!"

## Challange

In this challenge we receive a stripped ELF 64-bit executable **'bcry'** and a text file **'note.dat'**:

```
key: %key%
text: test_test_test_test_test
Encoded: 7685737a9f7895737a9f84857b769f7a657b769f78898378

key: %key%
text: qwertyuiopasdfgh
Encoded: 717785747885858d6f7e917364686776

key: %key%
text: skIllaoInasJjklqo19akq9k13k45k69alq1
Encoded: 7393a992708d8fad708d83aa7273707d6f3939856b7d398bb53b8b34b573b6c5618e7135

key: %key%
text: %flag%
Encoded: 8185748f7b3b3a3565454584b8babbb8b441323ebc8b3a86b5899283b9c2c56d64388889b781


*Note: in all three cases used one key*
```

Upon executing the 'bcry' file, we are requested a key and, if we inform a valid key, a text for encryption. The program then returns the encrypted text.

## Recon

First of all, we needed to know the key length that must be given. To do that, we used the disassembler/decompiler [cutter](https://cutter.re/) and searched the code for the 'Incorrect key size' statement. The uncovered key size length was 16.

After uncovering the key size, we fuzzled arround with the executable and noted that if you altered just one character in the key or in the text, there is always just one byte altered in the encrypted text. With this in mind and with the cases given in the **'note.dat'** file, we can uncover the key used for encryption by using the text in the file and by mapping each character in the key to its respective position in the encrypted text. After that we can brute force each byte with the worst case scenario complexity of $$(16*17)$$ for each encrypted text; being 17 the number of accepted characters to be given in the key when running **'bcry'**.

## Reversing

We first mapped all the key character position to the corresponding encrypted text position (note that, after the $$16^{th}$$ byte, the position pattern repeats its self as in *Pos % 16*). Then, to start abusing the uncovered fact, we used the following python code:
```python
import subprocess
import string
 
iterator =  {
    0:0, 1:11, 2:10, 3:9,
    4:1, 5:12, 6:15, 7:8,
    8:2, 9:13, 10:14, 11:7,
    12:3, 13:4, 14:5, 15:6
}
 
 
def encrypt(key, text):
    '''This functions runs the bcry file with the text and key provided and 
    returns the output'''
    key = key.encode('utf-8')+b"\n"
    text = text.encode('utf-8')+b"\n"
    process = subprocess.Popen(["./bcry"], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    process.stdin.write(key)
    process.stdin.write(text)
    encoded = process.communicate()[0].decode("utf-8").rstrip('\n').split(":")[-1].strip()
    process.stdin.close()
    return encoded
 
 
possible_keys = []
key = list("abcdefg023157799")
enc_data = [
            "7685737a9f7895737a9f84857b769f7a657b769f78898378",
            "717785747885858d6f7e917364686776",
            '7393a992708d8fad708d83aa7273707d6f3939856b7d398bb53b8b34b573b6c5618e7135'
           ]
 
w1 = "test_test_test_test_test"
w2 = "qwertyuiopasdfgh"
w3 = "skIllaoInasJjklqo19akq9k13k45k69alq1"

for i in range(0, 128):
    if(i % 100 == 0):
    for c in list('abcdefgh0123456789'):
       
        try_key = list(key)
        try_key[iterator[i % 16]] = c
        try_key = ''.join(try_key)
       
        m1 = (i % len(w1))*2
        m2 = (i % len(w2))*2
        m3 = (i % len(w3))*2
       
        if(
            (encrypt(try_key, w1)[m1 : m1+2] == enc_data[0][m1:m1+2])
          and
            (encrypt(try_key, w2)[m2 : m2+2] == enc_data[1][m2:m2+2])
          and
            (encrypt(try_key, w3)[m3 : m3+2] == enc_data[2][m3:m3+2])
          ):
            key = try_key
            t1 = encrypt(key, w1) == enc_data[0]
            t2 = encrypt(key, w2) == enc_data[1]
            t3 = encrypt(key, w3) == enc_data[2]
            if t1 and t2 and t3:
                print("MATEI", key)
            if t1 and t2 or t3:
                if key not in possible:
                    possible.append(key)
```

The code above then return us all the possible keys that can be used to encrypt ```w1 and w2 or 23```.

With the keys in hand we can apply the same logic to print out the original flag, altering each character in the possible flag and comparing the correspondent byte to the encrypted message byte provided in the **'note.dat'** file. The corresponding byte position will always be ```[i*2:i*2+2]``` in which *i* is the position of the character in the text to be encrypted. Using this python code to append the previous one, we can print out the flag:

```python
chuteira = string.printable[:-6]
 
flag = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
result = "8185748f7b3b3a3565454584b8babbb8b441323ebc8b3a86b5899283b9c2c56d64388889b781"

for k in keys:
    for f in range(0, len(flag)):
        for c in chuteira:
            try_flag = list(flag)
            try_flag[f] = c
            try_flag = ''.join(try_flag)
           
            pos = encrypt(k, try_flag)
            if(pos[f*2:f*2+2] == result[f*2:f*2+2]):
                flag = try_flag
    print(flag)
```

After executing the code, we get three possible flags, in which **Aero{381a95d003629088c8f1ebc189ab6fe7}** is the correct one.
