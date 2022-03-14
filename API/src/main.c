/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:34:29 by lamorim           #+#    #+#             */
/*   Updated: 2022/02/27 00:27:08by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "api.h"

int	g_sig = 0;

static void	ft_sig_stop(int sign)
{
	printf("\nBye!\n");
	sign = 1;
	g_sig = sign;
}

static int	ft_check_method(const char *mth)
{
	if (strstr(mth, "GET"))
		return 0;
	return 1;
}

static void ft_handle_event(struct mg_connection *conet, int ev, void *ev_data, void *fn_data)
{
	t_replay	*replay;

	replay = malloc(sizeof(t_replay));
	replay->filename = LOG;
	replay->conet = conet;
	if (ev == MG_EV_HTTP_MSG)
	{
		replay->s_http = (struct mg_http_message *) ev_data;
		if (!ft_check_method(replay->s_http->method.ptr))
		{
			if (mg_http_match_uri(replay->s_http, "/"))
				ft_replay_home(replay);
			else if (mg_http_match_uri(replay->s_http, "/secret"))
				ft_replay_secret(replay);
			else
				ft_replay_nf(replay);
		}
		else
			ft_replay_ni(replay);
	}
	(void)fn_data;
	free(replay);
}

int main(void)
{
	struct mg_mgr	data;

	printf("API up!\n");
	signal(SIGINT, ft_sig_stop);
	mg_mgr_init(&data);
	mg_http_listen(&data, HOST_HTTP, ft_handle_event, &data);
	while (!g_sig)
		mg_mgr_poll(&data, 1000);
	mg_mgr_free(&data);
	return 0;
}
