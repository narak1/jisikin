#include <stdio.h>
#include <string.h>

#define MSB 0x80000000
#define LSB 0x1
#define MAXBIT 32

typedef unsigned int uint;

uint func_add(uint n1, uint n2);
uint func_sub(uint n1, uint n2);
uint func_and(uint n1, uint n2);
uint func_or(uint n1, uint n2);
uint func_xor(uint n1, uint n2);
uint func_shl(uint n1, uint n2);
uint func_shr(uint n1, uint n2);
uint func_asr(uint n1, uint n2);
uint func_rol(uint n1, uint n2);
uint func_ror(uint n1, uint n2);

enum Operator { OP_ADD, OP_SUB, OP_AND, OP_OR, OP_XOR, OP_SHL, OP_SHR, OP_ASR, OP_ROL, OP_ROR,
				OP_MAX };
char *op_str[] = { "add", "sub", "and", "or", "xor", "shl", "shr", "asr", "rol", "ror" };
uint (*op_func[])(uint n1, uint n2)
	= { func_add, func_sub, func_and, func_or, func_xor, func_shl, func_shr, func_asr, func_rol, func_ror };

main()
{
	uint i;
	uint num1, num2, num3, op;
	char operator[4];

	while(1)
	{
		printf("Type in an expression: ");
		scanf("%x%s%x", &num1, operator, &num2);
		for( i=0 ; i<OP_MAX ; i++ ) {
			if( strcmp(operator, op_str[i]) == 0 ) {
				op = i;
				break;
			}
		}

		if( i == OP_MAX ) {
			printf("No defined operator [%s]\n\n", operator);
			continue;
		}

		num3 = op_func[i](num1, num2);

		printf("The answer is: %x\n\n", num3);
	}
}

uint func_add(uint n1, uint n2) { return n1+n2; }
uint func_sub(uint n1, uint n2) { return n1-n2; }
uint func_and(uint n1, uint n2) { return n1&n2; }
uint func_or(uint n1, uint n2) { return n1|n2; }
uint func_xor(uint n1, uint n2) { return n1^n2; }
uint func_shl(uint n1, uint n2) { if( n2 < MAXBIT ) return n1<<n2; else return 0; }
uint func_shr(uint n1, uint n2) { if( n2 < MAXBIT ) return n1>>n2; else return 0; }

uint func_asr(uint n1, uint n2)
{
	uint i, msb = n1 & MSB;

	for( i=0 ; i<n2 ; i++ ) {
		n1 >>= 1;
		n1 |= msb;
	}

	return n1;
}

uint func_rol(uint n1, uint n2)
{
	uint i, msb;

	for( i=0 ; i<n2 ; i++ ) {
		msb = n1 & MSB;
		n1 <<= 1;
		if( msb )
			n1 |= LSB;
	}

	return n1;
}

uint func_ror(uint n1, uint n2)
{
	uint i, lsb;

	for( i=0 ; i<n2 ; i++ ) {
		lsb = n1 & LSB;
		n1 >>= 1;
		if( lsb )
			n1 |= MSB;
	}

	return n1;
}

