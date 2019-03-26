.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $10, $0, 4
ADDI $11, $0, 5
SUBU $9, $10, $11
SW $9, -8($fp)
ADDI $9, $0, 3
SW $9, -12($fp)
ADDI $10, $0, 2
SUBU $9, $0, $10
SW $9, -16($fp)
ADDI $9, $0, 0
SW $9, -20($fp)
LW $12, -8($fp)
nop
LW $13, -12($fp)
nop
ADDU $11, $12, $13
LW $12, -16($fp)
nop
ADDU $10, $11, $12
LW $11, -20($fp)
nop
ADDU $9, $10, $11
LW $10, -24($fp)
nop
ADDU $2, $9, $10
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
