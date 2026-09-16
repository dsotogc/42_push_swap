/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:44:39 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/16 16:25:33 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*src_c;
	size_t				i;

	i = 0;
	d = (unsigned char *)dest;
	src_c = (const unsigned char *)src;
	while (i < n)
	{
		d[i] = src_c[i];
		i++;
	}
	return (dest);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = ft_strlen(src);
	if (i + 1 < size)
		ft_memcpy(dst, src, i + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (i);
}

static char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*new_str;

	s_len = ft_strlen(s) + 1;
	new_str = malloc(s_len * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s, s_len);
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	real_len;
	char	*new_str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	real_len = ft_strlen(s + start);
	if (len < real_len)
		real_len = len;
	new_str = malloc(real_len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s + start, real_len + 1);
	return (new_str);
}
