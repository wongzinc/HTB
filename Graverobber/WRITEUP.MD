# Challenge Name

**Category:** Reverse Engineering
**Difficulty:** Very Easy
**Platform:** HTB 
**Binary:** Graverobber

## 📝 Challenge Description
We're breaking into the catacombs to find a rumoured great treasure - I hope there's no vengeful spirits down there...

## 🔍 Initial Recon
```bash
ulong main(void)

{
    int iVar1;
    ulong uVar2;
    int64_t in_FS_OFFSET;
    uint32_t uStack_ec;
    uchar auStack_e8 [144];
    ulong uStack_58;
    ulong uStack_50;
    ulong uStack_48;
    ulong uStack_40;
    ulong uStack_38;
    ulong uStack_30;
    ulong uStack_28;
    ulong uStack_20;
    uint uStack_18;
    int64_t iStack_10;
    
    iStack_10 = *(in_FS_OFFSET + 0x28);
    uStack_58 = 0;
    uStack_50 = 0;
    uStack_48 = 0;
    uStack_40 = 0;
    uStack_38 = 0;
    uStack_30 = 0;
    uStack_28 = 0;
    uStack_20 = 0;
    uStack_18 = 0;
    uStack_ec = 0;
    do {
        if (0x1f < uStack_ec) {
            sym.imp.puts("We found the treasure! (I hope it\'s not cursed)");
            uVar2 = 0;
code_r0x00001256:
            if (iStack_10 != *(in_FS_OFFSET + 0x28)) {
    //WARNING: Subroutine does not return
                sym.imp.__stack_chk_fail();
            }
            return uVar2;
        }
        *(&uStack_58 + uStack_ec * 2) = L"HTB{br34k1n9_d0wn_th3_sysc4ll5}"[uStack_ec];
        *(&uStack_58 + uStack_ec * 2 + 1) = 0x2f;
        iVar1 = sym.imp.stat(&uStack_58,auStack_e8);
        if (iVar1 != 0) {
            sym.imp.puts("We took a wrong turning!");
            uVar2 = 1;
            goto code_r0x00001256;
        }
        uStack_ec = uStack_ec + 1;
    } while( true );
}
```

## Analysis 
It is easy to see that the flag is lie inside the code. Ea3y Peasy!
It's because the pdg help us deal with lots of problem. 

## Alternative Solution
Use strace to check what is going on in the process of running this binary file.

```bash
newfstatat(AT_FDCWD, "H/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/w/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/w/n/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/w/n/_/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/w/n/_/t/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/w/n/_/t/h/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/w/n/_/t/h/3/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/w/n/_/t/h/3/_/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/w/n/_/t/h/3/_/s/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/w/n/_/t/h/3/_/s/y/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/w/n/_/t/h/3/_/s/y/s/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/w/n/_/t/h/3/_/s/y/s/c/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/w/n/_/t/h/3/_/s/y/s/c/4/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/w/n/_/t/h/3/_/s/y/s/c/4/l/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/w/n/_/t/h/3/_/s/y/s/c/4/l/l/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/w/n/_/t/h/3/_/s/y/s/c/4/l/l/5/", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "H/T/B/{/b/r/3/4/k/1/n/9/_/d/0/w/n/_/t/h/3/_/s/y/s/c/4/l/l/5/}/", 0x7ffcdd717940, 0) = -1 ENOENT (No such file or directory)

```
No such file or directory -> mkdir -p H/T/...... 
We traced the system calls until the flag finally emerged.

## Flag
HTB{br34k1n9_d0wn_th3_sysc4ll5}
