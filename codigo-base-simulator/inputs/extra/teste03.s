#Testando: SRL SLL SRA SLLV SRLV SRAV
addiu $v0, $zero, 0xa

	li $t0, 2005
	srl $t1, $t0, 3
	sll $t2, $t0, 3
	sra $t3, $t0, 3
	
	li $t1, 3
	sllv $t4, $t1, $t0
	srlv $t5, $t1, $t0
	srav $t6, $t1, $t0
	
	li $t0, -2005
	sllv $t7, $t1, $t0
	srlv $s0, $t1, $t0
	srav $s1, $t1, $t0
	
	srl $s2, $t0, 3
	sll $s3, $t0, 3
	sra $s4, $t0, 3	
	
syscall