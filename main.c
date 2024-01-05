#include <stdio.h>
#include <string.h>

void	one(void *a)
{
	printf("one parameter: %s\n", (char *) a);
}

void	two(void *a, void *b)
{
	printf("two parameters: %s %s\n", (char *) a, (char *) b);
}

typedef struct s_func {
	void	(*f)();
	char	*s;
	int	p;
}	t_func;

void	define_func(t_func *func, void (*f)(), char *s, int p)
{
	func -> f = f;
	func -> s = s;
	func -> p = p;
}

int	main(int argc, char **argv)
{		
	int	i;
	t_func	func[3];

	if (argc < 2 || argc > 4)
		return (-1);
	define_func(&func[0], &one, "one", 1);
	define_func(&func[1], &two, "two", 2);
	define_func(&func[2], NULL, NULL, 0);
	i = 0;
	while (func[i].s)
	{
		if (!strncmp(func[i].s, argv[1], 5))
		{
			if (func[i].p == 1)
				func[i].f(argv[2]);
			else if (func[i].p == 2)
				func[i].f(argv[2], argv[3]);
		}
		i++;
	}
	return (0);
}
