#include "monty.h"
/**
 * f_pall - function to prints all elements of the stack
 * @head: Pointer to the Head of the stack
 * @counter: keeps track of the line number
 * Return: void
 */
void f_pall(stack_t **head, unsigned int counter)
{
stack_t *h;
(void)counter;

h = *head;
if (h == NULL)
return;
while (h)
{
printf("%d\n", h->n);
h = h->next;
}
}
/**
 * f_pchar - prints the char at the top of the stack.
 * @head: Pointer to the Head of the stack
 * @counter: keeps track of the line number
 * Return: void
 */
void f_pchar(stack_t **head, unsigned int counter)
{
stack_t *h;

h = *head;
if (!h)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
fclose(inventory.file);
free(inventory.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
if (h->n > 127 || h->n < 0)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
fclose(inventory.file);
free(inventory.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
printf("%c\n", h->n);
}
/**
 * f_pint - prints the top element of the stack
 * @head: Pointer to the Head of the stack
 * @counter: keeps track of the line number
 * Return: void
 */
void f_pint(stack_t **head, unsigned int counter)
{
if (*head == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
fclose(inventory.file);
free(inventory.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}

/**
 * f_pstr - function to print the string at top of the stack.
 * @head: Pointer to the Head of the stack
 * @counter: keeps track of the line number
 * Return:void
 */
void f_pstr(stack_t **head, unsigned int counter)
{
stack_t *h;
(void)counter;

h = *head;
while (h)
{
if (h->n > 127 || h->n <= 0)
{
break;
}
printf("%c", h->n);
h = h->next;
}
printf("\n");
}
