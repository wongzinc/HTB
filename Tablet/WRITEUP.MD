# Challenge Name

**Category:** Reverse Engineering
**Difficulty:** Very Easy
**Platform:** HTB 
**Binary:** Shattered Tablet

## 📝 Challenge Description
Deep in an ancient tomb, you've discovered a stone tablet with secret information on the locations of other relics. However, while dodging a poison dart, it slipped from your hands and shattered into hundreds of pieces. Can you reassemble it and read the clues?

## 🔍 Initial Recon
```bash
ulong main(void)

{
    ulong uStack_48;
    ulong uStack_40;
    ulong uStack_38;
    ulong uStack_30;
    ulong uStack_28;
    ulong uStack_20;
    ulong uStack_18;
    ulong uStack_10;
    
    uStack_48 = 0;
    uStack_40 = 0;
    uStack_38 = 0;
    uStack_30 = 0;
    uStack_28 = 0;
    uStack_20 = 0;
    uStack_18 = 0;
    uStack_10 = 0;
    sym.imp.printf("Hmmmm... I think the tablet says: ");
    sym.imp.fgets(&uStack_48,0x40,_reloc.stdin);
    if (((((uStack_28._2_1_ == '4') && (uStack_38._4_1_ == '3')) && (uStack_28._4_1_ == 'r')) &&
        ((((uStack_48._1_1_ == 'T' && (uStack_38._5_1_ == 'v')) &&
          ((uStack_48._6_1_ == '0' && ((uStack_28._7_1_ == '}' && (uStack_28._6_1_ == 'd')))))) &&
         (uStack_30._7_1_ == 'r')))) &&
       ((((((uStack_30._5_1_ == '3' && (uStack_40 == '3')) && (uStack_38._6_1_ == 'e')) &&
          ((uStack_28._3_1_ == '1' && (uStack_48._5_1_ == 'r')))) &&
         ((uStack_48 == 'H' && ((uStack_28 == '3' && (uStack_38._2_1_ == '.')))))) &&
        (((((uStack_40._5_1_ == '4' &&
            (((((uStack_48._3_1_ == '{' && (uStack_40._2_1_ == '_')) && (uStack_38 == '.')) &&
              ((uStack_48._4_1_ == 'b' && (uStack_48._7_1_ == 'k')))) && (uStack_40._7_1_ == 't')))) &&
           (((uStack_40._6_1_ == 'r' && (uStack_38._3_1_ == 'n')) &&
            ((uStack_30._1_1_ == 't' &&
             (((uStack_38._1_1_ == '.' && (uStack_40._1_1_ == 'n')) && (uStack_30._6_1_ == '_')))))))) &&
          (((uStack_30._2_1_ == '0' && (uStack_30 == '_')) && (uStack_40._4_1_ == 'p')))) &&
         ((((uStack_38._7_1_ == 'r' && (uStack_30._4_1_ == 'b')) &&
           ((uStack_28._1_1_ == 'p' &&
            (((uStack_48._2_1_ == 'B' && (uStack_30._3_1_ == '_')) && (uStack_40._3_1_ == '4')))))) &&
          (uStack_28._5_1_ == '3')))))))) {
        sym.imp.puts("Yes! That\'s right!");
    }
    else {
        sym.imp.puts("No... not that");
    }
    return 0;
}
```

## 🔧 Analysis
Tools: ghidra

![alt text](image.png)

Use renaming method for each uStack, for example uStack10 = first, uStack20 = second and so on.
## 4
fourth = 3
fourth11 = p
fourth21 = 4
fourth31 = l
fourth41 = r
fourth51 = 3
fourth61 = d
fourth71 = }

## 5
fifth = _
fifth11 = t
fifth21 = 0
fifth31 = _
fifth41 = b
fifth51 = 3
fifth61 = _
fifth71 = r

HTB{br0k3n_4p4rt...n3ver_t0_b3_r3p41r3d}

## 6
sixth = .
sixth11 = .
sixth21 = .
sixth31 = n
sixth41 = 3
sixth51 = v
sixth61 = e
sixth71 = r

## 7
seventh = 3
seventh11 = n
seventh21 = _
seventh31 = 4
seventh41 = p
seventh51 = 4
seventh61 = r
seventh71 = t

## 8
eighth = H
eighth11 = T
eighth21 = B
eighth31 = {
eighth41 = b
eighth51 = r
eighth61= 0
eighth71 = k

it's leet speak1337!!!

## Flag
HTB{br0k3n_4p4rt...n3ver_t0_b3_r3p41r3d}







