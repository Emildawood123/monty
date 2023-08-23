#include "monty.h"
/**
 * pop - that del last or (first)
 * @stack: head of stack
 * @line: number line
 */
void pop(stack_t **stack, __attribute__((unused)) unsigned int line)
{
if (stack == NULL || *stack == NULL)
{
free_stack(stack);
fprintf(stderr, "L%d: can't pop an empty stack\n", line);
exit(EXIT_FAILURE);
}
if ((*stack)->next == NULL)
{
free_stack(stack);
}
else
{
(*stack)->next->prev = NULL;
*stack = (*stack)->next;
}
}
/**
 * swap - that swap top two el..
 * @stack: head of stack
 * @line: number line
 */
void swap(stack_t **stack, __attribute__((unused)) unsigned int line)
{
int num;
stack_t *new;
new = *stack;
if (*stack == NULL || (*stack)->next == NULL)
{
free_stack(&new);
free_stack(stack);
fprintf(stderr, "L%d: can't swap, stack too short", line);
exit(EXIT_FAILURE);
}
num = new->n;
new->n = new->next->n;
new->next->n = num;
}
