/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:11:51 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 16:15:42 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbadge.h"

int	*get_current_context(void)
{
	static int	context = 0;

	return (&context);
}

void	create_safe_malloc_context(void)
{
	int	*context;

	context = get_current_context();
	if (!context)
		return ;
	(*context)++;
}

void	exit_safe_malloc_context(void)
{
	int	*context;

	context = get_current_context();
	if (!context)
		return ;
	free_garbadge(*context);
	(*context)--;
}

void	send_pointer_to_upper_context(void *ptr)
{
	int	*context;

	context = get_current_context();
	if (!context)
		return ;
	if (*context < 1)
		return ;
	add_to_garbadge(ptr, *context - 1);
	delete_from_context(ptr, *context);
}
