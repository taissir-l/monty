#include "monty.h"
stack_t *head = NULL;
/**
 * main - main fun.
 *
 * @argc: arguments count.
 * @argv: list of arguments.
 *
 * Return: always 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_opener(argv[1]);
	node_freer();

	return (0);
}
/**
 * node_creator - fun Creates a node.
 *
 * @n: number to go inside the node.
 *
 * Return: pointer to the node with sucess otherwise NULL.
 */
stack_t *node_creator(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));

	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;

	return (node);
}
/**
 * node_freer - Function to free nodes.
 *
 * Return: void.
 */
void node_freer(void)
{
	stack_t *tmp;
	stack_t *head = NULL;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
/**
 * queue_adder - function adds node to the queue.
 *
 * @new_node: the new pointer to the node.
 * @ln: line num.
 */
void queue_adder(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
