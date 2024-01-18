#include "monty.h"
/**
 *f_sub- function to substract top two elements.
 *@head: Pointer to the Head of the stack
 *@counter: keeps track of the line number
 *Return: void
 */
void f_sub(stack_t **head, unsigned int counter)
{
    stack_t *temp;
    int sus, nodes;

    temp = *head;
    for (nodes = 0; temp != NULL; nodes++)
        temp = temp->next;
    if (nodes < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
        fclose(inventory.file);
        free(inventory.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    temp = *head;
    sus = temp->next->n - temp->n;
    temp->next->n = sus;
    *head = temp->next;
    free(temp);
}
/**
 * f_stack - function to set the stack flag.
 * @head: Pointer to the Head of the stack
 * @counter: keeps track of the line number
 * Return: no return
 */
void f_stack(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    inventory.Stack_Flag = 0;
}
/**
 * f_swap - function to swap the top two elements of the stack.
 * @head: Pointer to the Head of the stack
 * @counter: keeps track of the line number
 * Return: void
 */
void f_swap(stack_t **head, unsigned int counter)
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
        fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
        fclose(inventory.file);
        free(inventory.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    h = *head;
    temp = h->n;
    h->n = h->next->n;
    h->next->n = temp;
}

/**
 *f_rotr- function to rotates the stack to bottom
 *@head: Pointer to the Head of the stack
 *@counter: keeps track of the line number
 *Return: void
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *copy;

    copy = *head;
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    while (copy->next)
    {
        copy = copy->next;
    }
    copy->next = *head;
    copy->prev->next = NULL;
    copy->prev = NULL;
    (*head)->prev = copy;
    (*head) = copy;
}
/**
 *f_rotl- function to rotates the stack to top.
 *@head: Pointer to the Head of the stack
 *@counter: keeps track of the line number
 *Return: void
 */
void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *tmp = *head, *temp;

    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    temp = (*head)->next;
    temp->prev = NULL;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = *head;
    (*head)->next = NULL;
    (*head)->prev = tmp;
    (*head) = temp;
}