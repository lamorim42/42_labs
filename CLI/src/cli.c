/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:35:02 by lamorim           #+#    #+#             */
/*   Updated: 2022/02/24 19:50:08 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_init_data(argc, argv, &data);
	ft_check_args(&data);
	ft_count(&data);
	ft_chose_printf(&data);
	return (0);
}
