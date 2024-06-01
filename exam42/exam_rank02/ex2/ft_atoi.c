
int	ft_atoi(const char *str)
{
	int	i = 0;
	long	res = 0;
	int	sign = 1;
	
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	const char	*str = "	 \n+2147483647 ";
	printf("mine : %i\n", ft_atoi(str));
	printf("true : %i\n",atoi(str));
}
*/
