#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	required_sum;
int	size;
int	*nums;

void	print_subset(int subsize, int *subset)
{
	for (int i = 0; i < subsize; i++)
	{
		printf("%d", subset[i]);
		if (i < subsize - 1)
			printf(" ");
	}
	printf("\n");
}

int		calc_subset_sum(int subsize, int *subset)
{
	int	result = 0;
	for (int i = 0; i < subsize; i++)
		result += subset[i];
	return (result);
}

void	solve(int subsize, int current_idx, int *subset)
{
	if (current_idx == size)
	{
		if (calc_subset_sum(subsize, subset) == required_sum)
			print_subset(subsize, subset);
		return ;
	}
	solve(subsize, current_idx + 1, subset);
	subset[subsize] = nums[current_idx];
	solve(subsize + 1, current_idx + 1, subset);
}

int	main(int argc, char *argv[])
{
	if (argc < 3)
		return (1);
	required_sum = atoi(argv[1]);
	size = argc - 2;
	nums = calloc(size, sizeof(int));
	if (!nums)
		return (1);
	int	*subset = calloc(size, sizeof(int));
	if (!subset)
		return (free(nums), 1);
	for (int i = 0; i < size; i++)
		nums[i] = atoi(argv[i + 2]);
	int subsize = 0;
	int current_idx = 0;
	solve(subsize, current_idx, subset);
	free(nums);
	free(subset);
}
