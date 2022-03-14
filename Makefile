### Separator
SEP ="\n\e[0;36m--------------------------------------------------------\e[0m\n"

### Directoris
API_DIR	=	./API
CLI_DIR	=	./CLI

### Git configurations
MSG		= Update
ADD		= .

### Default goal
.DEFAULT_GOAL	= all

### Rules
all:	CLI
		sudo docker build -t api ./API
		sudo docker run -d -v /home/luishads/42/42labs-selection-process-v2-lamorim42/API/log/server.log:/api_42/log/server.log --env-file db.env -p 8000:8000 --name my_server api

CLI:
	make all -C $(CLI_DIR)

clean:
	make clean -C $(CLI_DIR)

fclean:		clean
			make fclean -C $(CLI_DIR)
			$(RM) .git_log

re:			fclean all

git:		fclean
			git status
			@echo $(SEP)
			git add $(ADD)
			@echo $(SEP)
			git commit -m "$(MSG)"
			@echo $(SEP)
			git status
			@echo $(SEP)
			git log > .git_log

.PHONY:		all clean fclean re CLI