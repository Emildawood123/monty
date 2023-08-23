#include "monty.h"
/**
 * push - that push new element to stack
 * @stack: stack
 * @line: number
 */
void push(stack_t **stack, unsigned int line)
{
stack_t *new;
int num;
new = malloc(sizeof(stack_t));
if (new == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
if (is_d(value) == -1)
{
free_stack(&new);
free_stack(stack);
fprintf(stderr, "L%d: usage: push integer\n", line);
exit(EXIT_FAILURE);
}
num = atoi(value);
new->n = num;
new->prev = NULL;
if (*stack != NULL)
{
new->next = *stack;
(*stack)->prev = new;
}
else if (*stack == NULL)
{
new->next = NULL;
}
*stack = new;
}
/**
 * pall - that print all ele
 * @stack: head of stack
 * @line: number line
 * Return: void
 */
void pall(stack_t **stack, unsigned int line __attribute__((unused)))
{
stack_t *curr;
curr = *stack;
while (curr)
{
fprintf(stdout, "%d\n", curr->n);
curr = curr->next;
}
}
/**
 * is_d - taht check is digit or no
 * @value: value
 * Return: 0 or 1
 */
int is_d(char *value)
{
int c = 0;
if (value[c] == '-')
{
c++;
}
while (value[c])
{
if (!(value[c] >= '0' && value[c] <= '9'))
{
return (-1);
}
c++;
}
return (1);
}
/**
 * pint - that fun print last
 * @stack: head of
 * @line: number
 * Return: void
 */
void pint(stack_t **stack, __attribute__((unused)) unsigned int line)
{
if (*stack == NULL || stack == NULL)
{
free_stack(stack);
fprintf(stderr, "L%d: can't pint, stack empty\n", line);
exit(EXIT_FAILURE);
}
fprintf(stdout, "%d\n", (*stack)->n);
}
