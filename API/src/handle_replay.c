/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_replay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 00:22:24 by lamorim           #+#    #+#             */
/*   Updated: 2022/02/27 03:39:17 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "api.h"

static void	log_message(t_replay *replay)
{
	FILE	*fp;
	time_t	curtime;

	fp = fopen(replay->filename, "a");
	if (!fp)
		return ;
	time(&curtime);
	fprintf(fp, "%.*s ", (int)replay->s_http->method.len, \
	replay->s_http->method.ptr);
	fprintf(fp, "%.*s ", (int)replay->s_http->uri.len, \
	replay->s_http->uri.ptr);
	fprintf(fp, "%d ", replay->status);
	fprintf(fp, "%s", ctime(&curtime));
	fclose(fp);
}

void	ft_replay_home(t_replay *replay)
{
	mg_http_reply(replay->conet, 200, \
	"Content-Type: application/json\r\n\
connection: close\r\n\
Allow: GET\r\n", \
	"{\"result\": %s}", "\"home\"");
	replay->status = 200;
	log_message(replay);
}

void	ft_replay_secret(t_replay *replay)
{
	char *str;

	str = ft_peck_form_db();
	mg_http_reply(replay->conet, 200, \
	"Content-Type: application/json\r\n\
connection: close\r\n\
Allow: GET\r\n", \
	"%s", str);
	free(str);
	replay->status = 200;
	log_message(replay);
}

void	ft_replay_nf(t_replay *replay)
{
	mg_http_reply(replay->conet, 404, \
	"Content-Type: application/json\r\n\
connection: close\r\n\
Allow: GET\r\n", \
	"{\"result\": %s}", "\"Not found...\"");
	replay->status = 404;
	log_message(replay);
}

void	ft_replay_ni(t_replay *replay)
{
	mg_http_reply(replay->conet, 501, \
	"Content-Type: application/json\r\n\
connection: close\r\n\
Allow: GET\r\n", \
	"{\"result\": %s}", "\"Method not implemented\"");
	replay->status = 501;
	log_message(replay);
}