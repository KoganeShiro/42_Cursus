
//La fonction strcspn() calcule la longueur du 
//segment initial de s qui ne contient que des caractères absents de reject.  

#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	len;
	size_t	i;
	
	len = 0;
	i = 0;
	while (s[len] != '\0')
	{
		i = 0;
		while (reject[i] != '\0')
		{
			if (s[len] == reject[i])
				return (len);
			i++;
		}
		len++;
	}
	return (len);
}
/*
#include <stdio.h>

int	main()
{
	char	*str;
	char	*reject;
	
	str = "hello world";
	reject = "ewor";
	printf("%lu\n", ft_strcspn(str, reject));
	printf("%lu", strcspn(str, reject));
	return (0);
}
*/
