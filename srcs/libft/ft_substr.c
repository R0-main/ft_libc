/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/21 11:41:55 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	s_start_len;
	char	*result;

	i = -1;
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else
	{
		s_start_len = ft_strlen(s + start);
		if (len > s_start_len)
			len = s_start_len;
	}
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	while (s[++i] && i < len)
		result[i] = s[i + start];
	result[i] = 0;
	return (result);
}
