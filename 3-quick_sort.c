#include "sort.h"

/**
 * swap - Function that swaps two int values.
 *
 * @array: the integer array to sort.
 * @size: the size of the array.
 * @first: address of first value.
 * @second: address of second value.
 *
 * Return: void
 */

void swap(int *array, size_t size, int *first, int *second)
{
	if (*first != *second)
	{
		*first = *first + *second;
		*second = *first - *second;
		*first = *first - *second;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - partiotions the array.
 * @array: the integer array to sort.
 * @size: the size of the array.
 * @low:  the low index of the sort range.
 * @high: the high index of the sort range.
 *
 * Return: size_t.
 */
size_t lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int iter1, iter2, pivot;

	pivot = array[high]; /* pivot should always be the last element */

	for (iter1 = iter2 = low; iter2 < high; iter2++)
	{
		if (array[iter2] < pivot)
			swap(array, size, &array[iter2], &array[iter1++]);
	}
	swap(array, size, &array[iter1], &array[high]);
	return (iter1);
}

/**
 * quicksort - quicksorts via lomuto partitioning scheme.
 * @array: the integer array to sort.
 * @size: the size of the array.
 * @low:  the low index of the sort range.
 * @high: the high index of the sort range.
 *
 * Return: void.
 */
void quicksort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t p = lomuto_partition(array, size, low, high);

		quicksort(array, size, low, p - 1);
		quicksort(array, size, p + 1, high);
	}
}

/**
 * quick_sort - calles quicksort.
 * @array: the integer array to sort.
 * @size: the size of the array.
 *
 * Return: void.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
