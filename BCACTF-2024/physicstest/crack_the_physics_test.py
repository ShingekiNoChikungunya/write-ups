import string
from pwn import *
import time


def get_answer(question):
    if b'A spring' in question:
        return b"x*y"
    if b'A red ball' in question:
        return b"x/3+2*y/3"
    if b'A box' in question:
        return b"x*y*y/2"

io = remote('challs.bcactf.com', 30586)

caracteres = string.printable
caracteres =caracteres[:-2]

line = io.recvuntil(b'Answer: ')
question = line.split(b'\n')[8]
# print(f"questão fora do for: {question}")

answer = get_answer(question)
# print(f"resposta: {answer}")
io.sendline(answer)

line = io.recvuntil(b'---------------------------------------------------------------------')
is_right = line.split(b'\n')[1]
# print(is_right)

letter = ""
i = 0
flag = ""

while letter != "}":
    for c in caracteres:
        line = io.recvuntil(b'Answer: ')

        question = line.split(b'\n')[3]
        # print(f"questão: {question}")

        answer = get_answer(question)
        # print(f"resposta: {answer}")
        ascii_caracter = str(ord(c)).encode('utf-8')
        index = str(i).encode('utf-8')
        answer = answer + b"+ord(flag[" + index + b"])-" + ascii_caracter
        # print(answer)
        io.sendline(answer)

        line = io.recvuntil(b'---------------------------------------------------------------------')
        is_right = line.split(b'\n')[1]
        # print(f"certo/errado: {is_right}")
        if b'FAILED' in is_right:
            continue
        if b'Good' in is_right:
            i += 1
            flag += c
            letter = c
            print(f"[*] -------- FLAG: {flag}")
            break

print(f"FLAG: {flag}")
