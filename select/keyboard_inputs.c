/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:10:07 by psambo            #+#    #+#             */
/*   Updated: 2018/09/22 15:31:17 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		up_cursor(t_pick *pick)
{
	int		current;
	int		max;
	int		min;

	current = pick->pos;
	max = pick->n_items;
	min = 0;
	if (current == min)
		pick->pos = max - 1;
	else
		pick->pos = pick->pos - 1;
	ft_save_and_load(pick, 0);
	ft_print_list(pick);
}

void		enter(t_pick *pick)
{
	int	i;

	i = 0;
	reset_iterm(&(pick->term));
	while (pick->n_items > i)
	{
		if ((pick->selected)[i] == 1)
		{
			ft_putstr_fd((pick->items)[i], 1);
			ft_putchar_fd(' ', 1);
		}
		i++;
	}
	ft_putchar_fd('\n', 1);
	exit(0);
}

void		down_cursor(t_pick *pick)
{
	int		current;
	int		max;
	int		min;

	current = pick->pos;
	max = pick->n_items;
	min = 0;
	if (current == (max - 1))
		pick->pos = min;
	else
		pick->pos = pick->pos + 1;
	ft_save_and_load(pick, 0);
	ft_print_list(pick);
}

void		ft_select_item(t_pick *pick)
{
	int		pos;

	pos = pick->pos;
	if (pick->selected[pos] == 1)
		pick->selected[pos] = -1;
	else
		pick->selected[pos] = 1;
	if (pick->pos == pick->n_items - 1)
		pick->pos = 0;
	else
		pick->pos += 1;
	ft_save_and_load(pick, 0);
	ft_print_list(pick);
}

void		keyboard(void)
{
	char	key[5];

	key[4] = '\0';
	while (1)
	{
		ft_clear(key);
		read(0, key, 4);
		if (key[0] == 27 && key[1] == '\0' && key[2] == '\0')
			return ;
		else if (key[0] == 27 && key[1] == 91 && key[2] == 'A')
			up_cursor(ft_save_and_load(NULL, 1));
		else if (key[0] == 27 && key[1] == 91 && key[2] == 'B')
			down_cursor(ft_save_and_load(NULL, 1));
		else if (key[0] == 32 && key[1] == '\0' && key[2] == '\0')
			ft_select_item(ft_save_and_load(NULL, 1));
		else if (key[0] == 10 && key[1] == '\0' && key[2] == '\0')
			enter(ft_save_and_load(NULL, 1));
		/*else if (key[0] == 127 && key[1] == '\0' && key[2] == '\0')
			ft_remove_item(ft_save_and_load(NULL, 1));
		else if (key[0] == 27 && key[1] == 91 && key[2] == 51)
			ft_remove_item(ft_save_and_load(NULL, 1));*/
	}
}
