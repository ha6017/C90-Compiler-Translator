.text
.align 2
.globl makeFive
.ent makeFive
makeFive:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
SW $4, -8($fp)
ADDI $9, $0, 5
ADDU $8, $0, $9
SW $8, -8($fp)
LW $2, -8($fp)
nop
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
.end makeFive

.text
.align 2
.globl myFunction
.ent myFunction
myFunction:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $9, $0, 12
SW $9, -8 ($fp)
LW $4, -8($fp)
nop
ADDI $sp, $fp, -12
JAL makeFive
nop
ADDU $9, $2, $0
SW $9, -12 ($fp)
ADDI $9, $0, 6969
LW $12, -12($fp)
nop
ADDU $12, $12, $9
ADDU $8, $0, $12
SW $12, -12($fp)
LW $2, -12($fp)
nop
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
.end myFunction
