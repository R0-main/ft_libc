/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:31:08 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 14:29:45 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbadge.h"

void	*safe_malloc(size_t size)
{
	void	*memory;
	int		*context;

	memory = malloc(size);
	if (!memory)
		safe_exit();
	context = get_current_context();
	if (!context)
		safe_exit();
	add_to_garbadge(memory, *context);
	return (memory);
}
