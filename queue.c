#include "monty.h"
/**
 * f_queue - Function to set the queue flag.
 * @head: Pointer to the Head of the queue
 * @counter: keeps track of the line number
 * Return: void
 */
void f_queue(stack_t **head, unsigned int counter)
{
(void)head;
(void)counter;
inventory.Stack_Flag = 1;
}

/**
 * addqueue - function to add an element to the queue
 * @n: number to be added
 * @head: Pointer to the Head of the queue
 * Return: void
 */
void addqueue(stack_t **head, int n)
{
stack_t *new_node, *temp;

temp = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error\n");
}
new_node->n = n;
new_node->next = NULL;
if (temp)
{
while (temp->next)
	temp = temp->next;
}
if (!temp)
{
*head = new_node;
new_node->prev = NULL;
}
else
{
temp->next = new_node;
new_node->prev = temp;
}
}

