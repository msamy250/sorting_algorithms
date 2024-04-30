#include "sort.h"

/**
 * swap - Function that swaps two nodes in a doubly-linked list
 *
 * @first: address of first node
 * @second: address of second node
 *
 * Return: void
 */

void swap(listint_t *first, listint_t *second)
{
	if (first->prev)
		first->prev->next = second;
	if (second->next)
		second->next->prev = first;

	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
}

/**
 * insertion_sort_list - insertion sorts a doubly-linked list
 *
 * @list: address of pointer to head node
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *key_node, *iter_node;

	if (!list || !*list || !(*list)->next)
		return;
	key_node = (*list)->next;
	while (key_node)
	{
		iter_node = key_node;
		key_node = key_node->next;
		while (iter_node && iter_node->prev)
		{
			if (iter_node->prev->n > iter_node->n)
			{
				swap(iter_node->prev, iter_node);
				if (!iter_node->prev)
					*list = iter_node;
				print_list((const listint_t *)*list);
			}
			else
				iter_node = iter_node->prev;
		}
	}
}
