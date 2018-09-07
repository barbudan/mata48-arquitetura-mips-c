addiu $2 $0 10
lui $3 0x1000
addiu $4 $0 0xABCDEF37
addiu $5 $0 0x55

sw $4 0($3)
lw $20 0($3)

sb $5 1($3)
lw $21 0($3)
lh $22 2($3)
lhu $23 2($3)

sw $4 0($3)
sh $5 2($3)
lw $24 0($3)
lh $25 2($3)
lhu $26 2($3)

syscall