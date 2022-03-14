/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_db.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:48:33 by lamorim           #+#    #+#             */
/*   Updated: 2022/02/27 04:43:23 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "api.h"

static void	ft_msg_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}

static void	ft_init_error(void)
{
	fprintf(stderr, "mysql_init() failed\n");
	exit(1);
}

char *ft_peck_form_db(void)
{
	t_db	*db;
	char	*ret;

	db = malloc(sizeof(t_db));
	if (db == NULL)
		exit(499);
	db->con = mysql_init(NULL);
	if (db->con == NULL)
		ft_init_error();
	if (mysql_real_connect(db->con, getenv("DBHOST"), getenv("DBUSER"), \
	getenv("DBPASS"), getenv("DBNAME"), (unsigned int)atoi(getenv("DBPORT")), \
	NULL, 0) == NULL)
		ft_msg_error(db->con);
	if (mysql_query(db->con, "SELECT * FROM secret"))
		ft_msg_error(db->con);
	db->result = mysql_store_result(db->con);
	if (db->result == NULL)
		ft_msg_error(db->con);
	db->row = mysql_fetch_row(db->result);
	db->str = malloc(sizeof(char) * strlen(db->row[0]) + 1);
	if (db->str == NULL)
		exit(500);
	if (db->row[0] != NULL)
		strcpy(db->str, db->row[0]);
	else
		db->str = NULL;
	mysql_free_result(db->result);
	mysql_close(db->con);
	ret = db->str;
	free(db);
	mysql_library_end();
	return(ret);
}
