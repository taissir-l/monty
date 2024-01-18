#include "monty.h"
/**
 * nop - simple function.
 *
 * @stack: the pointer to a pointer pointing to top node of stack.
 * @l_num: Interger of the line number of the opcode.
 */
void nop(stack_t **stack, unsigned int l_num)
{
	(void)stack;
	(void)l_num;
}
/**
 * node_swaper - function swaps top two elements of  stack.
 *
 * @stack: the pointer to a pointer pointing to top node of stack.
 * @l_num: Interger of the line number of the opcode.
 */
void node_swaper(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, l_num, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
/**
 * nodes_adder - function adds  top two elements of  stack.
 *
 * @stack: the pointer to a pointer pointing to top node of stack.
 * @l_num: Interger of the line number of the opcode.
 */
void nodes_adder(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, l_num, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;

	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * node_sub - function that adds top two elements of  stack.
 *
 * @stack: the pointer to a pointer pointing to top node of stack.
 * @l_num: Interger of the line number of the opcode.
 */
void node_sub(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_errors(8, l_num, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);

	(*stack)->prev = NULL;
}
/**
 * node_div - function adds the top two elements of  stack.
 *
 * @stack: the pointer to a pointer pointing to top node of stack.
 * @l_num: Interger of the line number of the opcode.
 */
void node_div(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, l_num, "div");

	if ((*stack)->n == 0)
		more_errors(9, l_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
