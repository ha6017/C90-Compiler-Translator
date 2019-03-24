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
LW $24, -20($fp)
nop
LW $25, -16($fp)
nop
ADDU $20, $24, $25
LW $24, -12($fp)
nop
ADDU $17, $20, $24
LW $20, -8($fp)
nop
ADDU $2, $17, $20
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
