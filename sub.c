#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode being executed
 */
void sub(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

(*stack)->next->n -= (*stack)->n;
temp = *stack;
*stack = (*stack)->next;
(*stack)->prev = NULL;
free(temp);
}
