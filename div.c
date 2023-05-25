#include "monty.h"

/**
 * div_op - Divides the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode being executed
 */
void div_op(stack_t **stack, unsigned int line_number)
{
stack_t *h = *stack;
int len = 0, aux;

while (h)
{
h = h->next;
len++;
}

if (len < 2)
{
fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

h = *stack;

if (h->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

aux = h->next->n / h->n;
h->next->n = aux;
*stack = h->next;
free(h);
}
