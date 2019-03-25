.text
.align 2
.globl rand
.ent rand
rand:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $9, $0, 0
SW $9, -8 ($fp)
ADDI $9, $0, 1
LW $10, -8($fp)
nop
ADDU $10, $10, $9
ADDU $8, $0, $10
SW $10, -8($fp)
LW $2, -8($fp)
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
.end rand
