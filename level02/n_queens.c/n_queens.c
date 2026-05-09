#include <stdio.h>
#include <stdlib.h>

int		ft_abs(int x)
{
	return x > 0 ? x : -x;
}

void	print(int *board, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			fprintf(stdout, " ");
		fprintf(stdout, "%d", board[i]);
	}
	fprintf(stdout, "\n");
}

int		no_conflict(int *board, int col)
{
	for (int i = 0; i < col; i++)
		if (board[col] == board[i] || ft_abs(col - i) == ft_abs(board[col] - board[i]))
			return 0;
	return 1;
}

void	solve(int *board, int col, int n)
{
	if (n == col)
	{
		print(board, n);
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		board[col] = i;
		if (no_conflict(board, col))
			solve(board, col + 1, n);
	}
}

int	main(int ac, char *av[])
{
	if (ac != 2)
		return 1;
	int n = atoi(av[1]);
	int *board = calloc(n, sizeof(int));
	if (!board)
		return 1;
	solve(board, 0, n);
	free(board);
	return 0;
}
