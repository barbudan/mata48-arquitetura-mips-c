	#funções do tipo shamt
	#Teste para trabalho de arquitetura
	
	addiu	$3,$0, -20
	addiu	$4,$0, -1
	addiu 	$5, $0, 16
	addiu	$6,$0, 10
	addiu	$2, $0, 10
	
	sll	$8, $3,16
	sll	$9, $4,16
	srl	$10, $3,16
	srl	$11, $4,16
	sra	$12, $3,16
	sra	$13, $4,16
	
	srl	$14, $4,10
	sra	$15, $3,10
	syscall