#include "monty.h"
/**
 * mydiv - div f and s ..
 * @stack: stack
 * @line: line number
 */
void mydiv(stack_t **stack, __attribute__((unused)) unsigned int line)
{
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
(*stack)->n = (*stack)->n / (*stack)->next->n;
(*stack)->next = (*stack)->next->next;
}
