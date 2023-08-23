#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#define TOKEN " \t\r\n\a\""
extern char *value;
char *value;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void push(stack_t **stack, unsigned int line);
void pall(stack_t **stack, unsigned int line);
void free_stack(stack_t **stack);
int is_valid(char *line, instruction_t opcode[]);
char *new_line(char *line);
void er_ins(int count, char *new_line, char *line);
void er_argc(void);
void pint(stack_t **stack, unsigned int n);
void add(stack_t **stack, unsigned int n);
int is_d(char *value);
void pop(stack_t **stack, unsigned int line);
void swap(stack_t **stack, unsigned int line);
void nop(stack_t **stack, unsigned int line);
void sub(stack_t **stack, unsigned int line);
void mydiv(stack_t **stack, unsigned int line);
void mymul(stack_t **stack, unsigned int line);
#endif
