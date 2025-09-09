# Challenge Name

**Category:** Reverse Engineering
**Difficulty:** Very Easy
**Platform:** HTB 
**Binary:** FlagCasino

## 📝 Challenge Description
The team stumbles into a long-abandoned casino. As you enter, the lights and music whir to life, and a staff of robots begin moving around and offering games, while skeletons of prewar patrons are slumped at slot machines. A robotic dealer waves you over and promises great wealth if you can win - can you beat the house and gather funds for the mission?

## 🔍 Initial Recon
```bash
ulong main(void)

{
    int iVar1;
    char cStack_d;
    uint32_t uStack_c;
    
    sym.imp.puts("[ ** WELCOME TO ROBO CASINO **]");
    sym.imp.puts(
                "     ,     ,\n    (\\____/)\n     (_oo_)\n       (O)\n     __||__    \\)\n  []/______\\[] /\n  / \\______/ \\/\n /    /__\\\n(\\   /____\\\n---------------------"
                );
    sym.imp.puts("[*** PLEASE PLACE YOUR BETS ***]");
    uStack_c = 0;
    while( true ) {
        if (0x1d < uStack_c) {
            sym.imp.puts("[ ** HOUSE BALANCE $0 - PLEASE COME BACK LATER ** ]");
            return 0;
        }
        sym.imp.printf(0x20f9);
        iVar1 = sym.imp.__isoc99_scanf(0x20fc,&cStack_d);
        if (iVar1 != 1) break;
        sym.imp.srand(cStack_d);
        iVar1 = sym.imp.rand();
        if (iVar1 != *(obj.check + uStack_c * 4)) {
            sym.imp.puts("[ * INCORRECT * ]");
            sym.imp.puts("[ *** ACTIVATING SECURITY SYSTEM - PLEASE VACATE *** ]");
    //WARNING: Subroutine does not return
            sym.imp.exit(0xfffffffe);
        }
        sym.imp.puts("[ * CORRECT *]");
        uStack_c = uStack_c + 1;
    }
    //WARNING: Subroutine does not return
    sym.imp.exit(0xffffffff);
}


```

## 🔧 Analysis
Tools: radare2

Steps:
```Dynamic analysis (radare2)
r2 ./wide db.exe
aaa
afl
s sym.main
pdg

```

First of all, `0x1d < uStack_c` means the loop is gonna run for 29 times. The random generator is not really safe since the random seed depends on user's input. According to Official Solution, we can map each character to a specific random number. By stepping through check array, we convert back each random numbers store in check array to its original character.

## Solution
```python
import ctypes

libc = ctypes.CDLL('libc.so.6') # CDLL(C Dynamic Link Library)
                                # libc is now a python object, we can call the function inside like
                                # rand(), srand(), printf() directly
mapping = {}
for i in range(255):  # 0x00 ~ 0xFF(255)
    libc.srand(i)
    mapping[libc.rand()] = chr(i)    # mapping[rand] = character

from pwn import *

flag = ""
e = ELF('./casino')
for j in range(30):
    val = e.u32(e.sym['check'] + j*4)  # u32() - 檔指定地址讀一個 32-bit(4-bytes)無號整數
    flag += mapping[val]

print(flag)
```



## Result
```bash
root@kali:~/Documents/htb# python3 exploit_casino.py 
[*] '/root/Documents/htb/casino'
    Arch:       amd64-64-little
    RELRO:      Partial RELRO
    Stack:      No canary found
    NX:         NX enabled
    PIE:        PIE enabled
    Stripped:   No
HTB{r4nd_1s_sup3r_pr3d1ct4bl3}
```
## Flag
HTB{r4nd_1s_sup3r_pr3d1ct4bl3}
