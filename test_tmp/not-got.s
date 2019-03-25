.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $9, $0, 4
SW $9, -8 ($fp)
ADDI $9, $0, 0
SW $9, -12 ($fp)
LW $10, -12($fp)
nop
ADDI $9, $0, 1
BEQ $10, $0,L_3
nop
ADDI $9, $0, 0
L_3:
BEQ $9, $0, L_2
nop
LW $11, -8($fp)
nop
ADDI $10, $0, 1
BEQ $11, $0,L_6
nop
ADDI $10, $0, 0
L_6:
BEQ $10, $0, L_4
nop
ADDI $2, $0, 1
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
ADDI $2, $0, 20
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
L_5:
L_2:
ADDI $2, $0, 10
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
