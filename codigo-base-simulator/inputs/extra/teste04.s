.text
__start:	addiu $v0, $zero, 10 #Sets syscall
		addiu $t0, $zero, 5 #Says 5
		addi $t1, $t0, 300 #Says 300
		sub $t2, $t1, $t0 #Says 295
		subu $t2, $t2, $t0 #Says 290
		bne $t2, $t1, label_b #Jumps
label_a:
		j label_d
label_b:
		addiu $t3, $0, 128 #Says 128
		addiu $t4, $0, 128 #Says 128
		bne $t3, $t4, label_c #Doesn't jump
		beq $t3, $t4, label_a #Jumps
label_c:
		addiu $t8, $zero, 1
label_d:
		addiu $t0, $zero, 3 #Says 3
		addiu $t1, $zero, 2 #Says 2
		beq $t0, $t1, label_c #Doesn't jump
		and $t2, $t1, $t0 #Says 2
		or $t3, $t1, $t0 #Says 3
		xor $t4, $t1, $t0 #Says 1
		nor $t5, $t1, $t0 #Says fffffffc
		syscall #Exits