#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include "monty.h"
/**
 * main - that to receive command from us..
 * @argc: numbers of words
 * @argv: words
 * Return: ..
 */
int main(int argc, char *argv[])
{
instruction_t opcode[] = {{"push", push}, {"pall", pall}, {"pint", pint},
{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop}};
stack_t *new_s;
char *new, *instruc, *line = NULL;
FILE *stream;
size_t len = 0;
int index;
unsigned int count = 0;
if (argc != 2)
	er_argc();
stream = fopen(argv[1], "r");
if (stream == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (1)
{
count++;
if (getline(&line, &len, stream) == -1)
	break;
new = new_line(line);
if (strcmp(new, "\n") == 0 || new[0] == '#')
	continue;
instruc = strtok(new, TOKEN);
value = strtok(NULL, TOKEN);
index = is_valid(instruc, opcode);
if (index != -1)
	opcode[index].f(&new_s, count);
else
{
free_stack(&new_s);
er_ins(count, new, line);
}
} free(line);
free_stack(&new_s);
fclose(stream);
return (0);
}
/**
 * new_line - that funcation
 * @line: line from user
 * Return: line edited
 */
char *new_line(char *line)
{
int i = 0;
while (line[i])
{
if (line[i] == ' ')
{
i++;
}
else
{
line += i;
break;
}
}
if (line[0] == '\n' && strlen(line) == 1)
{
return (line);
}
else if (line[strlen(line) - 1] == '\n')
{
line [strlen(line) - 1] = '\0';
}
return (line);
}
/**
 * is_valid - is exist func??
 * @line:line
 * @opcode:command
 * Return:index or -1 faild
*/
int is_valid(char *line, instruction_t opcode[])
{
int i;
for (i = 0; i <= 6; i++)
{
if (strcmp(line, opcode[i].opcode) == 0)
return (i);
}
return (-1);
}
/**
 * free_stack - that funcation free all ele
 * @stack: stack
 */
void free_stack(stack_t **stack)
{
stack_t *freeme;
freeme = *stack;
while (freeme)
{
free(freeme);
freeme = freeme->next;
}
*stack = NULL;
}
