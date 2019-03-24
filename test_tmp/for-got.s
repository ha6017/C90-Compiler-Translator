.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
SW $4, -8($fp)
ADDI $17, $0, 0
SW $17, -12 ($fp)
ADDI $17, $0, 0
SW $17, -16 ($fp)

top_1_0:
LW $20, -16($fp)
nop
LW $24, -8($fp)
nop
SLT $17, $20, $24
BEQ $17, $0, bottom_1_0
nop
LW $24, -12($fp)
nop
LW $25, -16($fp)
nop
ADDU $20, $24, $25
ADDU $16, $0, $20
SW $16, -12($fp)
LW $20, -16($fp)
nop
ADDU $16, $0, $20
ADDI $20, $20, 1
SW $20, -16($fp)
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
