#include "minirt.h"

size_t	ft_strlen(const char *pointer)
{
	size_t counter;

	counter = 0;
	while (pointer[counter] != '\0')
		counter++;
	return (counter);
}

int		ft_isdigit(int argument)
{
	if (argument >= 48 && argument <= 57)
		return (1);
	if (argument == '-')
		return (1);
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pointerdest;
	unsigned char	*pointersource;

	pointerdest = dest;
	pointersource = (unsigned char*)src;
	if (pointerdest == 0 && pointersource == 0)
		return (dest);
	while (n-- > 0)
		*pointerdest++ = *pointersource++;
	return (dest);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s) + 1;
	dup = malloc(sizeof(char) * len);
	if (dup)
		ft_memcpy(dup, s, len);
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	if (s == 0)
		return (0);
	sub = malloc((len + 1) * sizeof(char));
	if (sub == 0)
		return (0);
	i = 0;
	while ((i < len) && (start < ft_strlen(s)))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static char		*joinstrings(char *pointer, char const *s1, char const *s2)
{
	int counter;

	counter = 0;
	while (*s1 != '\0')
		pointer[counter++] = *s1++;
	while (*s2 != '\0')
		pointer[counter++] = *s2++;
	pointer[counter] = '\0';
	return (pointer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	lens1;
	unsigned int	lens2;
	char			*pointer;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	pointer = malloc((lens1 + lens2) + sizeof(char));
	if (pointer == 0)
		return (0);
	return (joinstrings(pointer, s1, s2));
}
