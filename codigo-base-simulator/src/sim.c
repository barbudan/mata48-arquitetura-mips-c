//////////////////////// 2017.2 - MATA48 - ARQUITETURA DE COMPUTADORES ////////////////////////////////////////////
/////////////////////////////ALUNO: DANILO DE ANDRADE PELETEIRO ///////////////////////////////////////////////////

#include <stdio.h>
#include "shell.h"

void process_instruction()
{
    /* execute one instruction here. You should use CURRENT_STATE and modify
     * values in NEXT_STATE. You can call mem_read_32() and mem_write_32() to
     * access memory. */

	uint32_t opcode,func,rs,rt,rd,target,PCHighOrder,auxlb_u32;
	int32_t auxlb_32;

	int64_t auxmd_64;
	uint64_t auxmd_u64;

	uint8_t auxlb_u8;
	uint16_t auxlb_u16;
	int8_t auxlb_8;
	int16_t sa, auxlb_16;
	
	uint16_t immediate_u16;
	int16_t immediate_16;

	uint32_t immediate_u32;
	int32_t immediate_32;

	uint32_t memoria = mem_read_32(CURRENT_STATE.PC);

	opcode = memoria & 0xFC000000; // Operador.
	opcode = opcode >> 26; // Excluindo os bits desnecessários.
	
	if(opcode == 0) // R FORMAT
	{
		
		rs = memoria & 0x03E00000; // Pegando somente os 5 bits referentes ao RS.
		rs = rs >> 21;
		rt = memoria & 0x001F0000; // Pegando somente os 5 bits referentes ao RT.
		rt = rt >> 16;
		rd = memoria & 0x0000F800; // Pegando somente os 5 bits referentes ao RD.
		rd = rd >> 11;
		sa = memoria & 0x000007C0; // Pegando somente os 5 bits referentes ao SHAMT.
		sa = sa >> 6;
		func = memoria & 0x0000003F;
		int x=1;
		switch(func)
		{
			case 0x20: // ADD - Add
				NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rs] + CURRENT_STATE.REGS[rt];
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x21: // ADDU - Add Unsigned
				NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rs] + CURRENT_STATE.REGS[rt];
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x24: // AND - Bitwise AND
				NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rs] & CURRENT_STATE.REGS[rt];
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x1A: // DIV - Divide
				auxmd_64 = (int64_t)(int32_t)CURRENT_STATE.REGS[rs] % (int64_t)(int32_t)CURRENT_STATE.REGS[rt];
				auxmd_64 = auxmd_64 & 0xFFFFFFFF00000000;
				auxmd_64 = (uint64_t)auxmd_64 >> 32;
				NEXT_STATE.HI = auxmd_64;
				auxmd_64 = (int64_t)(int32_t)CURRENT_STATE.REGS[rs] / (int64_t)(int32_t)CURRENT_STATE.REGS[rt];
				NEXT_STATE.LO = auxmd_64 & 0x00000000FFFFFFFF;
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x1B: // DIVU - Unsigned Divide
				auxmd_u64 = (uint64_t)CURRENT_STATE.REGS[rs] % (uint64_t)CURRENT_STATE.REGS[rt];
				NEXT_STATE.HI = (uint32_t)auxmd_u64;
				auxmd_u64 = (uint64_t)CURRENT_STATE.REGS[rs] / (uint64_t)CURRENT_STATE.REGS[rt];
				NEXT_STATE.LO = (uint32_t)auxmd_u64;
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x08: // JR - Jump to Adress in Register
				NEXT_STATE.PC = CURRENT_STATE.REGS[31];
				break;

			case 0x09: // JALR - Jump and Link Register
				NEXT_STATE.PC = CURRENT_STATE.REGS[rs];
				NEXT_STATE.REGS[rd] = CURRENT_STATE.PC+4;
				break;

			case 0x10: // MFHI - Move from HI Register
				NEXT_STATE.REGS[rd] = CURRENT_STATE.HI;
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x12: // MFLO - Move from LO Register
				NEXT_STATE.REGS[rd] = CURRENT_STATE.LO;
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x18: // MULT - Multiply
				auxmd_64 = (int64_t)(int32_t)CURRENT_STATE.REGS[rs] * (int64_t)(int32_t)CURRENT_STATE.REGS[rt];
				auxmd_64 = auxmd_64 & 0xFFFFFFFF00000000;
				auxmd_64 = (uint64_t)auxmd_64 >> 32;
				NEXT_STATE.HI = auxmd_64;
				auxmd_64 = (int64_t)(int32_t)CURRENT_STATE.REGS[rs] * (int64_t)(int32_t)CURRENT_STATE.REGS[rt];
				NEXT_STATE.LO = auxmd_64 & 0x00000000FFFFFFFF;
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x19: // MULTU - Unsigned Multiply
				auxmd_u64 = (uint64_t)CURRENT_STATE.REGS[rs] * (uint64_t)CURRENT_STATE.REGS[rt];
				auxmd_u64 = auxmd_u64 & 0xFFFFFFFF00000000;
				auxmd_u64 = auxmd_u64 >> 32;
				NEXT_STATE.HI = auxmd_u64;
				auxmd_u64 = (uint64_t)CURRENT_STATE.REGS[rs] * (uint64_t)CURRENT_STATE.REGS[rt];
				NEXT_STATE.LO = auxmd_u64 & 0x00000000FFFFFFFF;
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x27: // NOR - Bitwise NOR (NOT-OR)
				NEXT_STATE.REGS[rd] = ~(CURRENT_STATE.REGS[rs] | CURRENT_STATE.REGS[rt]);
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x26: // XOR - Bitwise XOR (Exclusive-OR)
				NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rs] ^ CURRENT_STATE.REGS[rt];
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x25: // OR - Bitwise OR
				NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rs] | CURRENT_STATE.REGS[rt];
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x2A: // SLT - Set to 1 if Less Than
				if((int32_t)CURRENT_STATE.REGS[rs] < (int32_t)CURRENT_STATE.REGS[rt])
					NEXT_STATE.REGS[rd] = 1;
				else
					NEXT_STATE.REGS[rd] = 0;
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x2B: // SLTU - Set to 1 if Less Than Unsigned
				if(CURRENT_STATE.REGS[rs] < CURRENT_STATE.REGS[rt])
					NEXT_STATE.REGS[rd] = 1;
				else
					NEXT_STATE.REGS[rd] = 0;
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x00: // SLL - Logical Shift Left
				NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rt] << sa;
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x02: // SRL - Logical Shift Right
				NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rt] >> sa;
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x03: // SRA - Arithmetic Shift Right
				NEXT_STATE.REGS[rd] = (int32_t)CURRENT_STATE.REGS[rt] >> sa;
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x22: // SUB - Substract
				NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rs] - CURRENT_STATE.REGS[rt];
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x23: // SUBU - Unsigned Substract
				NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rs] - CURRENT_STATE.REGS[rt];
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x04: // SLLV - Shift Left Logical Variable
				NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rt] << (CURRENT_STATE.REGS[rs] & 0x0000001F);
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;	

			case 0x06: // SRLV - Shift Right Logical Variable
				NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rt] >> (CURRENT_STATE.REGS[rs] & 0x0000001F);
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x07: // SRAV - Shift Right Arithmetic Variable
				NEXT_STATE.REGS[rd] = (int32_t)CURRENT_STATE.REGS[rt] >> (CURRENT_STATE.REGS[rs] & 0x0000001F);
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x11: // MTHI - Move to HI
				NEXT_STATE.HI = CURRENT_STATE.REGS[rs];
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x13: // MTLO - Move to LO
				NEXT_STATE.LO = CURRENT_STATE.REGS[rs];
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

			case 0x0c: // SYSCALL
				if(NEXT_STATE.REGS[2]==10)
					RUN_BIT = 0;
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
				break;

		}


	}
	else if(opcode == 2) // J - Jump [J-FORMAT] // FUNCIONANDO
	{
		target = memoria & 0x03FFFFFF;
		target = target << 2;
		PCHighOrder = CURRENT_STATE.PC & 0xF0000000;
		NEXT_STATE.PC = PCHighOrder | target;
	}
	else if(opcode == 3) // JAL- Jump and Link [J-FORMAT]
	{
		target = memoria & 0x03FFFFFF;
		target = target << 2;
		PCHighOrder = CURRENT_STATE.PC & 0xF0000000;
		NEXT_STATE.PC = PCHighOrder | target;
		NEXT_STATE.REGS[31] = CURRENT_STATE.PC + 4;

	}
	else // I FORMAT
	{
		
		rs = memoria & 0x03E00000; // Pegando somente os 5 bits referentes ao RS.
		rs = rs >> 21;
		rt = memoria & 0x001F0000; // Pegando somente os 5 bits referentes ao RT.
		rt = rt >> 16;
		
		immediate_16 = memoria & 0x0000FFFF; // 16 bits
		immediate_u16 = memoria & 0x0000FFFF; // 16 bits s/ sinal
		immediate_32 = memoria & 0x0000FFFF; // 32 bits
		immediate_u32 = memoria & 0x0000FFFF; // 32 bits s/ sinal
		switch(opcode)
		{
			
			case 9: // ADDIU - Add Immediate Unsigned
			NEXT_STATE.REGS[rt] = CURRENT_STATE.REGS[rs] + immediate_16;
			NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 13: // ORI - Or Immediate
			NEXT_STATE.REGS[rt] = CURRENT_STATE.REGS[rs] | immediate_u32;
			NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 4: // BEQ - Branc If Equal
			if((int32_t)CURRENT_STATE.REGS[rs] == (int32_t)CURRENT_STATE.REGS[rt])
			{
				NEXT_STATE.PC = (CURRENT_STATE.PC) + (immediate_16 << 2);
				NEXT_STATE.PC = NEXT_STATE.PC+4;
			}
			else
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 5: // BNE - Branch If Not Equal
			if((int32_t)CURRENT_STATE.REGS[rs] != (int32_t)CURRENT_STATE.REGS[rt])
			{
				NEXT_STATE.PC = (CURRENT_STATE.PC) + (immediate_16 << 2);
				NEXT_STATE.PC = NEXT_STATE.PC+4;
			}
			else
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 12: // ANDI - And Immediate
			NEXT_STATE.REGS[rt] = CURRENT_STATE.REGS[rs] & immediate_u16;
			NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 14: // XORI - Exclusive Or Immediate
			NEXT_STATE.REGS[rt] = CURRENT_STATE.REGS[rs] ^ immediate_u16;
			NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 15: // LUI - Load Upper Immediate
			immediate_u32 = immediate_u32 << 16;
			NEXT_STATE.REGS[rt] = immediate_u32;
			NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 8: // ADDI - Add Immediate
			NEXT_STATE.REGS[rt] = CURRENT_STATE.REGS[rs] + immediate_16;
			NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 10: // SLTI - Set On if Less than Immediate
			if((int32_t)CURRENT_STATE.REGS[rs] < immediate_16)
				NEXT_STATE.REGS[rt] = 1;
			else
				NEXT_STATE.REGS[rt] = 0;
			NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 11: // SLTI - Set On if Less than Immediate Unsigned
			if(CURRENT_STATE.REGS[rs] < immediate_u16)
				NEXT_STATE.REGS[rt] = 1;
			else
				NEXT_STATE.REGS[rt] = 0;
			NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 1:
			if(rt == 0) // BLTZ - Branch on Less Than Zero
			{
				if((int32_t)CURRENT_STATE.REGS[rs] < 0)
				{	
					NEXT_STATE.PC = (CURRENT_STATE.PC) + (immediate_16 << 2);
					NEXT_STATE.PC = NEXT_STATE.PC+4;
				}
				else
					NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			}
			else if(rt == 1) // BGEZ - Branch on Greater Than or Equal to Zero
			{
				if((int32_t)CURRENT_STATE.REGS[rs] >= 0)
				{
					NEXT_STATE.PC = (CURRENT_STATE.PC) + (immediate_16 << 2);
					NEXT_STATE.PC = NEXT_STATE.PC+4;
				}
				else
					NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			}
			else if(rt == 16) // BLTZAL - Branch on Less Than Zero And Link
			{
				NEXT_STATE.REGS[31] = CURRENT_STATE.PC+4; // Assim é o correto(via def.), porém, no MARS, teria que estar dentro do IF
				if((int32_t)CURRENT_STATE.REGS[rs] < 0)
				{
					NEXT_STATE.PC = (CURRENT_STATE.PC) + (immediate_16 << 2);
					NEXT_STATE.PC = NEXT_STATE.PC+4;
				}
				else
					NEXT_STATE.PC = CURRENT_STATE.PC + 4;
					
			}
			else if(rt == 17) // BGEZAL - Branch on Greater Than or Equal to Zero And Link
			{
				NEXT_STATE.REGS[31] = CURRENT_STATE.PC+4; // Assim é o correto(via def.), porém, no MARS, teria que estar dentro do IF
				if((int32_t)CURRENT_STATE.REGS[rs] >= 0)
				{
					NEXT_STATE.PC = (CURRENT_STATE.PC) + (immediate_16 << 2);
					NEXT_STATE.PC = NEXT_STATE.PC+4;
				}
				else
					NEXT_STATE.PC = CURRENT_STATE.PC+4;

			}
			break;

			case 6: // BLEZ - Branch on Less Than or Equal to Zero
			if((int32_t)CURRENT_STATE.REGS[rs] <= 0)
			{	
				NEXT_STATE.PC = (CURRENT_STATE.PC) + (immediate_16 << 2);
				NEXT_STATE.PC = NEXT_STATE.PC+4;
			}
			else
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 7: // BGTZ - Branch on Greater Than Zero
			if((int32_t)CURRENT_STATE.REGS[rs] > 0)
			{
				NEXT_STATE.PC = (CURRENT_STATE.PC) + (immediate_16 << 2);
				NEXT_STATE.PC = NEXT_STATE.PC+4;
			}
			else
				NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 35: // LW - Load Word
			NEXT_STATE.REGS[rt] = mem_read_32( (CURRENT_STATE.REGS[rs]) + immediate_16 );
			NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 43: // SW - Store Word
			mem_write_32( (CURRENT_STATE.REGS[rs])+immediate_16, CURRENT_STATE.REGS[rt]);
			NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 40: // SB - Store Byte
			auxlb_u8 = CURRENT_STATE.REGS[rt] & 0x000000FF;
			auxlb_u32 = mem_read_32(CURRENT_STATE.REGS[rs] + immediate_16);
			auxlb_u32 = auxlb_u32 & 0xFFFFFF00;
			auxlb_u32 = auxlb_u32 | auxlb_u8;
			mem_write_32( CURRENT_STATE.REGS[rs] + immediate_16, auxlb_u32);
			NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 32: // LB - Load Byte
			auxlb_u32 = mem_read_32( (CURRENT_STATE.REGS[rs]) + immediate_16 );
			auxlb_8 = auxlb_u32 & 0x000000FF;
			NEXT_STATE.REGS[rt] = (NEXT_STATE.REGS[rt] & 0xFFFFFF00) | auxlb_8;
			NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 36: // LBU - Load Byte Unsigned
			auxlb_u32 = mem_read_32( (CURRENT_STATE.REGS[rs]) + immediate_16 );
			auxlb_u8 = auxlb_u32 & 0x000000FF;
			NEXT_STATE.REGS[rt] = (NEXT_STATE.REGS[rt] & 0x00000000) | auxlb_u8;
			NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

			case 41: // SH - Store Halfword
			auxlb_u16 = CURRENT_STATE.REGS[rt] & 0x0000FFFF;
			auxlb_u32 = mem_read_32(CURRENT_STATE.REGS[rs] + immediate_16);
			auxlb_u32 = auxlb_u32 & 0xFFFF0000;
			auxlb_u32 = auxlb_u32 | auxlb_u16;
			mem_write_32( (CURRENT_STATE.REGS[rs]) + immediate_16, (auxlb_u32) );
			NEXT_STATE.PC = CURRENT_STATE.PC + 4;

			case 37: // LHU - Load Halfword Unsigned
			auxlb_u32 = mem_read_32( (CURRENT_STATE.REGS[rs]) + immediate_16 );
			auxlb_u32 = auxlb_u32 & 0x0000FFFF;
			NEXT_STATE.REGS[rt] = (CURRENT_STATE.REGS[rt] & 0xFFFF0000) | auxlb_u32;
			NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;
			
			case 33: // LH - Load Halfword
			auxlb_u32 = mem_read_32( (CURRENT_STATE.REGS[rs]) + immediate_16 );
			auxlb_16 = auxlb_u32 & 0x0000FFFF;
			NEXT_STATE.REGS[rt] = (CURRENT_STATE.REGS[rt] & 0xFFFF0000) | auxlb_16;
			NEXT_STATE.PC = CURRENT_STATE.PC + 4;
			break;

		}


	}



}
