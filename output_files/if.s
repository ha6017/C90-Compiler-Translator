func:
SW $31, 4 ($fp)
ADDI $9, $0, 1
BEQ $9, $0, L_2
nop
ADDI $2, $0, 0
L_2:
ADDI $2, $0, 69
LW $31, 4 ($fp)
nop
LW $fp, 0 ($fp)
nop
JR $31
nop
