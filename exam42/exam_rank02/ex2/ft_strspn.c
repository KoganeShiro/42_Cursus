
//La fonction strspn() calcule la longueur du segment initial
//de s qui ne contient que des caractères présents dans accept.


#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i = 0;
	size_t	j = 0;

	while (s[i] != '\0')
	{
		if (ft_strchr(accept, s[i]) == 0)
			break;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main()
{
	const char	*s;
	const char	*accept;
	
	s = "Hello, World";
	accept = "Hey, world";
	printf("%lu\n", ft_strspn(s, accept));
	printf("%lu", strspn(s, accept));
	return (0);
}
*/
