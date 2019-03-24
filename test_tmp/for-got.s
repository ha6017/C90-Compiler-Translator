.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
SW $4, -8($fp)
ADDI $9, $0, 0
SW $9, -12 ($fp)
ADDI $9, $0, 0
SW $9, -16 ($fp)

top_1_0:
LW $10, -16($fp)
nop
LW $11, -8($fp)
nop
SLT $9, $10, $11
BEQ $9, $0, bottom_1_0
nop
LW $11, -12($fp)
nop
LW $12, -16($fp)
nop
ADDU $10, $11, $12
ADDU $8, $0, $10
SW $8, -12($fp)
LW $10, -16($fp)
nop
ADDU $8, $0, $10
ADDI $10, $10, 1
SW $10, -16($fp)
J top_1_0
nop

bottom_1_0:
LW $2, -12($fp)
nop
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
.end f
