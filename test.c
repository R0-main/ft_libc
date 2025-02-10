/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:07:36 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 15:54:48 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbadge.h"

char	*weird_function(void)
{
	void	*s;

	create_safe_malloc_context();
	s = safe_malloc(1000);
	ft_strlcpy(s, "This is my text i want to save", 31);
	send_pointer_to_upper_context(s);
	exit_safe_malloc_context();
	return (s);
}

int	main(void)
{
	char	*s;

	s = weird_function();
	printf("%s\n", s);
	exit_safe_malloc_context();
}
