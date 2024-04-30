#include "sort.h"

/**
 * bubble_sort - Function that sorts an array of ints
 * using bubble sort algorithm
 *
 * @array: array of ints
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t iter1, iter2;
	int temp;

	if (!size || !array)
		return;

	iter1 = 0;
	while (iter1 < size)
	{
		for (iter2 = 0; iter2 < size - 1; iter2++)
		{
			if (array[iter2] > array[iter2 + 1])
			{
				temp = array[iter2];
				array[iter2] = array[iter2 + 1];
				array[iter2 + 1] = temp;
				print_array(array, size);
			}
		}
		iter1++;
	}
}
