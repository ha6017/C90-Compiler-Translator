.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $17, $0, 1
SW $17, -8 ($fp)
ADDI $17, $0, 1
SW $17, -12 ($fp)
ADDI $17, $0, 1
SW $17, -16 ($fp)
ADDI $17, $0, 1
SW $17, -20 ($fp)
LW $20, -8($fp)
nop
ADDI $24, $0, 1
SLT $17, $20, $24
BEQ $17, $0, L_2
nop
LW $24, -12($fp)
nop
ADDI $25, $0, 1
ADDI $20, $0, 0
BNE $24, $25, L_4
nop
ADDI $20, $0, 1
L_4:
BEQ $20, $0, L_3
nop
LW $25, -16($fp)
nop
