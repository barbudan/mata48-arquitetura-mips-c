	#funções do tipo j
	#Teste para trabalho de arquitetura
	
	
	j	a
e:	j	bc
g:	j	d
a:	jal	e
d:	add	$3, $ra, $0
	j	f
bc:	j 	g
f:	addiu	$2, $0, 10
	syscall