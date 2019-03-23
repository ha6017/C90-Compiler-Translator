f:
SW $31, 4 ($fp)
ADDI $9, $0, 4
SW $9, 8 ($fp)
ADDI $9, $0, 0
SW $9, 12 ($fp)
LW $12, 12($fp)
nop
ADDI $9, $0, 1
BEQ $12, $0,L_3
nop
ADDI $9, $0, 0
L_3
BEQ $9, $0, L_2
nop
LW $16, 8($fp)
nop
ADDI $12, $0, 1
BEQ $16, $0,L_6
nop
ADDI $12, $0, 0
L_6
BEQ $12, $0, L_4
nop
ADDI $2, $0, 1
J L_5
nop
L_4:
ADDI $2, $0, 0
L_5:
L_2:
ADDI $2, $0, 20
LW $31, 4 ($fp)
nop
LW $fp, 0 ($fp)
nop
JR $31
nop
