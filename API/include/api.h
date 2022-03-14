/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:35:31 by lamorim           #+#    #+#             */
/*   Updated: 2022/02/27 02:40:29 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef API_H
# define API_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <signal.h>
# include <mysql/mysql.h>
# include "mongoose.h"

# define LOG "./log/server.log"

# define HOST_HTTP "0.0.0.0:8000"

typedef struct s_replay {
	struct mg_connection	*conet;
	struct mg_http_message	*s_http;
	const char				*filename;
	int						status;
}							t_replay;

typedef struct s_db
{
	MYSQL		*con;
	MYSQL_ROW	row;
	MYSQL_RES	*result;
	char		*str;
}				t_db;

char	*ft_peck_form_db(void);
void	ft_replay_home(t_replay *replay);
void	ft_replay_secret(t_replay *replay);
void	ft_replay_nf(t_replay *replay);
void	ft_replay_ni(t_replay *replay);

#endif