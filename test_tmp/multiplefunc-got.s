.text
.align 2
.globl subtract
.ent subtract
subtract:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
SW $4, -8($fp)
SW $5, -12($fp)
LW $9, -8($fp)
nop
LW $10, -12($fp)
nop
SUBU $2, $9, $10
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
.end subtract

.text
.align 2
.globl func
.ent func
func:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $4, $0, 10
ADDI $5, $0, 5
ADDI $sp, $fp, -8
JAL subtract
nop
ADDU $9, $2, $0
SW $9, -8 ($fp)
LW $10, -8($fp)
nop
ADDI $11, $0, 5
ADDI $9, $0, 0
BNE $10, $11, L_6
nop
ADDI $9, $0, 1
L_6:
BEQ $9, $0, L_4
nop
ADDI $2, $0, 0
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
ADDI $2, $0, 10
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
L_5:
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
.end func
