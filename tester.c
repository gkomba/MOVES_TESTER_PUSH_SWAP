#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "./libft/ft_split.c"
#include "./libft/ft_memset.c"

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

int	partition(int *tab, int start, int end)
{
	int	pivot = 0;

	pivot = ((tab[start] + tab[end] + tab[(start + end) / 2]) / 3);
	while (start < end)
	{
		while (start < end && tab[start] <= pivot)
			start++;
		while (start < end && tab[end] > pivot)
			end--;
		ft_swap(&tab[start], &tab[end]);
	}
	return (start);
}

void	ft_qsort(int *tab, int start, int end)
{
	int	position = 0;

	if (start < end)
	{
		position = partition(tab, start, end);
		ft_qsort(tab, start, position - 1);
		ft_qsort(tab, position, end);
	}
}

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	int n = 100000;
	char buffer[n];
	int readed = read(fd, buffer, n);
	char **matrix = ft_split(buffer, '\n');
	int i = 0;
	while (matrix[i] != NULL)
		i++;
	int *place;
	place = (int *)malloc(sizeof(int) * (i + 1));
	i = 0;
	while (matrix[i] != NULL)
	{
		place[i] = atoi(matrix[i]);
		i++;
	}
	ft_qsort(place, 0, i - 1);
	printf("BUFFER_LIMIT: %d / %d\n", n, readed);
	printf("Min Value of Sorts: %d\n", place[0]);
	printf("Middle Value of Sorts: %d\n", place[(i - 1) / 2]);
	printf("Max Value of Sorts: %d\n", place[i - 1]);
}
