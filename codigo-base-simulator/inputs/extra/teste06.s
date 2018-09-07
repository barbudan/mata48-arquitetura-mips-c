#Melhor prevenir do que codar errado


main:
        li $sp 0x7fffeffc
        lui    $3, 0x1000

        addiu  $5, $zero, 0xcafe
        addiu  $6, $zero, 0xfeca
        addiu  $7, $zero, 0xbeef
        addiu  $8, $zero, 0xefbe
        sb     $5, 0($3)
        sb     $6, 1($3)
        sb     $7, 6($3)
        sb     $8, 7($3)

        lbu     $9,  0($3)
        lbu     $10, 1($3)
        lb      $11, 6($3)
        lb      $12, 7($3)

        addiu  $3, $3, 4
        sh     $5, 0($3)
        sh     $6, 2($3)
        sh     $7, 4($3)
        sh     $8, 6($3)

        lhu     $13,  0($3)
        lhu     $14,  2($3)
        lh     $15,  4($3)
        lh     $16,  6($3)
        addiu $v0, $zero, 0xa
        addiu $3, $zero, 1
        addiu $4, $zero, -1
        addiu $5, $zero, 0x1234

        j l_1
l_0:
        addu $5, $5, $ra
        beq   $zero, $zero, l_2
l_1:
        addiu $5, $5, 7
        jal l_0
        j l_8
l_2:    
        addiu $5, $5, 9
        slt $7, $3, $4
        slt $8, $4, $3
        sltu $9, $3, $5
        sltu $10, $5, $3
        bne $3, $4, l_4
l_3:
        addiu $5, $5, 5
        multu $3, $5
        mfhi $14
        mflo $15

        mult $5 $6
        mfhi $24
        mflo $25
        bgez $zero, l_6
l_4:
        addiu $5, $5, 11
        blez  $3, l_3
l_5:
        addiu $5, $5, 99
        addiu   $7, $6, 9999
        subu    $8, $7, $2
        xor     $9, $4, $3
        xori    $10, $2, 255
        srl     $11, $6, 5
        sra     $12, $6, 4
        and     $13, $11, $5
        andi    $14, $4, 100
        sub     $15, $zero, $10
        bgtz  $3, l_3
l_6:
        addiu $5, $5, 111
        jr $ra
l_7:
        addiu $5, $5, 200
        addiu $10, $10, 0xf00
        ori $0, $0, 0
        ori $0, $0, 0
        addiu $5, $zero, 100        
        syscall
l_8:    
        addiu $5, $5, 215
        li $t0 -5452

        sw $t0, 0($sp)
        lb $t1, 0($sp)
        lh $t2, 0($sp)
        lbu $t3, 0($sp)
        lhu $t4, 0($sp)
        jal l_10
l_9:
        addiu $5, $5, 1
        syscall        
l_10:    
        addu $5, $5, $6
        li $t0 5452
        sw $t0, 4($sp)
        lb $s1, 4($sp)
        lh $s2, 4($sp)
        lbu $s3, 4($sp)
        lhu $s4, 4($sp)
        bltzal $4, l_12
l_11:
        addiu $5, $5, 400
        li $t0, -2005
        sllv $t7, $t1, $t0
        srlv $s0, $t1, $t0
        srav $s1, $t1, $t0
        syscall
l_12:    
        addu $5, $5, $6
        li $t1, 3
        sllv $t4, $t1, $t0
        srlv $t5, $t1, $t0
        srav $t6, $t1, $t0
        bgezal $4, l_11
        
l_13:    
        or      $4, $3, $2
        add     $5, $zero, 1234
        sll     $6, $5, 16
        addiu $5, $5, 0xbeb0063d
        syscall