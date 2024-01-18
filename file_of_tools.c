#include "monty.h"
/**
 * file_opener - function that opens a file.
 *
 * @f_name: namepath.
 *
 * Return: void.
 */
void file_opener(char *f_name)
{
	FILE *fpd = fopen(f_name, "r");

	if (f_name == NULL || fpd == NULL)
		err(2, f_name);

	file_reader(fpd);

	fclose(fpd);
}
/**
 * file_reader - function that reads a file.
 *
 * @fpd: pointer to descriptor.
 *
 * Return: void
 */
void file_reader(FILE *fpd)
{
	int l_num, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (l_num = 1; getline(&buffer, &len, fpd) != -1; l_num++)
	{
		format = sep_lines(buffer, l_num, format);
	}

	free(buffer);
}
/**
 * sep_lines - function separates each line to determine
 *                                 which function to call.
 *
 * @buffer: line from file.
 * @l_num: line number.
 * @format:  storage format.
 *
 * Return: 0 if the opcode is stack else 1.
 */
int sep_lines(char *buffer, int l_num, int format)
{
	char *opcode, *val;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	func_finder(opcode, val, l_num, format);

	return (format);
}
/**
 * func_finder - function to find the appropriate function for the opcode.
 *
 * @opcode: opcode.
 * @value: argument of opcode.
 * @format:  storage format.
 * @ln: line number
 *
 * Return: void
 */
void func_finder(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", stack_adder},
		{"pall", stack_printer},
		{"pint", top_printer},
		{"pop", toper_pop},
		{"nop", nop},
		{"swap", node_swaper},
		{"add", nodes_adder},
		{"sub", node_sub},
		{"div", node_div},
		{"mul", node_mul},
		{"mod", node_mod},
		{"pchar", char_printer},
		{"pstr", str_printer},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			fun_caller(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}
/**
 * fun_caller - function to Calls the required fun.
 *
 * @func: Pointer to the function called.
 * @op: representer of the opcode.
 * @val: the numeric value.
 * @ln: line num.
 * @format: Format specifier.
 */
void fun_caller(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	stack_t *head = NULL;
	int f;
	int i;

	f = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			f = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = node_creator(atoi(val) * f);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			queue_adder(&node, ln);
	}
	else
		func(&head, ln);
}
