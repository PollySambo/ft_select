/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:10:20 by psambo            #+#    #+#             */
/*   Updated: 2018/09/21 10:07:08 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				ft_win_change(void)
{
	t_select	*tmp;

	tmp = ft_save_and_load(NULL, 1);
	ioctl(FILE_DS, TIOCGWINSZ, &(tmp->win));
	ft_save_and_load(tmp, 0);
	ft_print_list(tmp);
}

static void			ft_handle(int num)
{
	t_select	*select;
	char		ch[2];

	if (num == SIGINT)
		ft_exit();
	else if (num == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		select = ft_save_and_load(NULL, 1);
		ft_reset_term_behavior(&(select->term));
		ch[0] = select->term.c_cc[VSUSP];
		ch[1] = '\0';
		ioctl(0, TIOCSTI, ch);
	}
	else if (num == SIGCONT)
	{
		signal(SIGTSTP, ft_handle);
		select = ft_save_and_load(NULL, 1);
		ft_change_term_behavior(&(select->term));
		ft_print_list(select);
	}
	else if (num == SIGWINCH)
		ft_win_change();
	else
		ft_exit();
}

void				ft_handle_signals(void)
{
	int	i;

	i = 1;
	while (i <= 31)
	{
		signal(i, ft_handle);
		i++;
	}
}
