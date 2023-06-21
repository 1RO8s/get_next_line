/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:12:36 by hnagasak          #+#    #+#             */
/*   Updated: 2023/06/16 09:50:50 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void *show_malloc_address(size_t size, const char *file, unsigned int line)
{
	void *p;
	p = malloc(size);
	printf("\n## %s[%d]: malloc(%p)\n",file,line,p);
	return p;
}

#define malloc(s) show_malloc_address(s, __FILE__, __LINE__) 

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	i = 0;
	if (dstsize <= 0)
		return (srclen);
	while (i + 1 < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2 != NULL)
		ft_strlcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}

static size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*start;
	size_t	i;
	size_t	dstlen;

	if (dst == NULL && dstsize != 0)
		return (ft_strlen(NULL));
	if (dst == NULL)
		dstlen = 0;
	else
		dstlen = ft_strlen(dst);
	start = dst;
	while (start != NULL && *start != '\0')
		start++;
	i = 0;
	while (dstlen + i + 1 < dstsize && src[i] != '\0')
	{
		start[i] = src[i];
		i++;
	}
	if (dst != NULL)
		start[i] = '\0';
	if (dstlen < dstsize)
		return (dstlen + ft_strlen(src));
	else
		return (dstsize + ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	else if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * (len + 1));
	if (s3 != NULL)
	{
		ft_strlcpy(s3, s1, len + 1);
		ft_strlcat(s3, s2, len + 1);
	}
	return (s3);
}
