#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: The array to sort
 * @size: The number of elements of @array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx_min, temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		idx_min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[idx_min])
				idx_min = j;
		}

		if (idx_min != i)
		{
			temp = array[idx_min];
			array[idx_min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
