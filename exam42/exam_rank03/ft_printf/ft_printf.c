
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_format(va_list args, char format);
int	print_char(const char c);
int	print_str(const char *str);
int	print_nbr(int n);
int	print_hex(unsigned long nb);
int	ft_printf(const char *str, ...);

/*
int	main()
{
	int hex = 0;
	int age = 0;
	char *name = NULL;
	int len = ft_printf("hello %s, you are %d, which in hex is %x\n", name, age, hex);
	int len2 = printf("hello %s, you are %d, which in hex is %x\n", name, age, hex);
	printf("\nlen: %d\n", len);
	printf("len2: %d\n", len2);
	return (0);
}
*/

int	ft_printf(const char *str, ...)
{
	int	i = 0;
	int	len = 0;
	va_list args;
	va_start(args, str);

	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			len += ft_format(args, str[i + 1]);
			i++;
		}
		else
			len += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	ft_format(va_list args, const char format)
{
	int	len = 0;
	if (format == 's')
		len += print_str(va_arg(args, const char *));
	else if (format == 'd')
		len += print_nbr(va_arg(args, int));
	else if (format == 'x')
		len += print_hex(va_arg(args, unsigned int));
	return (len);
}

int	print_char(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(const char *str)
{
	int	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_nbr(int n)
{
	int	len = 0;
	long nb = n;
	if (nb < 0)
	{
		len += print_char('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		len += print_nbr(nb / 10);
		len += print_char(nb % 10 + '0');
	}
	else
		len += print_char(nb % 10 + '0');
	return (len);
}

int	print_hex(unsigned long nb)
{
	char base[16] = "0123456789abcdef";
	int len = 0;
	if (nb / 16)
	{
		len += print_hex(nb / 16);
		len += print_char(base[nb % 16]);
	}
	else
		len += print_char(base[nb % 16]);
	return (len);
}
