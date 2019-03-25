.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $17, $0, 4
SW $17, -8 ($fp)
ADDI $17, $0, 2
SW $17, -12 ($fp)
LW $17, -8($fp)
nop
LW $20, -12($fp)
nop
DIV $17, $20
MFLO 
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
