/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:34:46 by lamorim           #+#    #+#             */
/*   Updated: 2022/02/24 19:52:09 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

void	ft_printf_all(t_data *data)
{
	printf("--------------------------------------------\n");
	printf("| Total Requests | HTTP Method |   Path    |\n");
	printf("--------------------------------------------\n");
	printf("|    %6d      |     GET     |     /     |\n", \
	data->get_c[GET_SLASH]);
	printf("--------------------------------------------\n");
	printf("|    %6d      |     GET     |  /secret  |\n", \
	data->get_c[GET_SECRET]);
	printf("--------------------------------------------\n");
	printf("|    %6d      | All methods | all paths |\n", data->all);
	printf("--------------------------------------------\n");
}

void	ft_printf_all_log(t_data *data)
{
	data->file = fopen(FILE_LOG, "r");
	if (data->file == NULL)
		exit(1);
	while (fgets(data->buffer, SIZE, data->file))
		printf("%s", data->buffer);
	fclose(data->file);
}

void	ft_printf_get(t_data *data)
{
	printf("--------------------------------------------\n");
	printf("| Total Requests | HTTP Method |   Path    |\n");
	printf("--------------------------------------------\n");
	printf("|    %6d      |     GET     |     /     |\n", \
	data->get_c[GET_SLASH]);
	printf("--------------------------------------------\n");
	printf("|    %6d      |     GET     |  /secret  |\n", \
	data->get_c[GET_SECRET]);
	printf("--------------------------------------------\n");
}

void	ft_printf_get_slash(t_data *data)
{
	printf("--------------------------------------------\n");
	printf("| Total Requests | HTTP Method |   Path    |\n");
	printf("--------------------------------------------\n");
	printf("|    %6d      |     GET     |     /     |\n", \
	data->get_c[GET_SLASH]);
	printf("--------------------------------------------\n");
}

void	ft_printf_get_secret(t_data *data)
{
	printf("--------------------------------------------\n");
	printf("| Total Requests | HTTP Method |   Path    |\n");
	printf("--------------------------------------------\n");
	printf("|    %6d      |     GET     |  /secret  |\n", \
	data->get_c[GET_SECRET]);
	printf("--------------------------------------------\n");
}

void	ft_printf_help(void)
{
	printf("\n\e[1;31mBad command!\e[0m\n");
	printf("\e[1;37mValid commands:\e[0m\n");
	printf("\e[1;32m\t./my_cli all   :\e[0m to see all informations\n");
	printf("\e[1;32m\t./my_cli GET   :\e[0m to see informations");
	printf(" about GET method\n");
	printf("\e[1;32m\t./my_cli GET / :\e[0m to see informations");
	printf(" about GET method on / endpoint\n");
	exit(1);
}

void	ft_chose_printf(t_data *data)
{
	if (data->arg_c == 2)
	{
		if (!strncmp(data->arg_v[1], "all", 3))
			ft_printf_all(data);
		else if (!strncmp(data->arg_v[1], "GET", 3))
			ft_printf_get(data);
		else
			ft_printf_help();
	}
	else if (data->arg_c == 3)
	{
		if (!strcmp(data->arg_v[1], "GET") && \
			!strcmp(data->arg_v[2], "/"))
			ft_printf_get_slash(data);
		else if (!strcmp(data->arg_v[1], "GET") && \
				!strcmp(data->arg_v[2], "/secret"))
			ft_printf_get_secret(data);
		else if (!strcmp(data->arg_v[1], "all") && \
				!strcmp(data->arg_v[2], "log"))
			ft_printf_all_log(data);
		else
			ft_printf_help();
	}
}