/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:11:40 by psambo            #+#    #+#             */
/*   Updated: 2018/09/21 10:09:40 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_exit(void)
{
	t_select	*out;

	out = ft_save_and_load(NULL, 1);
	ft_free_mem(out);
	ft_reset_term_behavior(&(out->term));
	exit(0);
}
