/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/



/*
int		nbr_inbase(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)) || \
	(c >= 'a' && c <= ('a' + base - 10)));
}

int		ft_atoi_base(const char *str, int str_base)
{
	int		i;
	int		nbr;
	int		sign;

	if (!str[0] || (str_base < 2 || str_base > 16))
		return (0);
	nbr = 0;
	sign = 1;
	while (str[i] <= ' ') //whitespaces
		i++;
	if (str[0] == '-')
		sign = -1;
	while (str[i] && nbr_inbase(str[i], str_base))
	{
		if (str[i] >= 'A' && 'F' >= str[i])
			nbr = (nbr * str_base) + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && 'f' >= str[i])
			nbr = (nbr * str_base) + (str[i] - 'a' + 10);
		else
			nbr = (nbr * str_base) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
*/

int ft_isblank(char c)
{
	if (c <= ' ')
		return (1);
	return (0);
}

int		ft_isvalid(char c, int base)
{
	char digits[17] = "0123456789abcdef";
	char digits2[17] = "0123456789ABCDEF";

	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

int		ft_value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int result;
	int sign;

	result = 0;
	while (ft_isblank(*str))
		str++;
	sign = (*str == '-') ? -1 : 1; // if (*str == '-') then sign = -1 else sign = 1
	(*str == '-' || *str == '+') ? ++str : 0;
	while (ft_isvalid(*str, str_base))
		result = result * str_base + ft_value_of(*str++);
	return (result * sign);
}


/*
#include <stdio.h>

int	main()
{
	const char str[] = "1a";
	int	str_base = 16;
	
	printf("%i", ft_atoi_base(str, str_base));
	return (0);
}
*/
