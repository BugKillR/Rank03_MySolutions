#include <stdio.h>
#include <unistd.h>

int	is_valid(char	*s)
{
	int	open = 0;
	int close = 0;

	while (*s)
	{
		if (*s == '(')
			open++;
		else if (*s == ')')
		{
			if (open > 0)
				open--;
			else
				close++;
		}
		s++;
	}
	return (open + close);
}

void rip(char *s, int to_fix, int fixed, int i)
{
	char	c;

	if (to_fix == fixed && !is_valid(s))
	{
		puts(s);
		return ;
	}
	if (fixed > to_fix)
		return ;
	while (s[i])
	{
		if (s[i] == '(' || s[i] == ')')
		{
			c = s[i];
			s[i] = ' ';
			rip(s, to_fix, fixed + 1, i + 1);
			s[i] = c;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;
	rip(argv[1], is_valid(argv[1]), 0, 0);
	return 0;
}
