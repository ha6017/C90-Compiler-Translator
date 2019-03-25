.text
.align 2
.globl func
.ent func
func:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $17, $0, 1
SW $17, -8 ($fp)
ADDI $17, $0, 0
SW $17, -12 ($fp)
LW $20, -8($fp)
nop
LW $24, -12($fp)
nop
SLT $17, $20, $24
ADDI $25, $0, 1
SLT $17, $17, $25
BEQ $17, $0, L_2
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
