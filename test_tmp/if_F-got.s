.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $9, $0, 100
SW $9, -8 ($fp)
LW $10, -8($fp)
nop
ADDI $11, $0, 100
ADDI $9, $0, 0
BEQ $10, $11, L_3
nop
ADDI $9, $0, 1
L_3:
BEQ $9, $0, L_2
nop
ADDI $2, $0, 2
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
L_2:
ADDI $2, $0, 0
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
