/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_arg_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 04:24:43 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/06 05:56:33 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_arg		**ft_link_arg_lst(t_arg **arg_lst)
{
	t_arg	*tmp;
	t_arg	*start;

	start = *arg_lst;
	(*arg_lst)->prev = NULL;
	while ((*arg_lst)->next)
	{
		tmp = (*arg_lst);
		(*arg_lst) = (*arg_lst)->next;
		(*arg_lst)->prev = tmp;
	}
	arg_lst = &start;
	return (arg_lst);
}

t_arg		*new_arg(char *name, t_arg *nxt_elem)
{
	t_arg		*new;

	if (!(new = (t_arg *)malloc(sizeof(t_arg))))
		exit(-1);
	ft_memcpy(new->name, name, ft_strlen(name) + 1);
	new->next = nxt_elem;
	return (new);
}

void		ft_unlink_arg(t_arg **arg)
{
	t_arg *tmp;

	tmp = *arg;
	if (tmp->prev)
		(tmp->prev)->next = tmp->next;
	if (tmp->next)
		(tmp->next)->prev = tmp->prev;
}

t_arg		**ft_insert_arg(t_arg **arg, t_arg **arg_place, char option)
{
	if (option == 'G')
	{
		(*arg)->next = *arg_place;
		(*arg)->prev = (*arg_place)->prev;
		if ((*arg_place)->prev)
			((*arg_place)->prev)->next = *arg;
		(*arg_place)->prev = *arg;
	}
	else
	{
		(*arg)->next = (*arg_place)->next;
		(*arg)->prev = *arg_place;
		if ((*arg_place)->next)
			((*arg_place)->next)->prev = *arg;
		(*arg_place)->next = *arg;
	}
	return (arg);
}
