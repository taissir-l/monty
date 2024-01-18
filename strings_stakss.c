#include "monty.h"
/**
 * char_printer - function prints  Ascii value.
 *
 * @stack: the pointer to a pointer pointing to top node of stack.
 * @l_num: Interger of the line number of the opcode.
 */
void char_printer(stack_t **stack, unsigned int l_num)
{
	int a;

	if (stack == NULL || *stack == NULL)
		error_strg(11, l_num);

	a = (*stack)->n;
	if (a < 0 || a > 127)
		error_strg(10, l_num);
	printf("%c\n", a);
}
/**
 * str_printer - function prints a string.
 *
 * @stack: the pointer to a pointer pointing to top node of stack.
 * @l_num: Interger of the line number of the opcode.
 */
void str_printer(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int a;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		a = tmp->n;
		if (a <= 0 || a > 127)
			break;
		printf("%c", a);
		tmp = tmp->next;
	}

	printf("\n");
}
/**
 * rotl - function that rotates the first node of the stack to the bottom.
 *
 * @stack: the pointer to a pointer pointing to top node of stack.
 * @l_num: Interger of the line number of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
/**
 * rotr - function to otates the last node of the stack to the top.
 *
 * @stack: the pointer to a pointer pointing to top node of stack.
 * @l_num: Interger of the line number of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;


	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
