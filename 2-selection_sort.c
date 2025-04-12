#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection Sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: The size of the array.
 *
 * Description: This function repeatedly finds the smallest element
 *              in the unsorted portion of the array and swaps it with
 *              the first element of that portion. The process continues
 *              until the entire array is sorted.
 */
void selection_sort(int *array, size_t size)
{
	size_t index1, index2, index_temp; /* Loop counters and index for swapping */
	int temp, swapped;                /* Temporary variables for swapping */

	/* Check if the array is NULL or has less than 2 elements */
	if (array == NULL || size < 2)
		return;

	/* Outer loop: Iterate through each element in the array */
	for (index1 = 0; index1 < size - 1; index1++)
	{
		/* Initialize variables for finding the smallest element */
		temp = array[index1]; /* Assume current element is the smallest */
		swapped = 0;          /* Reset swapped flag */

		/* Inner loop: Find the smallest element in the unsorted portion */
		for (index2 = index1; index2 < size; index2++)
		{
			/* If a smaller element is found, update temp and index_temp */
			if (array[index1] > array[index2] && temp > array[index2])
			{
				temp = array[index2]; /* Update smallest value */
				index_temp = index2;  /* Store its index */
				swapped = 1;          /* Mark that a swap is needed */
			}
		}

		/* If no smaller element was found, skip to the next iteration */
		if (swapped == 0)
			continue;

		/* Swap the smallest element with the current element at index1 */
		array[index_temp] = array[index1];
		array[index1] = temp;

		/* Print the array after each swap */
		print_array(array, size);
	}
}
