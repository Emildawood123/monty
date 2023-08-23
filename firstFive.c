#include "monty.h"
/**
 * push - that push new element to stack
 * @stack: stack
 * @n: number
 */
void push(stack_t **stack, unsigned int n)
{
stack_t *new;
new = malloc(sizeof(stack_t));
if (new == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new->n = n;
new->prev = NULL;
if (*stack != NULL)
{
new->next = *stack;
(*stack)->prev = new;
}
else
{
new->next = NULL;
}
*stack = new;
}
/**
 * pall - that print all ele
 * @stack: head of stack
 * @n: number line
 * Return: void
 */
void pall(stack_t **stack, unsigned int n __attribute__((unused)))
{
stack_t *curr;
curr = *stack;
while (curr)
{
fprintf(stdout, "%i\n", curr->n);
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
if (value[0] == '-')
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
 * @n: number
 * Return: void
 */
void pint(stack_t **stack, __attribute__((unused)) unsigned int n)
{
if (*stack == NULL || stack == NULL)
{
fprintf(stdout, "L%d: can't pint, stack empty", n);
exit(EXIT_FAILURE);
}
fprintf(stdout, "%d\n", (*stack)->n);
}
