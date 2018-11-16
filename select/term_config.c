/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:10:43 by psambo            #+#    #+#             */
/*   Updated: 2018/09/22 15:29:42 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	clear_iterm(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_putchar);
}

int		change_iterm(struct termios *term)
{
	if (tgetent(NULL, getenv("TERM")) == -1)
		return (-1);
	if (tcgetattr(FILE_DS, term) == -1)
		return (-1);
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(FILE_DS, TCSANOW, term) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 1, ft_putchar);
	tputs(tgetstr("vi", NULL), 1, ft_putchar);
	return (0);
}

int		reset_iterm(struct termios *term)
{
	tputs(tgetstr("ve", NULL), 1, ft_putchar);
	tputs(tgetstr("te", NULL), 1, ft_putchar);
	term->c_lflag |= (ICANON | ECHO);
	if ((tcsetattr(FILE_DS, TCSANOW, term)) == -1)
		return (-1);
	return (0);
}
