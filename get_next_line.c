/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:59:23 by tclaereb          #+#    #+#             */
/*   Updated: 2023/12/08 19:56:24 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	int		i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstlen >= size)
		return (size + srclen);
	while (src[i] != '\0' && (dstlen + i) < (size - 1))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s;
	size_t	ls1;
	size_t	ls2;

	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	s = (char *)malloc((ls1 + ls2) * sizeof(char));
	if (!s)
		return (NULL);
	ft_strlcat(s, s1, ls1 + 1);
	ft_strlcat(s + ls1, s2, ls2 + 1);
	free(s1);
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	i;
	char	*new_s;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen || len == 0)
		return (NULL);
	new_s = malloc(len * sizeof(char));
	i = 0;
	while (i < len)
	{
		new_s[i] = s[i];
		i++;
	}
	return (new_s);
}

ssize_t	read_file(int fd, char *ptr)
{
	char	*buff;
	ssize_t	i;

	buff = malloc(BUFFER_SIZE * sizeof(char));
	if (!buff)
		return (-1);
	i = read(fd, buff, BUFFER_SIZE);
	if (i == -1)
		return (-1);
	ft_strjoin(ptr, buff);
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*return_ptr;
	char		*buff;
	ssize_t		i;

	if (!ptr)
	{
		ptr = malloc(BUFFER_SIZE * sizeof(char));
		if (!ptr)
			return (NULL);
		i = read(fd, ptr, BUFFER_SIZE);		
	}
	else
	{
		while (!ft_strchr(ptr, '\n'))
		{
			i = read_file(fd, ptr);
			if (i == -1)
			{
				free(ptr);
				return (NULL);
			}
			else if (i == 0)
				break ;
		}
	}
	i = ft_strchr(ptr, '\n') - ptr;
	if (!i)
		i = ft_strlen(ptr);
	return_ptr = ft_substr(ptr, 0, i);
	if (!return_ptr)
	{
		free(ptr);
		return (NULL);
	}
	buff = ft_substr(ptr, i + 1, ft_strlen(ptr));
	if (!buff)
	{
		free(ptr);
		free(return_ptr);
		return (NULL);
	}
	free(ptr);
	ptr = buff;
	return (return_ptr);
}
