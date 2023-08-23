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
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
free_stack(stack);
fprintf(stderr, "L%d: can't swap, stack too short\n", line);
exit(EXIT_FAILURE);
}
num = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = num;
}
/**
 * add - merge f and s in one
 * @stack: head of stack
 * @line: line number
 */
void add(stack_t **stack, __attribute__((unused)) unsigned int line)
{
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
free_stack(stack);
fprintf(stderr, "L%d: can't add, stack too short\n", line);
exit(EXIT_FAILURE);
}
(*stack)->n = (*stack)->n + (*stack)->next->n;
(*stack)->next = (*stack)->next->next;

}
