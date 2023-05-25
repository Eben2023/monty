#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number.
 */
void push(stack_t **stack, unsigned int line_number)
{
char *arg;
int value;
stack_t *new_node;

arg = strtok(NULL, " \t\n");

if (arg == NULL || !is_number(arg))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

value = atoi(arg);
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
(*stack)->prev = new_node;
*stack = new_node;
}


/**
 * pall - Prints all values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number.
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;

(void)line_number;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
 * is_number - Checks if a string is a number.
 * @str: String to check.
 *
 * Return: 1 if the string is a number, 0 otherwise.
 */
int is_number(char *str)
{
if (str == NULL || *str == '\0')
return (0);

if (*str == '-')
str++;

while (*str != '\0')
{
if (*str < '0' || *str > '9')
return (0);
str++;
}

return (1);
}
