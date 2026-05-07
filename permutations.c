#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i = 0;
	while (s[i])
		i++;
	return i;
}

void	ft_swap(char *s1, char *s2)
{
	char	c;

	c = *s1;
	*s1 = *s2;
	*s2 = c;
}

void	sort(char *s)
{
	int len = ft_strlen(s);

	while (len-- > 0)
	{
		int i = 0;
		while (s[i + 1])
		{
			if (s[i] > s[i + 1])
				ft_swap(s + i, s + i + 1);
			i++;
		}
	}
}

void	perm(char *s, int start, int end)
{
	if (start == end)
		puts(s);
	else
	{
		int i = start;
		while (i < end)
		{
			sort(s + start);
			ft_swap(s + start, s + i);
			perm(s, start + 1, end);
			ft_swap(s + start, s + i);
			i++;
		}
	}
}

int	main(int ac, char *av[])
{
	if (ac != 2)
		return 1;
	perm(av[1], 0, ft_strlen(av[1]));
	return 0;
}
