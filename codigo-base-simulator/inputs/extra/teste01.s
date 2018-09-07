#Testando SLIT ADDI ANDI XORI
addiu $v0, $zero, 0xa

	li $t0, -1
	slti $t1, $t0, 0
	addi $t2, $t0, 12
	addi $t3, $t0, -12

	li $t4, 3
	andi $t4, $t4, 0
	li $t5, 3
	xori $t5, $t5, 3

syscall