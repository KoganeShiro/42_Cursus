/*/ 	la fonction strpbrk est assez proche de la fonction strchr.
La différence réside dans le fait que la fonction strchr recherche la première occurrence d'un caractère unique
alors que strpbrk recherche la première occurrence d'un caractère parmi une liste de caractères (s2) à rechercher.
	Si la fonction trouve un des caractères recherchés dans la chaîne,
elle renvoie un pointeur vers le premier caractère de la liste rencontré. Dans le cas contraire, la fonction renvoie un pointeur nul (NULL).
/*/

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (0);
}
/*

#include <stdio.h>
#include <string.h>

int	main()
{
	const char	*s1;
	const char	*s2;
	
	s1 = "Hello, World !";
	s2 = "! e";
	printf("%s\n", ft_strpbrk(s1, s2));
	printf("%s", strpbrk(s1, s2));
}
*/
