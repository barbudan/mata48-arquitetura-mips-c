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
		beq $t3, $t4, label_d #Jumps
label_c:
		addiu $t8, $zero, 1 #Won't be run
label_d:
		addiu $t0, $zero, 3 #Says 3
		addiu $t1, $zero, 2 #Says 2
		beq $t0, $t1, label_c #Doesn't jump
		and $t2, $t1, $t0 #Says 2
		or $t3, $t1, $t0 #Says 3
		xor $t4, $t1, $t0 #Says 1
		nor $t5, $t1, $t0 #Says fffffffc
		slt $t6, $t0, $t1 #Says 0
		slt $t7, $t1, $t0 #Says 1
		addi $t7, $zero, -7 #Says fffffff9
		slti $t2, $zero, -7 #Says 0
		add $t0, $zero, $zero #Says 0
		j label_f
label_e:
		j label_h
label_f:
		jal label_e
label_g:
		addi $t0, $t0, 1 #increments t0
		jr $ra #Points to line "bltz $zero, label_i" in the end
label_h:
		bltzal $t7, label_g #Jumps 
		bltzal $zero, label_g #Doesn't jump
		bltzal $t3, label_g #Doesn't jump
		bgezal $t7, label_g #Doesn't jump
		bgezal $zero, label_g #Jumps 
		bgezal $t3, label_g #Jumps
		bltz $zero, label_i #Doesn't jump
		bltz $t3, label_i #Doesn't jump
		#t0 = 3 so far
		bltz $t7, label_i #Jumps 
		j label_j #Won't be run
label_i:
		addi $t0, $t0, 1 #increments t0
		#t0 = 4 so far
label_j:
		bgez $t7, label_k #Doesn't jump
		bgez $t3, label_k #Jumps
		j label_l #Won't be run
label_k:
		addi $t0, $t0, 1 #increments t0
		#t0 = 5 so far
label_l:
		blez $t3, label_m #Doesn't jump
		blez $t7, label_m #Jumps
		j label_n #Won't be run
label_m:
		addi $t0, $t0, 1 #increments t0
		#t0 = 6 so far
label_n:
		bgtz $t7, label_o #Doesn't jump
		bgtz $t3, label_o #Jumps
		j label_p #Won't be run
label_o:
		addi $t0, $t0, 1 #increments t0
		#t0 = 7 at the end
label_p:
		syscall #Exits

		#Comments aside codes are the expected outcome