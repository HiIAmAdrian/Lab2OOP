#include <stdlib.h>
#include <string.h>

char* ft_strdup(const char* s1)
{
	char* copy;
	int		i;

	i = 0;
	if ((copy = (char*)malloc(sizeof(char) * (strlen(s1) + 1))))
	{
		while (s1[i])
		{
			copy[i] = s1[i];
			i++;
		}
		copy[i] = 0;
		return (copy);
	}
	if (copy)
		free(copy);
	return (NULL);
}