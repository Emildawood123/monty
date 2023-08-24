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
int n;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line);
exit(EXIT_FAILURE);
}
n = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = n;
}
/**
 * add - merge f and s in one
 * @stack: head of stack
 * @line: line number
 */
void add(stack_t **stack, __attribute__((unused)) unsigned int line)
{
stack_t *new;
new = (*stack)->next;
if (*stack == NULL || (*stack)->next == NULL)
{
free_stack(stack);
fprintf(stderr, "L%d: can't add, stack too short\n", line);
exit(EXIT_FAILURE);
}
(*stack)->n = (*stack)->n + (*stack)->next->n;
if (new->next == NULL)
{
(*stack)->next = NULL;
}
else
{
(*stack)->next = new->next;
}
free(new);
}
/**
 * nop - nothing
 * @stack: head of stack
 * @line: l
 */
void nop(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line)
{

}
/**
 * sub - merge f - s in one
 * @stack: head of stack
 * @line: line number
 */
void sub(stack_t **stack, __attribute__((unused)) unsigned int line)
{
if (*stack == NULL || (*stack)->next == NULL)
{
free_stack(stack);
fprintf(stderr, "L%d: can't sub, stack too short\n", line);
exit(EXIT_FAILURE);
}
(*stack)->n = (*stack)->n - (*stack)->next->n;
(*stack)->next = (*stack)->next->next;
}
