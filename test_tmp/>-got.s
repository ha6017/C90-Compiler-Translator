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
ADDI $9, $0, 0
SW $9, -16 ($fp)
ADDI $9, $0, 4
SW $9, -20 ($fp)
LW $10, -12($fp)
nop
LW $11, -8($fp)
nop
SLT $9, $11, $10
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
.end func
