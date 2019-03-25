.globl a
.data
.align 2
.size a, 12
a:
.word 6
.word 5
.word 4

.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
LUI $11, %hi(a)
ADDI $11, $11, %lo(a)
LW $10, 0($11)
nop
LUI $12, %hi(a)
ADDI $12, $12, %lo(a)
LW $11, 4($12)
nop
ADDU $9, $10, $11
LUI $11, %hi(a)
ADDI $11, $11, %lo(a)
LW $10, 8($11)
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
