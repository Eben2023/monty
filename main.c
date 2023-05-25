#include "monty.h"

/**
 * main - Monty bytecode interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
FILE *file;
stack_t *stack = NULL;
char line[1024];
unsigned int line_number = 0;
instruction_t instruction;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

while (fgets(line, sizeof(line), file) != NULL)
{
line_number++;
instruction = get_instruction(line, line_number);
if (instruction.opcode != NULL)
instruction.f(&stack, line_number);
}

free_stack(stack);
fclose(file);

return (EXIT_SUCCESS);
}
