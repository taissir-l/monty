#include "monty.h"
/**
 * err - function prints appropiate error messages according to error code.
 *
 * @code_errorr: wich are:
 * (1) => user does not give any file or more than one file to the program.
 * (2) => file provided is not a file that can be opened or read.
 * (3) => file provided contains an invalid instruction.
 * (4) => the program is unable to malloc more memory.
 * (5) => the parameter passed to the instruction "push" is not an int.
 * (6) => stack it empty for pint.
 * (7) => stack it empty for pop.
 * (8) => stack is too short for operation.
 */
void err(int code_errorr, ...)
{
	va_list ag;
	char *op;
	int a_num_l;

	va_start(ag, code_errorr);
	switch (code_errorr)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			a_num_l = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", a_num_l, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	node_freer();

	exit(EXIT_FAILURE);
}
/**
 * more_errors - function that handles errors.
 *
 * @code_errorr: wich are:
 * (6) => stack it empty for pint.
 * (7) => stack it empty for pop.
 * (8) =>  stack is too short for operation.
 * (9) => the division by zero.
 */

void more_errors(int code_errorr, ...)
{
	va_list ag;
	char *op;
	int a_num_l;

	va_start(ag, code_errorr);
	switch (code_errorr)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			a_num_l = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", a_num_l, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	node_freer();

	exit(EXIT_FAILURE);
}
/**
 * error_strg - function to handle errors.
 *
 * @code_errorr: wich are:
 * (10) ~> number inside a node is outside ASCII bounds.
 * (11) ~> stack is empty.
 */
void error_strg(int code_errorr, ...)
{
	va_list ag;
	int a_num_l;

	va_start(ag, code_errorr);
	a_num_l = va_arg(ag, int);
	switch (code_errorr)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", a_num_l);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", a_num_l);
			break;
		default:
			break;
	}
	node_freer();

	exit(EXIT_FAILURE);
}
