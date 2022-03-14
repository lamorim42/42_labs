
# Documentação da API

Para fazer API utilizei duas libs core para o funcionamento correto do programa.
A lib `mongoose`, onde irá nos ajudar a lidar com o monitoramento das portas e as requisições `HTTP`. E a `libmysql` que nos auxilia nas querys no bando de dados.

## Como navegar por esse repositório

- [`src`](./src/) - Código fonte do projeto

- [`obj`](./obj/) - Diretório para os arquivos objetos gerados na compilação

- [`log`](./log/) - Onde fica o arquivo de log do sistema

- [`library`](./library/) - Onde será gerado o arquivo `libmongoose.a`

- [`include`](./include/) - Onde estão os arquivos `api.h` e `mongoose.h`

- [`Dockerfile`](./Dockerfile) - Arquivo para gerar o container onde irá rodar a API

No diretório [`src`](./src/) temos o arquivo [`handle_db.c`](./src/handle_db.c) que são funções para as querys no banco de dados.

O arquivo [`handle_replay.c`](./src/handle_replay.c) são funções para lidar com os retornos das requisições.

E na [`main.c`](./src/main.c) temos o core da aplicação, são as funções que tiram vantagem da biblioteca `mongoose`.

O arquivo [`mongoose.c`](./src/mongoose.c) é o arquivo fonte da lib mongoose.

---

## [handle_db.c](./src/handle_db.c)

- `static void	ft_msg_error(MYSQL *con)` - Função auxiliar para lidar com erros de alocação de variáveis do `libmysql`

- `static void	ft_init_error(void)` - Função auxiliar para lidar com erro de inicialização da variáveis `con`

- `char *ft_peck_form_db(void)` - Função principal do arquivo, onde abrimos o banco de dados e pegamos a informação requisitada pelo cliente. Ela retorna o conteudo a ser devolvido no body.

## [handle_replay.c](./src/handle_replay.c)

- `static void	log_message(t_replay *replay)` - Função auxiliar para gerar o conteudo do arquivo de log.

- `void	ft_replay_home(t_replay *replay)` - Função para lidar com o retorno da requisição `GET` no endpoit `/`.

- `void	ft_replay_secret(t_replay *replay)` - Função para lidar com o retorno da requisição `GET` no endpoit `/secret`, esse retorno é extraido do banco de dados.

- `void	ft_replay_nf(t_replay *replay)` - Função para lidar com o retorno da requisição `GET` em um endpoit não válido.

- `void	ft_replay_ni(t_replay *replay)` - Função para lidar com o retorno de requisição que não são `GET`.

## [main.c](./src/main.c)

- `static void	ft_sig_stop(int sign)` - Função para lidar com o sinal de interrupção `SIGINT`. Ela altera o valor da variável `g_sig` para interronper o looping de escuta da porta, por onde são feitas as requisições, e libera os espaços alocados pela aplicação.

- `static int	ft_check_method(const char *mth)` - Essa função verifica se o metódo passado é o `GET`. Se for `GET` retorna `0` caso não retorna `1`.

- `static void ft_handle_event(struct mg_connection *conet, int ev, void *ev_data, void *fn_data)` - Essa é a função responsável por retornar a requisição corretamente. Ela verifica a todo momento de algum request foi feito com o auxilio da `MG_EV_HTTP_MSG`.

- `int main(void)` - A main é a reponsavel por manter a escuta na porta e responde uma request do tipo `HTTP` com o auxílio das funções do `mongoose`.

## [Dockerfile](./Dockerfile)

Contem as diretivas para gerar uma imagem de um container com as dependencias necessárias para rodar a aplicação.