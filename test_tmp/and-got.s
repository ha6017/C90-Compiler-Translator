.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $11, $0, 1
ADDI $12, $0, 1
ADDU $10, $11, $12
ADDI $12, $0, 0
ADDI $13, $0, 12
ADDU $11, $12, $13
ADDI $9, $0, 1
BEQ $10, $0,L_2
nop
BEQ $11, $0,L_2
nop
J L_3
nop
L_2:
ADDI $9, $0, 0
L_3:
SW $9, -8 ($fp)
LW $10, -8($fp)
nop
ADDI $11, $0, 1
ADDI $9, $0, 0
BNE $10, $11, L_6
nop
ADDI $9, $0, 1
L_6:
BEQ $9, $0, L_4
nop
ADDI $2, $0, 0
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
J L_5
nop
L_4:
ADDI $2, $0, 10
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
L_5:
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
.end f
