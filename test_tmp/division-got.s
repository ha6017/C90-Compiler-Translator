.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $9, $0, 4
SW $9, -8 ($fp)
ADDI $9, $0, 2
SW $9, -12 ($fp)
LW $9, -8($fp)
nop
LW $10, -12($fp)
nop
DIV $9, $10
MFLO $2
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
