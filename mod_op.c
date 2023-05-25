#include "monty.h"

/**
 * mod_op - Computes the rest of the division of the second top element
 *          of the stack by the top element
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode being executed
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
stack_t *top, *second;
int result;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

top = *stack;
second = top->next;

if (top->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

result = second->n % top->n;
second->n = result;
*stack = second;
(*stack)->prev = NULL;
free(top);
}
