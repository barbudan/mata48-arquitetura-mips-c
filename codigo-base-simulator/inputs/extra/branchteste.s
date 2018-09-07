addiu $v0, $0, 10
		addiu $t1, $zero, 40
		addiu $t0, $zero, 10
		addiu $t5, $zero, 50
		add $t2 $t1 $t0
		la $t4 l1
	l1:
		addiu $t0, $t0, 10
		beq $t0, $t5, end
		bne $t0, $t1, l1
		add $t3 $t1 $t0

		jalr $t4
	end:
syscall