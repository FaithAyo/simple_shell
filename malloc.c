#include "main.h"

/**
 * cf_malloc - allocate a pointer to double the space
 * @pt: pointer to the former array
 * @num: pointer to the number of element in the former array
 * Return: pointer to the new array
 */
char **cf_malloc(char **pt, size_t *num)
{
	char **av_new;
	size_t a;

	av_new = malloc(sizeof(char *) * ((*size) + 10));
	if (av_new == NULL)
	{
		free(pt);
		return (NULL);
	}
	for (a =0; i < (*size); i++)
	{
		av_new[a] = pt[a];
	}
	*size += 10;
	free(ptr);
	return (new);
}
