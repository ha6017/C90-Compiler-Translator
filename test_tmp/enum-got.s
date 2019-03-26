.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $9, $0, 1
SW $9, -8 ($fp)
ADDI $9, $0, 3
SW $9, -12 ($fp)
ADDI $9, $0, 4
SW $9, -16 ($fp)
ADDI $9, $0, -2
SW $9, -20 ($fp)
LW $2, -16($fp)
nop
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
