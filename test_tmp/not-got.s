.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $17, $0, 4
SW $17, -8 ($fp)
ADDI $17, $0, 0
SW $17, -12 ($fp)
LW $20, -12($fp)
nop
ADDI $17, $0, 1
BEQ $20, $0,L_4
nop
ADDI $17, $0, 0
L_4
BEQ $17, $0, L_2
nop
LW $20, -8($fp)
nop
BEQ $20, $0, L_5
nop
ADDI $2, $0, 1
J L_6
nop
L_5:
ADDI $2, $0, 20
L_6:
J L_3
nop
L_2:
ADDI $2, $0, 10
L_3:
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
.end f
