/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:32:16 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/27 08:34:43 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbadge.h"

void	add_to_garbadge(void *pointer)
{
	t_list	**garbage_head;
	t_list	*lst;

	garbage_head = get_garbage();
	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
	{
		free(pointer);
		safe_exit();
	}
	lst->content = pointer;
	lst->next = NULL;
	ft_lstadd_front(garbage_head, lst);
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
}

void	reset_garbadge(void)
{
	t_list	**garbage_head;

	garbage_head = get_garbage();
	if (!garbage_head || !*garbage_head)
		return ;
	*garbage_head = NULL;
}
