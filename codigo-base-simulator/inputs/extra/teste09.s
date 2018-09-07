addiu $2 $0 10
lui $3 0x1000
addiu $4 $0 0xABCDEF37
addiu $5 $0 0x55
li $6 3

sub $10 $5 $4
subu $11 $5 $4

sra $12 $4 3
srav $13 $4 $6
srl $14 $4 3
srlv $15 $4 $6

slt $17 $4 $5
sltu $18 $4 $5
slti $19 $4 0x55
sltiu $20 $4 0x55

andi $22 $4 0xAF763EBA
andi $23 $4 0x55

syscall