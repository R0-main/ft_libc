/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:31:08 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/28 12:32:50 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbadge.h"

void	safe_free(void *pointer)
{
	t_list	*lst;
	t_list	*prev;
	t_list	**garbage_head;

	garbage_head = get_garbage();
	if (!garbage_head || !*garbage_head)
		return ;
	lst = *garbage_head;
	prev = NULL;
	while (lst)
	{
		if (lst->content == pointer)
		{
			if (prev)
				prev->next = lst->next;
			free(lst);
			break ;
		}
		prev = lst;
		lst = lst->next;
	}
	free(pointer);
}

void	free_garbadge(void)
{
	t_list	*tmp;
	t_list	*lst;
	t_list	**garbage_head;

	garbage_head = get_garbage();
	if (!garbage_head || !*garbage_head)
		return ;
	lst = *garbage_head;
	while (lst)
	{
		tmp = lst->next;
		if (lst->content)
			free(lst->content);
		lst->content = NULL;
		free(lst);
		lst = tmp;
	}
	*garbage_head = NULL;
}
