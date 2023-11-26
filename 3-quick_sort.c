#include "sort.h"

/**
 * devider - This function finds the pivot
 * element in the array and returns its index.
 * @array: The array to sort.
 * @start: The start index of the subarray to sort.
 * @end: The end index of the subarray to sort.
 * @size: The size of the array.
 *
 * Return: The index of the pivot element.
 */
int devider(int *array, int start, int end, size_t size)
{
	int j, tmp, i;

	i = start - 1;

	for (j = start; j < end; j++)
	{
		if (array[j] < array[end])
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (j != i)
				print_array(array, size);
		}
	}

	i++;
	if (array[i] != array[end])
	{
		tmp = array[end];
		array[end] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * Lomuto_quick_sort - This function sorts the array
 * using the Lomuto partitioning scheme.
 * @array: The array to sort.
 * @start: The start index of the subarray to sort.
 * @end: The end index of the subarray to sort.
 * @size: The size of the array.
 */
void Lomuto_quick_sort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (end <= start)
		return;

	pivot = devider(array, start, end, size);
	Lomuto_quick_sort(array, start, pivot - 1, size);
	Lomuto_quick_sort(array, pivot + 1, end, size);
}

/**
 * quick_sort - This function sorts the array using the quick sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	Lomuto_quick_sort(array, 0, size - 1, size);
}
