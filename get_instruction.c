#include "monty.h"

/**
 * get_instruction - Parses a line and returns the corresponding instruction.
 * @line: Line to parse.
 * @line_number: Line number.
 *
 * Return: Instruction struct with opcode and function pointer.
 */
instruction_t get_instruction(char *line, unsigned int line_number)
{
instruction_t instruction;
char *opcode = NULL;

/* Extract the opcode from the line */
opcode = strtok(line, " \t\n");

if (opcode != NULL)
{
/* Initialize the instruction struct */
instruction.opcode = opcode;
instruction.f = NULL;

/* Assign the function pointer based on the opcode */
if (strcmp(opcode, "push") == 0)
instruction.f = push;
else if (strcmp(opcode, "pall") == 0)
instruction.f = pall;
else if (strcmp(opcode, "pint") == 0)
instruction.f = pint;
else if (strcmp(opcode, "pop") == 0)
instruction.f = pop;
else if (strcmp(opcode, "swap") == 0)
instruction.f = swap;
else if (strcmp(opcode, "add") == 0)
instruction.f = add;
/* Add more opcode and function mappings here */

/* Handle unknown instructions */
if (instruction.f == NULL)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}
else
{
/* Handle empty lines */
instruction.opcode = NULL;
}
return (instruction);
}
