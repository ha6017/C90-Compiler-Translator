.text
.align 2
.globl f
.ent f
f:
SW $fp, 0 ($sp)
SW $31, -4 ($sp)
ADDI $fp, $sp,  0
SW $0, 4294967288($fp)
nop
SW $0, 4294967284($fp)
nop
SW $0, 4294967280($fp)
nop
SW $0, 4294967276($fp)
nop
SW $0, 4294967272($fp)
nop
ADDI $9, $0, 69
ADDU $8, $0, $9
SW $8, -16($fp)
LW $2, -16($fp)
nop
LW $31, -4 ($fp)
nop
LW $fp, 0 ($fp)
nop
ADDI $sp, $fp,  0
JR $31
nop
.end f
