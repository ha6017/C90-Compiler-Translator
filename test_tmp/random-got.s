.text
.align 2
.globl rand
.ent rand
rand:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
ADDI $17, $0, 0
SW $17, -8 ($fp)
ADDI $17, $0, 1
LW $20, -8($fp)
nop
ADDU $20, $20, $17
ADDU $16, $0, $20
SW $20, -8($fp)
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
