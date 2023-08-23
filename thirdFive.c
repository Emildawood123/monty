#include "monty.h"
/**
 * mydiv - div f and s ..
 * @stack: stack
 * @line: line number
 */
void mydiv(stack_t **stack, unsigned int line)
{
int num;
stack_t *new;
if (*stack == NULL || (*stack)->next == NULL)
{
free_stack(stack);
fprintf(stderr, "L%d: can't div, stack too short\n", line);
exit(EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line);
exit(EXIT_FAILURE);
}
new = *stack;
num = (*stack)->n;
(*stack)->next->n /= num;
(*stack)->next->prev = NULL;
free(new);
*stack = (*stack)->next;
}
