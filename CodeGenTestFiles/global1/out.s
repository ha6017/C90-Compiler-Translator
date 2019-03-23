.globl a
.data
.align 2
a:
.word 10

.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
LUI $20, %hi(a)
ADDI $20, $20, %lo(a)
LW $17, 0($20)
nop
SW $17, -8 ($fp)
LW $2, -8($fp)
nop
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
.end f
