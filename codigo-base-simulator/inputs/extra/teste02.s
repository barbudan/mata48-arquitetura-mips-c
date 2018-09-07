#Testando: SW LB LH LBU LHU

addiu $v0, $zero, 0xa
	
	li $t0 -5452

	li $s0, 0x7fffeffc #apenas para testar acesso por imediatos, esse é o endereço original de SP
	sw $t0, 0($s0)
	lb $t1,	0($s0)
	lh $t2, 0($s0)
	
	li $t0 5452
	sw $t0, 0($s0)
	lbu $t3, 0($s0)
	lhu $t4, 0($s0)

syscall