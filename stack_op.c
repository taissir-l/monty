#include "monty.h"
/**
 * node_mul - function adds  top two elements of the stack.
 *
 * @stack: the pointer to a pointer pointing to top node of stack.
 * @l_num: Interger of the line number of the opcode.
 */
void node_mul(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, l_num, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * node_mod - function adds  top two elements of the stack.
 *
 * @stack: the pointer to a pointer pointing to top node of stack.
 * @l_num: Interger of the line number of the opcode.
 */
void node_mod(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_errors(8, l_num, "mod");

	if ((*stack)->n == 0)
		more_errors(9, l_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;

	free((*stack)->prev);
	(*stack)->prev = NULL;
}
