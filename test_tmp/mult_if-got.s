.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $9, $0, 1
SW $9, -8 ($fp)
ADDI $9, $0, 1
SW $9, -12 ($fp)
ADDI $9, $0, 1
SW $9, -16 ($fp)
ADDI $9, $0, 1
SW $9, -20 ($fp)
LW $10, -8($fp)
nop
ADDI $11, $0, 1
SLT $9, $10, $11
BEQ $9, $0, L_2
nop
LW $11, -12($fp)
nop
ADDI $12, $0, 1
ADDI $10, $0, 0
BNE $11, $12, L_4
nop
ADDI $10, $0, 1
L_4:
BEQ $10, $0, L_3
nop
LW $12, -16($fp)
nop
ADDI $13, $0, 1
ADDI $11, $0, 0
BNE $12, $13, L_6
nop
ADDI $11, $0, 1
L_6:
BEQ $11, $0, L_5
nop
LW $13, -20($fp)
nop
ADDI $14, $0, 1
ADDI $12, $0, 0
BEQ $13, $14, L_9
nop
ADDI $12, $0, 1
L_9:
BEQ $12, $0, L_7
nop
ADDI $2, $0, 0
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
J L_8
nop
L_7:
ADDI $2, $0, 1
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
L_8:
L_5:
L_3:
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
