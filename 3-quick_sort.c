#include "sort.h"
/**
 * devider - finds the pivot element in the array and returns its index
 * @arr: the array to be sorted
 * @start: the starting index of the subarray
 * @end: the ending index of the subarray
 * @size: size of the array
 *
 * Return: The index of the pivot element.
**/
int devider(int *array, int start, int end, size_t size)
{
	int i, j, tmp;

	i = start -1;

	for (j = start; j < end; j++)
	{
		if (array[j] < array[end])
		{
			i++;
			tmp = array[i];
			array[i] = arr[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	i++;
	if (array[i] != array[end])
	{
		tmp = array[i];
		array[i] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}
	return (i);
}
/**
 * Lomuto_quick_sort - sorts an array of integers using the Quick Sort
 * algorithm with Lomuto partition scheme
 * @arr: the array to be sorted
 * @start: the starting index of the subarray
 * @end: the ending index of the subarray
 * @size: size of the array
**/
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
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick Sort algorithm with Lomuto partition scheme
 * @arr: the array to be sorted
 * @size: size of the array
**/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	Lomuto_quick_sort(array, 0, size - 1, size);
}
