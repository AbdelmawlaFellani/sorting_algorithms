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
int devider(int *arr, int start, int end, size_t size)
{
	int i, j, tmp;

	i = start -1;

	for (j = start; j < end; j++)
	{
		if (arr[j] < arr[end])
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			print_array(arr, size);
		}
	}
	i++;
	if (arr[i] != arr[end])
	{
		tmp = arr[i];
		arr[i] = arr[end];
		arr[end] = tmp;
		print_array(arr, size);
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
void Lomuto_quick_sort(int *arr, int start, int end, size_t size)
{
	int pivot;

	if (end <= start)
		return;
	pivot = devider(arr, start, end, size);
	Lomuto_quick_sort(arr, start, pivot - 1, size);
	Lomuto_quick_sort(arr, pivot + 1, end, size);
}
/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick Sort algorithm with Lomuto partition scheme
 * @arr: the array to be sorted
 * @size: size of the array
**/
void quick_sort(int *arr, size_t size)
{
	if (!arr || size < 2)
		return;
	Lomuto_quick_sort(arr, 0, size - 1, size);
}
