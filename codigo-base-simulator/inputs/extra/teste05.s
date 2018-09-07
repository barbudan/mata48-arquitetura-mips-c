#Testando: NOR SLT SLTU MULT MFHI MFLO MTHI MTLO MULTU DIV DIVU

addiu $2, $zero, 0xa

	li $3, -458
	li $4, 458
	li $5, 296
	li $6, 896

	slt $7, $3, $4
	slt $8, $4, $3
	sltu $9, $3, $5
	sltu $10, $5, $3

	mult $3, $5
	mfhi $12 
	mflo $13

	multu $3, $5
	mfhi $14
	mflo $15

	mult $5 $6
	mfhi $24
	mflo $25

	li $5, 1545
	li $6, 9878

	multu $5, $6
	mfhi $26
	mflo $27
	
	div $16, $3, $4
	mfhi $17
	mflo $18

	divu $19, $3, $4
	mfhi $20
	mflo $21

	mthi $5
	mtlo $3	
	nor $22, $20, $21
	nor $23, $22, $3

syscall
