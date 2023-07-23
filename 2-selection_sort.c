#include "sort.h"

/**
 * selection_sort - function that sorts array using selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, min, swapped_flag;

	for (i = 0; i < size; i++)
	{
		min = i;
		swapped_flag = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
				swapped_flag = 1;
			}
		}
		if (j != i)
		{
			/* swap */
			tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
			if (swapped_flag)
				print_array(array, size);
		}
	}
}
