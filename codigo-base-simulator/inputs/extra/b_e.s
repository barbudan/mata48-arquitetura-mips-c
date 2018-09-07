	#funções do tipo branch especial
	#Teste para trabalho de arquitetura
	
	addiu	$3,$0, -20
	addiu	$4,$0, -1
	addiu 	$5, $0, 16
	addiu	$6,$0, 10
	addiu	$2, $0, 10
	
	bltz	$4,b2
	
	 
b2:
	addiu	$8, $0, 1
	bgez, $0, b3
	
b3:
	bltzal	$5, b2
	j	b4
	jr $ra
	syscall
	
b4:
	addiu	$9, $0, 1
	bgezal	$0, b5
	
b5:	
	addiu	$10, $0, -1
b6:
	addiu	$11, $0, 1
	bgez, $4, b9
	
b7:
	bltzal	$0, b7
	j	b9
	jr $ra
	syscall
	
b8:
	addiu	$12, $0, 1
	bgezal	$0, b9
	
b9:	
	addiu	$10, $0, 1
	syscall
	
	
	 
	   