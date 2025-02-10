/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:07:36 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 16:26:16 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbadge.h"

char	**weird_function(void)
{
	char	**s;
	void	*t;
	int		i;

	i = 0;
	create_safe_malloc_context();
	t = safe_malloc(1000);
	ft_strlcpy(t, "This is my text i want to save", 31);
	s = ft_split("fwqfq fqf wqf qf qwfqwf qwf qwf wqf qwf qwf qwfq  fwfqfq fqwf qfq fwq", ' ');
	while (s[i])
	{
		send_pointer_to_upper_context(s[i++]);
	}
	send_pointer_to_upper_context(s);
	send_pointer_to_upper_context(s);
	send_pointer_to_upper_context(s);
	exit_safe_malloc_context();
	return (s);
}

// TODO : rework the free_garbadge for double_free errors

int	main(void)
{
	char	**s;
	int		i;

	i = 0;
	s = weird_function();
	while (s[i])
	{
		printf("%s\n", s[i++]);
	}
	exit_safe_malloc_context();
}
