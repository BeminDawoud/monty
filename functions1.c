#include "monty.h"
/**
 * f_add - function that adds the top two elements of the stack.
 * @head: Pointer to the Head of the stack
 * @counter: keeps track of the line number
 * Return: void
 */
void f_add(stack_t **head, unsigned int counter)
{
stack_t *h;
int len = 0, temp;

h = *head;
while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't add, stack too short\n", counter);
fclose(inventory.file);
free(inventory.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
temp = h->n + h->next->n;
h->next->n = temp;
*head = h->next;
free(h);
}

/**
 * f_div - function that adds the top two elements of the stack.
 * @head: Pointer to the Head of the stack
 * @counter: keeps track of the line number
 * Return: void
 */
void f_div(stack_t **head, unsigned int counter)
{
stack_t *h;
int len = 0, temp;

h = *head;
while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't div, stack too short\n", counter);
fclose(inventory.file);
free(inventory.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
if (h->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(inventory.file);
free(inventory.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
temp = h->next->n / h->n;
h->next->n = temp;
*head = h->next;
free(h);
}

/**
 * f_mul - function to multiply the top two elements of the stack.
 * @head: Pointer to the Head of the stack
 * @counter: keeps track of the line number
 * Return: no return
 */
void f_mul(stack_t **head, unsigned int counter)
{
stack_t *h;
int len = 0, temp;

h = *head;
while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
fclose(inventory.file);
free(inventory.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
temp = h->next->n * h->n;
h->next->n = temp;
*head = h->next;
free(h);
}

/**
 *f_nop- this function does nothing.
 *@head: Pointer to the Head of the stack
 *@counter: keeps track of the line number
 *Return: void
 */
void f_nop(stack_t **head, unsigned int counter)
{
(void)counter;
(void)head;
}

/**
 * f_mod - function to find modulo of top two elements of stack
 * @head: Pointer to the Head of the stack
 * @counter: keeps track of the line number
 * Return: void
 */
void f_mod(stack_t **head, unsigned int counter)
{
stack_t *h;
int len = 0, temp;

h = *head;
while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
fclose(inventory.file);
free(inventory.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
if (h->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(inventory.file);
free(inventory.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
temp = h->next->n % h->n;
h->next->n = temp;
*head = h->next;
free(h);
}
