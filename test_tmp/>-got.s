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
ADDI $17, $0, 0
SW $17, -16 ($fp)
ADDI $17, $0, 4
SW $17, -20 ($fp)
LW $20, -12($fp)
nop
LW $24, -8($fp)
nop
SLT $17, $24, $20
BEQ $17, $0, L_2
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
