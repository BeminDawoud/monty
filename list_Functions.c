#include "monty.h"
/**
 * addnode - function to add an element on top of the stack
 * @head: a pointer to the head of stack
 * @n: number to be added
 * Return: void
 */
void addnode(stack_t **head, int n)
{

    stack_t *new_node, *temp;

    temp = *head;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
        exit(0);
    }
    if (temp)
        temp->prev = new_node;
    new_node->n = n;
    new_node->next = *head;
    new_node->prev = NULL;
    *head = new_node;
}

/**
 * free_stack - frees all elements of stack
 * @head: Pointer to the Head of the stack
 */
void free_stack(stack_t *head)
{
    stack_t *temp;

    temp = head;
    while (head)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
}

/**
 * f_push - function to push an element to the stack
 * @head: Pointer to the Head of the stack
 * @counter: keeps track of the line number
 * Return: void
 */
void f_push(stack_t **head, unsigned int counter)
{
    int n, j = 0, flag = 0;

    if (inventory.arg)
    {
        if (inventory.arg[0] == '-')
            j++;
        for (; inventory.arg[j] != '\0'; j++)
        {
            if (inventory.arg[j] > 57 || inventory.arg[j] < 48)
                flag = 1;
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(inventory.file);
            free(inventory.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(inventory.file);
        free(inventory.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    n = atoi(inventory.arg);
    if (inventory.Stack_Flag == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}

/**
 * f_pop - this function deletes the first element of the stack
 * @head: Pointer to the Head of the stack
 * @counter: keeps track of the line number
 * Return: void
 */
void f_pop(stack_t **head, unsigned int counter)
{
    stack_t *h;

    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
        fclose(inventory.file);
        free(inventory.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    h = *head;
    *head = h->next;
    free(h);
}