#include "monty.h"
/**
 * stack_adder - function that adds a node to stack.
 *
 * @new_node: pointer to new node.
 * @ln: Interger of line number of the opcode.
 */
void stack_adder(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;
	stack_t *head = NULL;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}
/**
 * stack_printer - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: line number of  the opcode.
 */
void stack_printer(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	(void) l_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * toper_pop - function adds a node to stack.
 *
 * @stack: the pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger of the line number of the opcode.
 */
void toper_pop(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_errors(7, l_num);

	tmp = *stack;
	*stack = tmp->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
/**
 * top_printer - function prints top node of stack.
 *
 * @stack: the pointer to a pointer pointing to top node of stack.
 * @l_num: Interger of the line number of the opcode.
 */
void top_printer(stack_t **stack, unsigned int l_num)
{
	if (stack == NULL || *stack == NULL)
		more_errors(6, l_num);
	printf("%d\n", (*stack)->n);
}
