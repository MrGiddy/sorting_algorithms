#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: An array of integers
 * @size: The number of element in @array
 *
 * Description: Lomuto partition is used
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	low = 0;
	high = size - 1;

	quick_sort_recursion(array, low, high, size);
}

/**
 * quick_sort_recursion - Recursively calls itself to sort @array
 * @array: An array of integers
 * @low: low index of subarray with elements less than the pivot
 * @high: high index of subarray with elements greater than the pivot
 * @size: The number of element in @array
 *
 * Return: Nothing
 */
void quick_sort_recursion(int array[], int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high);
		print_array(array, size);

		quick_sort_recursion(array, low, pivot_index - 1, size);
		quick_sort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * lomuto_partition - partitions an array based on a pivot element
 * @array: An array of integers
 * @low: low index of the subarray with elements less than the pivot
 * @high: high index of the subarray with elements greater than the pivot
 *
 * Return: Nothing
 */
int lomuto_partition(int array[], int low, int high)
{
	int pivot_value;
	int i, j;

	pivot_value = array[high];

	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}

	swap(&array[i], &array[high]);

	return (i);
}

/**
 * swap - Swaps two integers
 * @x: The first integer
 * @y: The second integer
 *
 * Return: Nothing
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
