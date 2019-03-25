.globl globArray
.data
.align 2
.size globArray, 12
globArray:
.word 15
.word 2
.word 5

.text
.align 2
.globl recursive
.ent recursive
recursive:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
SW $4, -8($fp)
SW $5, -12($fp)
SW $6, -16($fp)
SW $7, -20($fp)
LW $10, -8($fp)
nop
LW $11, -12($fp)
nop
SLT $9, $10, $11
ADDI $12, $0, 1
SLT $9, $9, $12
BEQ $9, $0, L_2
nop
LW $10, -12($fp)
nop
ADDU $8, $0, $10
ADDI $10, $10, 1
SW $10, -12($fp)
LW $10, -20($fp)
nop
ADDU $8, $0, $10
ADDIU $10, $10, -1
SW $10, -20($fp)
LW $11, -20($fp)
nop
ADDI $12, $0, 800
ADDU $10, $11, $12
LW $11, -16($fp)
nop
DIV $11, $10
MFLO $11
ADDU $8, $0, $11
SW $11, -16($fp)
LW $4, -8($fp)
nop
LW $5, -12($fp)
nop
LW $6, -16($fp)
nop
LW $7, -20($fp)
nop
ADDI $sp, $fp, -24
JAL recursive
nop
ADDU $2, $2, $0
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
LW $2, -12($fp)
nop
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
.end recursive

.text
.align 2
.globl func
.ent func
func:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $9, $0, 17
SW $9, -8 ($fp)
ADDI $4, $0, 10
ADDI $5, $0, 5
LW $6, -8($fp)
nop
ADDI $10, $0, 20
SUBU $7, $0, $10
ADDI $sp, $fp, -12
JAL recursive
nop
ADDU $9, $2, $0
SW $9, -12 ($fp)
LUI $10, %hi(globArray)
ADDI $10, $10, %lo(globArray)
LW $9, 4($10)
nop
LW $10, -12($fp)
nop
SUBU $10, $10, $9
ADDU $8, $0, $10
SW $10, -12($fp)
ADDI $9, $0, 1
SW $9, -16 ($fp)
ADDI $9, $0, 1
SW $9, -20 ($fp)

top_1_0:
LW $10, -20($fp)
nop
ADDI $11, $0, 10
SLT $9, $10, $11
BEQ $9, $0, bottom_1_0
nop
LW $10, -20($fp)
nop
LW $11, -16($fp)
nop
MUL $8, $11, $10
SW $8, -16($fp)
LW $11, -20($fp)
nop
ADDI $12, $0, 5
ADDI $10, $0, 0
BNE $11, $12, L_7
nop
ADDI $10, $0, 1
L_7:
BEQ $10, $0, L_6
nop
J bottom_1_0
nop
L_6:
LW $10, -20($fp)
nop
ADDU $8, $0, $10
ADDI $10, $10, 1
SW $10, -20($fp)
J top_1_0
nop

bottom_1_0:
LW $10, -12($fp)
nop
LW $11, -16($fp)
nop
ADDU $9, $10, $11
ADDU $8, $0, $9
SW $8, -12($fp)
LW $10, -12($fp)
nop
ADDI $11, $0, 129
ADDI $9, $0, 0
BNE $10, $11, L_10
nop
ADDI $9, $0, 1
L_10:
BEQ $9, $0, L_8
nop
ADDI $2, $0, 0
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
J L_9
nop
L_8:
ADDI $2, $0, 10
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
L_9:
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
.end func
