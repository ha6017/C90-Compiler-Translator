.text
.align 2
.globl func
.ent func
func:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $17, $0, 1
BEQ $17, $0, L_2
nop
ADDI $2, $0, 0
L_2:
ADDI $2, $0, 69
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
.end func
