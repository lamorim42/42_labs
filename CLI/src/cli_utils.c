/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:34:51 by lamorim           #+#    #+#             */
/*   Updated: 2022/02/24 19:51:49 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

void	ft_count(t_data *data)
{
	data->file = fopen(FILE_LOG, "r");
	if (data->file == NULL)
		exit(1);
	while (fgets(data->buffer, SIZE, data->file))
	{
		if (strstr(data->buffer, "GET / "))
			data->get_c[GET_SLASH]++;
		if (strstr(data->buffer, "GET /secret"))
			data->get_c[GET_SECRET]++;
		data->all++;
	}
	fclose(data->file);
}

int	ft_check_args(t_data *data)
{
	if (data->arg_c < 2 || data->arg_c > 3)
		ft_printf_help();
	else if (data->arg_c == 2)
	{
		if (!strncmp(data->arg_v[1], "all", 3) && \
			!strncmp(data->arg_v[1], "GET", 3))
			ft_printf_help();
	}
	else if (data->arg_c == 3)
	{
		if (!strncmp(data->arg_v[1], "all", 3) && \
			!strncmp(data->arg_v[1], "GET", 3) && \
			!strncmp(data->arg_v[2], "/", 1) && \
			!strncmp(data->arg_v[2], "/secret", 7))
			ft_printf_help();
	}
	return (0);
}

void	ft_init_data(int arg_c, char **arg_v, t_data *data)
{
	data->arg_c = arg_c;
	data->arg_v = arg_v;
	data->all = 0;
	data->get_c[GET_SLASH] = 0;
	data->get_c[GET_SECRET] = 0;
}
