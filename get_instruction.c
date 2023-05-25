#include "monty.h"

/**
 * assign_function_pointer - Assigns the function pointer based on the opcode.
 * @opcode: Opcode to check.
 *
 * Return: Function pointer corresponding to the opcode, or NULL if not found.
 */
void (*assign_function_pointer(char *opcode))(stack_t **, unsigned int)
{
if (strcmp(opcode, "push") == 0)
return (push);
else if (strcmp(opcode, "pall") == 0)
return (pall);
else if (strcmp(opcode, "pint") == 0)
return (pint);
else if (strcmp(opcode, "pop") == 0)
return (pop);
else if (strcmp(opcode, "swap") == 0)
return (swap);
else if (strcmp(opcode, "add") == 0)
return (add);
else if (strcmp(opcode, "nop") == 0)
return (nop);
else if (strcmp(opcode, "sub") == 0)
return (sub);
else if (strcmp(opcode, "div_op") == 0)
return (div_op);
/* Add more opcode and function mappings here */

return (NULL);
}

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
instruction.f = assign_function_pointer(opcode);

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
