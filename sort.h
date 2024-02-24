#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stddef.h>

/**
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);

/* Quick sort Algorithm */
void swap(int *x, int *y);
void quick_sort(int *array, size_t size);
void quick_sort_recursion(int array[], int low, int high, size_t size);
int lomuto_partition(int array[], int low, int high);

#endif /** SORT_H **/
