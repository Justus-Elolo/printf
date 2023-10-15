#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * 
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* Define an array of flag characters and their corresponding bit values */
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;// Loop variables and a variable to store the current position in 'format'.
	int flags = 0;// Initialize the flags to zero.
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	// Iterate through the 'format' string starting from the position after '*i'.
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		 // Iterate through the array of flag characters.
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		// If the current character in 'format' matches a flag character, set the corresponding flag bit.
		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
