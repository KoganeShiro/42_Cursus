
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int	i;
	char	*dup;
	
	i = 0;
	while (src[i] != '\0')
		i++;
	dup = malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	*src;
	const char *str;
	
	src = "Hello, World !";
	str = src;
	printf("%s\n", ft_strdup(src));
	printf("%s", strdup(str));
	return (0);
}
*/
