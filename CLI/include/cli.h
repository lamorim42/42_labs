/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:35:06 by lamorim           #+#    #+#             */
/*   Updated: 2022/02/27 00:52:31 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define FILE_LOG "./API/log/server.log"
# define GET_SLASH 0
# define GET_SECRET 1
# define SIZE 50

typedef struct s_data {
	int		arg_c;
	char	**arg_v;
	FILE	*file;
	char	buffer[SIZE];
	int		get_c[2];
	int		all;
}			t_data;

//cli_printf
void	ft_chose_printf(t_data *data);
void	ft_printf_help(void);
void	ft_printf_all(t_data *data);
void	ft_printf_get(t_data *data);
void	ft_printf_get_slash(t_data *data);
void	ft_printf_get_secret(t_data *data);

//cli_utils
void	ft_count(t_data *data);
int		ft_check_args(t_data *data);
void	ft_init_data(int arg_c, char **arg_v, t_data *data);

#endif