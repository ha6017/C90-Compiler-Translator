.text
.align 2
.globl arg
.ent arg
arg:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
SW $4, -8($fp)
SW $5, -12($fp)
SW $6, -16($fp)
SW $7, -20($fp)
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
SUBU $9, $10, $11
ADDI $10, $0, 20
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
.end arg
