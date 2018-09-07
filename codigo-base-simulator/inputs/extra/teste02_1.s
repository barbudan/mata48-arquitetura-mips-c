#Testando: SW LB LH LBU LHU

li $sp 0x7fffeffc #carregando o endereço no sp, pode ignorar essa instrução no mars
addiu $v0, $zero, 0xa
		
	li $t0 -5452

	sw $t0, 0($sp)
	lb $t1,	0($sp)
	lh $t2, 0($sp)
	lbu $t3, 0($sp)
	lhu $t4, 0($sp)
	
	li $t0 5452
	sw $t0, 4($sp)
	lb $s1,	4($sp)
	lh $s2, 4($sp)
	lbu $s3, 4($sp)
	lhu $s4, 4($sp)
	

syscall

#NOTA: No final da compilação, seu R1($at) deve ter 0x7fff0000. 
#Faz parte da instrução do li uma vez que 0x7fffeffc é um número muito grande.