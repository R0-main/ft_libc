/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:31:08 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 16:25:01 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbadge.h"

void	safe_free(void *pointer)
{
	int	*context;

	context = get_current_context();
	if (!context)
		return ;
	if (!delete_from_context(pointer, *context))
		return ;
	free(pointer);
}

bool	delete_from_context(void *pointer, int context)
{
	t_list	*lst;
	t_list	*prev;
	t_list	*next;
	t_list	**garbage_head;
	bool	deleted;

	deleted = false;
	if (context < 0 || context >= CONTEXT_MAX)
		return (true);
	garbage_head = get_garbage_from_context(context);
	if (!garbage_head || !*garbage_head)
		return (true);
	lst = *garbage_head;
	prev = NULL;
	while (lst)
	{
		next = lst->next;
		if (lst->content == pointer)
		{
			if (prev)
				prev->next = lst->next;
			else
				*garbage_head = NULL;
			deleted = true;
			free(lst);
		}
		prev = lst;
		lst = next;
	}
	return (deleted);
}

void	free_garbadge(int context)
{
	t_list	*tmp;
	t_list	*lst;
	t_list	**garbage_head;

	if (context < 0 || context >= CONTEXT_MAX)
		return ;
	garbage_head = get_garbage_from_context(context);
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
