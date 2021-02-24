#include "slide_line.h"

/**
 * slide_line - slides and merges an array of ints to the left or right,
 * based on the mechanics of the 2048 game on a single horizontal line
 *
 * @line: pointer to the array of ints to slide and merge
 * @size: the size of the array of ints to slide and merge
 * @direction: int defined by macro to determine if sliding left or right
 * if direction is not left or right the function fails
 *
 * Return: 1 if successfully slid and merged, 0 otherwise
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t index = 0, backtrack = 0;
	int count = 0;

	if (size <= 1)
		return (0);

	if (direction == SLIDE_RIGHT)
	{
		for (index = 1; index < size; index++)
		{
			backtrack = index - 1;
			if (line[index] == 0)
			{
				while (backtrack >= 0 && line[backtrack] != 0)
				{
					line[backtrack + 1] = line[backtrack];
					line[backtrack] = 0;
					backtrack--;
				}
			}
			else if (line[index] == line[backtrack])
			{
				line[index] += line[backtrack];
				while (backtrack >= 0 && line[backtrack] != 0)
				{
					line[backtrack + 1] = line[backtrack];
					line[backtrack] = 0;
					backtrack--;
				}
			}
			else
				count++;
		}
		if (count == (size - 2))
			return (0);
		return (1);
	}
	else if (direction == SLIDE_LEFT)
	{
		for (index = (size - 2); index >= 0; index--)
		{
			backtrack = index + 1;
			
		}
	}
	return (0);
}
