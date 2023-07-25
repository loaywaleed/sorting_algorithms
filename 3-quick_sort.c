#include "sort.h"

/**
 * swap - function that swaps two elements in an array
 * @a: element to swap
 * @b: 2nd element in swap operation
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * partition - lomuto partitioning with pivot in last element
 * @array: array to sort
 * @low: low value
 * @high: high value
 * @size: the size of the array to sort
 * Return: pivot after returning it to its place
 */
int partition(int *array, int low, int high, size_t size)
{
	int tmp_pivot, j, i;

	tmp_pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < tmp_pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_s - recursive function to to sort arrays
 * @array: array to sort
 * @low: low value
 * @high: high value
 * @size: the size of the array to sort
 */
void quick_s(int *array, int low, int high, size_t size)
{
	int piv = 0;

	if (low < high)
	{
		piv = partition(array, low, high, size);
		quick_s(array, low, piv - 1, size);
		quick_s(array, piv + 1, high, size);
	}
}

/**
 * quick_sort - function that sorts array using quicksort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!(array) || size < 2)
		return;
	quick_s(array, 0, size - 1, size);
}
