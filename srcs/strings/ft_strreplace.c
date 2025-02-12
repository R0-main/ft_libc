/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:06:24 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/12 15:03:50 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strreplace(char *str, char *mask, char *value)
{
	char	*result;
	size_t	i;
	size_t	y;
	size_t	k;

	i = 0;
	y = 0;
	k = 0;
	if (!str || !mask || !value)
		return (NULL);
	result = safe_malloc((ft_strlen(str) - ft_strlen(mask)) + ft_strlen(value)
			+ 1);
	while (str[i] && ft_strncmp(&str[i], mask, ft_strlen(mask)) != 0)
		result[k++] = str[i++];
	i += ft_strlen(mask);
	while (value[y])
		result[k++] = value[y++];
	while (str[i])
		result[k++] = str[i++];
	result[k] = 0;
	return (result);
}
