.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $9, $0, 3
SW $9, -8 ($fp)
ADDI $9, $0, 5
SW $9, -12 ($fp)
LW $10, -8($fp)
nop
LW $11, -12($fp)
nop
ADDU $9, $10, $11
ADDU $8, $0, $9
SW $8, -8($fp)
LW $10, -8($fp)
nop
ADDI $11, $0, 8
ADDI $9, $0, 0
BNE $10, $11, L_4
nop
ADDI $9, $0, 1
L_4:
BEQ $9, $0, L_2
nop
ADDI $2, $0, 0
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
J L_3
nop
L_2:
ADDI $2, $0, 20
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
L_3:
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
.end f
