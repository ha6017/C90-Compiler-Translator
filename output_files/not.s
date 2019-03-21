f:
SW $31, 4 ($fp)
ADDI $9, $0, 4
SW $9, 8 ($fp)
ADDI $9, $0, 0
SW $9, 12 ($fp)
LW $9, 12($fp)
nop
BEQ $9, $0, L_2
nop
LW $12, 8($fp)
nop
BEQ $12, $0, L_3
nop
ADDI $2, $0, 1
J L_4
nop
L_3:
ADDI $2, $0, 0
L_4:
L_2:
ADDI $2, $0, 20
LW $31, 4 ($fp)
nop
LW $fp, 0 ($fp)
nop
JR $31
nop
