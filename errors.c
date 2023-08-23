#include "monty.h"
/**
 * er_ins - that print error for inst..
 * @count: count
 * @line: line
 * @new_line: new_line
 */
void er_ins(int count, char *new_line, char *line)
{
fprintf(stderr, "L%d: unknown instruction %s\n", count, new_line);
free(line);
exit(EXIT_FAILURE);
}
/**
 * er_argc - taht to print error
 */
void er_argc(void)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
