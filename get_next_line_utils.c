#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    int		a;
    char	*sub;

    a = 0;
    if (!s)
        return (0);
    if ((len + 1) > ft_strlen((char *)s))
        len = ft_strlen((char *)s);
    if (len < 0)
        return (0);
    sub = (char *)malloc(len + 1);
    if (!sub)
        return (NULL);
    while (len > 0 && start < ft_strlen(s))
    {
        sub[a] = s[start];
        start++;
        a++;
        len--;
    }
    sub[a] = '\0';
    return (sub);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t			i;
    unsigned char	*destt;
    unsigned char	*srcc;

    destt = (unsigned char *)dst;
    srcc = (unsigned char *)src;
    i = 0;
    if (destt == 0 && srcc == 0)
        return (NULL);
    if (dst != src)
    {
        while (i < n)
        {
            destt[i] = srcc[i];
            i++;
        }
    }
    return (dst);
}

char	*ft_strjoin(char  *s1, char  *s2)
{
    char			*dst;
    unsigned int	i;
    unsigned int	j;

    if (!s1 || !s2)
        return (NULL);
    dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (dst == 0)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        dst[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
        dst[i++] = s2[j++];
    dst[i] = '\0';
    free(s1);
    return (dst);
}

int	ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char)c;
	while (s[i] != 0)
	{
		if (s[i] == cc)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (-2);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	ft_memcpy(s2, s1, ft_strlen(s1));
	*(s2 + ft_strlen(s1)) = '\0';
	return (s2);
}
