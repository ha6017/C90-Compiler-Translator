.text
.align 2
.globl func
.ent func
func:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $9, $0, 1
SW $9, -8 ($fp)
ADDI $9, $0, 0
SW $9, -12 ($fp)
LW $10, -8($fp)
nop
LW $11, -12($fp)
nop
SLT $9, $10, $11
ADDI $12, $0, 1
SLT $9, $9, $12
BEQ $9, $0, L_2
nop
ADDI $2, $0, 5
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
ADDI $2, $0, 10
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
L_3:
ADDI $2, $0, 20
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
.end func
