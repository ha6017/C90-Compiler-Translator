.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($fp)
SW $31, -4 ($fp)
ADDI $2, $0, 10
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
JR $31
nop
.end f
