# RSA is easy #1

## The problem 
In this chall was given two files: one containing the RSA public key and an array of ciphered items, and the other containing the code that generated that file.

After reading this code, it was noticed that each ciphered item was a single ```char```.

This is a huge mistake when some one wants to encode a message, as it limits the possibilities of each ciphered item to size of ```char```, making it possible ```to test every character``` for each ciphered item.

## Solution

Basically for each ciphered item and for each character, the character was ciphered and compared to the item, if they were the same the character was stored in an array.

finally, that array was the flag!

```python
flag = []
chars = string.printable[:-6]
for ciphered in ciphered_chars:
    j = 0
    while enc(public_key, chars[j])[0] != ciphered:
        j += 1
    flag.append(chars[j])
print(''.join(flag))

```

## Flag
- HackTM{why_ar3_MY_pR1va7es_pu8l1C_??}
- Points: 50