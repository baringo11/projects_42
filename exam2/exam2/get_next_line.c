#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	len;
	
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	unsigned int		pos;

	if (!s || !c)
		return (NULL);
	pos = 0;
	while (s[pos])
	{
		if (s[pos] == c)
			return (&s[pos]);
		pos++;
	}
	return(NULL);
}

char	*ft_strjoin(char *s, char *p)
{
	int		pos;
	char	*dest;

	if (!(dest = malloc(ft_strlen(s) + ft_strlen(p) + 1)))
		return (NULL);
	pos = 0;
	while (*s)
		dest[pos++] = *s++;
	while (*p)
		dest[pos++] = *p++;
	dest[pos] = '\0';
	return (dest);
}

char	*ft_strdup(char *s)
{
	int		pos;
	char	*dup;

	if (!(dup = malloc(ft_strlen(s) + 1)))
		return (NULL);
	pos = 0;
	while (s[pos])
	{
		dup[pos] = s[pos];
		pos++;
	}
	dup[pos] = 0; 
	return (dup);
}

int		get_next_line(char **line)
{
	static char	*text;
	char		buff[513];
	char		*temp, *temp2;
	int			t_read;

	if (!line)
		return (-1);
	while (ft_strchr(text, '\n') == NULL)
	{
		t_read = read(0, buff, 512);
		if (t_read < 0)
			return (-1);
		else if (!t_read)
			break;
		buff[t_read] = 0;
		if (!text)
			text = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(text, buff);
			free(text);
			text = temp;
		}
	}
	if (!t_read && !text)
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((temp = ft_strchr(text, '\n')))
	{
		*temp = 0;
		*line = ft_strdup(text);
		temp2 = ft_strdup(++temp);
		free(text);
		text = temp2;
	}
	else
	{
		*line = ft_strdup(text);
		free(text);
		text = NULL;
		return (0);
	}
	return (1);
}
