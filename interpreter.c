#include <stdio.h>
#include <math.h>

#include <interpreter.h>
#include <io.h>

// Operation Codes for Simple Machine Assembler
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define MOD 34
#define POWER 36
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43
#define RSTRING 50
#define WSTRING 51

// Memory size (max words)
#define MEM_SIZE 100

// Simple Machine memory
int memory[MEM_SIZE] = {0};

// Registers
int acumulator = 0;
int instruction_counter = 0;
int instruction_register = 0;
int operation_code = 0;
int operand = 0;

// Last memory position used by currente loaded program
int last_memory_position_used = 0;

void type_program(void) {
	int opc;

	reset_memory();
	
    printf( "\n\t*** Please enter your program one instruction ***\n");
	printf( "\t*** (or data word) at a time. I will type the ***\n");
	printf( "\t*** location number and a queston mark (?).   ***\n");
	printf( "\t*** You then type the word for that location. ***\n");
	printf( "\t*** Type the sentinel -9999 to stop entering  ***\n");
	printf( "\n*** Program load started ***\n\n");

	printf("%d ? ",last_memory_position_used);
	scanf("%d",&memory[last_memory_position_used]);

	while (memory[last_memory_position_used] != -9999 && last_memory_position_used < MEM_SIZE) {
		last_memory_position_used++;
		printf("%d ? ",last_memory_position_used);
		scanf("%d",&memory[last_memory_position_used]);
	}

	printf( "\n*** Program loaded in memory ***\n");

	printf("\nRun program.................1");
	printf("\nSave program to disk & run..2\n");
	printf("\n>> ");
	scanf("%d", &opc);

	if (opc == 2) {
		write_program(last_memory_position_used, memory);
	}

	getchar();
}

void load_program(void) {
	reset_memory();

	last_memory_position_used = read_program(memory);

	getchar();
}

void run_program(void) {
	char str[99];
	int y = 0, s = 1;

	printf("\n*** Program execution begin ***\n");

	while(last_memory_position_used != instruction_counter) {
		instruction_register = memory[instruction_counter];
		operation_code = instruction_register / 100;
		operand = instruction_register % 100;

		switch (operation_code) {
			case READ:
				printf("\n? ");
				scanf("%d",&memory[operand]);
				instruction_counter++;
				break;
			case WRITE:
				printf("\n%d",memory[operand]);
				instruction_counter++;
				break;
			case LOAD:
				acumulator = memory[operand];
				instruction_counter++;
				break;
			case STORE:
				memory[operand] = acumulator;
				instruction_counter++;
				break;
			case ADD:
				acumulator += memory[operand];
				instruction_counter++;
				break;
			case SUBTRACT:
				acumulator -= memory[operand];
				instruction_counter++;
				break;
			case DIVIDE:
				acumulator /= memory[operand];
				instruction_counter++;
				break;
			case MULTIPLY:
				acumulator *= memory[operand];
				instruction_counter++;
				break;
			case MOD:
				acumulator %= memory[operand];
				instruction_counter++;
				break;
			case POWER:
				acumulator = pow(acumulator,memory[operand]);
				instruction_counter++;
				break;
			case BRANCH:
				instruction_counter = operand;
				break;
			case BRANCHNEG:
				if (acumulator < 0) {
					instruction_counter = operand;
				} else {
					instruction_counter++;
				}
				break;
			case BRANCHZERO:
				if (acumulator == 0) {
					instruction_counter = operand;
				}
				else {
					instruction_counter++;
				}
				break;
			case HALT:
				instruction_counter = last_memory_position_used;
				break;
			case RSTRING:
				printf("\nString ? ");
				scanf("%s",str);

				while (str[y] != '\0') {
					++y;

					if (y > ((MEM_SIZE - 1) - operand)) {
						--y;
						break;
					}
				}

				memory[operand] = y;

				for (s = 1; s <= y; s++) {
					memory[operand + s] = (int) str[s - 1];
				}
				
				y = 0;
				instruction_counter++;
				break;
			case WSTRING:
				y = memory[operand];

				for (s = 1; s <= y; s++) {
					printf("%c",memory[operand + s]);
				}

				y = 0;
				instruction_counter++;
				break;
			default :
				instruction_counter++;
				break;
			}
	}

	printf("\n\n*** Program execution finished ***\n");
	getchar();
}

void dump_memory() {
	int co = 0, t = 0, codos = 0;
	
	printf("\n*** Memory State ***\n\n");
	printf("REGISTERS:\n");
	printf("\tAcumulator:\t\t%d\n",acumulator);
	printf("\tInstruction Counter:\t%d\n",instruction_counter);
	printf("\tInstruction Register:\t%d\n",instruction_register);
	printf("\tOperation Code:\t\t%d\n",operation_code);
	printf("\tOperand:\t\t%d\n",operand);
	printf("\nMEMORY:\n");

	for (co = 0; co <= (MEM_SIZE-1); co++) {
		if (co == 0) {
			printf("   ");
			for (t = 0; t <= 9; t++) {
				printf("%6d",t);
			}
		}

		if (co % 10 == 0) {
			if (co == 0) {
				printf("\n%d  ",codos);
			} else {
				printf("\n%d ",codos += 10);
			}
		}

		printf("%6d",memory[co]);
	}
	
	printf("\n\nPress any key to continue\n");
	getchar();
}

void reset_memory(void) {
	int i;

	for (i = 0; i <MEM_SIZE; i++) {
		memory[i] = 0;
	}
	
	acumulator = 0;
	operation_code = 0;
	operand = 0;
	instruction_register = 0;
	last_memory_position_used = 0;
	instruction_counter = 0;
}
