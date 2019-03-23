.text
.align 2
.globl makeFive
.ent makeFive
makeFive:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
SW $4, -8($fp)
LW $12, -8($fp)
nop
ADDI $16, $0, 5
SLT $9, $12, $16
BEQ $9, $0, L_2
nop
LW $12, -8($fp)
nop
ADDU $8, $0, $12
ADDI $12, $12, 1
SW $12, -8($fp)
LW $4, -8($fp)
nop
ADDI $sp, $fp, -12
JAL makeFive
nop
ADDU $2, $2, $0
J L_3
nop
L_2:
LW $2, -8($fp)
nop
L_3:
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
.end makeFive
