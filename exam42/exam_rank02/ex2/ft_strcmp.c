
int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (s1[i] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

/*
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		*s1++;
		*s2++;
	}
	return (*s1 - *s2);
}
*/
