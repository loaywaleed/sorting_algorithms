#include "sort.h"
#define FIRST 0
#define NEXT 1

/**
 * bubble_sort - sort array elments from min to max value
 * @array: array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t pass, current, swap;
	int flag;

	if (array == NULL || size < 2)
		return;
	for (pass = 0; pass < size - 1; pass++)
	{
		flag = 0;
		for (current = 0; current < size - pass - 1; current++)
		{
			if (array[current] > array[current + NEXT])
			{
				swap = array[current];
				array[current] = array[current + NEXT];
				array[current + NEXT] = swap;
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
