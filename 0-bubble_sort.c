#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble Sort algorithm.
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Return: Nothing (void)
 *
 * Description: This function iterates through the array multiple times,
 * comparing adjacent elements and swapping them if they are in the wrong order
 * After each swap, the current state of the array is printed using print_array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j; /* Loop counters */
	int tmp;     /* Temporary variable for swapping */

	/* Check if the array is NULL or has less than 2 elements */
	if (array == NULL || size < 2)
		return;

	/* Outer loop: controls the number of passes through the array */
	for (i = 0; i < size - 1; i++)
	{
		/* Inner loop: compares adjacent elements and swaps them if needed */
		for (j = 0; j < size - 1 - i; j++)
		{
			/* If the current element is greater than the next, swap them */
			if (array[j] > array[j + 1])
			{
				tmp = array[j];           /* Store current element in tmp */
				array[j] = array[j + 1]; /* Move next element to current position */
				array[j + 1] = tmp;      /* Move tmp to next position */

				/* Print the array after each swap */
				print_array(array, size);
			}
		}
	}
}
