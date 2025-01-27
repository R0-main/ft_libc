/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:31:08 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/27 08:34:37 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbadge.h"

void	*safe_malloc(size_t size)
{
	void	*memory;
	t_list	*lst;

	memory = malloc(size);
	if (!memory)
		safe_exit();
	add_to_garbadge(memory);
	return (memory);
}
