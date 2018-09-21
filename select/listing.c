/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:11:54 by psambo            #+#    #+#             */
/*   Updated: 2018/09/21 13:41:38 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_free_mem(t_select *select)
{
	int	i;

	i = 0;
	while ((select->items)[i] != '\0')
	{
		free((select->items)[i]);
		i++;
	}
	free(select->items);
	free(select->selected);
}

int			ft_get_longest_item(t_select *select)
{
	int		j;
	int		length;
	int		i;

	j = 0;
	if (select->n_items <= 0)
		return (0);
	length = strlen((select->items)[0]);
	while ((select->items)[j] != '\0')
	{
		i = strlen((select->items)[j]);
		if (length <= i)
			length = i;
		j++;
	}
	return (length);
}

static int	ft_check_winsize(t_select *select)
{
	int		i;

	i = ft_get_longest_item(select);
	if (select->win.ws_row <= select->n_items || select->win.ws_col <= i)
	{
		if (select->win.ws_row <= select->n_items)
			ft_put_endl("* Window height is too small.");
		if (select->win.ws_col <= i)
			ft_put_endl("* Window width is too small.");
		return (-1);
	}
	return (1);
}

void		ft_print_list(t_select *select)
{
	int	i;

	i = 0;
	ft_clear_terminal();
	if (ft_check_winsize(select) == -1)
		return ;
	while ((select->items)[i] != '\0')
	{
		if (select->pos == i)
		{
			//if (select->selected[i] == 1)
			//	ft_put_underline_highlight((select->items)[i], ft_put_yellow);
				ft_put_underline((select->items)[i], ft_put_yellow);
		}
		else
		{
			if (select->selected[i] == 1)
				ft_put_highlight((select->items)[i], ft_put_yellow);
			else
				ft_put_endl((select->items)[i]);
		}
		i++;
	}
}

void		ft_add_list(t_select *select, int n, char **list)
{
	int	i;

	i = 0;
	select->items = (char**)malloc(sizeof(char*) * (n + 1));
	select->selected = (int*)malloc(sizeof(int) * (n + 1));
	if (select->items == NULL || select->selected == NULL)
		return ;
	(select->items)[n] = (char*)'\0';
	(select->selected)[n] = (int)'\0';
	select->n_items = n;
	select->pos = 0;
	while (i < n)
	{
		(select->items)[i] = ft_strdup(list[i]);
		i++;
	}
	ioctl(FILE_DS, TIOCGWINSZ, &(select->win));
}
