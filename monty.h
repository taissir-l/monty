#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct stack_s - a doubly linked list  of a stack.
 *
 * @n: integer
 * @prev: pointer to the previous element of stack.
 * @next: pointer to the next element of stack.
 * Description: doubly linked .
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - funopcode.
 *
 * @opcode: the opcode
 * @f: handles the opcode
 * Description: opcode and its function.
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int l_num);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file ops*/

void file_opener(char *f_name);
int sep_lines(char *buffer, int l_num, int format);
void file_reader(FILE *);
int len_chars(FILE *);
void func_finder(char *, char *, int, int);

/*Stack ops*/

stack_t *node_creator(int n);
void node_freer(void);
void stack_printer(stack_t **, unsigned int);
void stack_adder(stack_t **, unsigned int);
void queue_adder(stack_t **, unsigned int);
void fun_caller(op_func, char *, char *, int, int);
void top_printer(stack_t **, unsigned int);
void toper_pop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void node_swaper(stack_t **, unsigned int);

/*ops with nodes*/

void nodes_adder(stack_t **, unsigned int);
void node_sub(stack_t **, unsigned int);
void node_div(stack_t **, unsigned int);
void node_mul(stack_t **, unsigned int);
void node_mod(stack_t **, unsigned int);

/*String ops*/

void char_printer(stack_t **, unsigned int);
void str_printer(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Error */

void err(int code_errorr, ...);
void more_errors(int code_errorr, ...);
void error_strg(int code_errorr, ...);
void rotr(stack_t **, unsigned int);

#endif
