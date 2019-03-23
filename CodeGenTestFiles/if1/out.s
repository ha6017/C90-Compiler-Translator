.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $17, $0, 12
SW $17, -8 ($fp)
LW $20, -8($fp)
nop
ADDI $24, $0, 12
ADDI $17, $0, 0
BNE $20, $24, L_3
nop
ADDI $17, $0, 1
L_3:
BEQ $17, $0, L_2
nop
ADDI $20, $0, 69
ADDU $16, $0, $20
SW $16, -8($fp)
L_2:
LW $2, -8($fp)
nop
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
.end f
