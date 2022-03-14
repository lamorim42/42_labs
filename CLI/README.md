
# Documentção da CLI

A CLI é uma aplicação para printar no terminal de maneira legivel o conteúdo do arquivo de log gerado pelo servidor.

## Como navegar por esse repositório

- [`src`](./src/) - Código fonte do projeto

- [`obj`](./obj/) - Diretório para os arquivos objetos gerado na compilação

- [`include`](./include/) - Onde está o arquivo `cli.h`

No diretório [`src`](./src/) temos os arquivos [`cli_printf.c`](./src/cli_printf.c), onde temos fuções responsáveis por printar os logs,
[`cli_utils.c`](./src/cli_utils.c), onde temos funções úteis para nossa aplicação, e [`cli.c`](./src/cli.c) onde organizamos o que foi pedido.

---

## [cli_printf.c](./src/cli_printf.c)

No aruivo `cli_printf.c` podemos destacar duas funções:

- `void	ft_chose_printf(t_data *data)` - Onde escolhemos qual função auxiliar vamos usar para printar o que foi requisitado.

- `void	ft_printf_all_log(t_data *data)` - Onde é printado todo a informação do arquivo de forma bruta no terminal.

As outras fuções são bem parecidas e redundantes. São o que será printado no terminal.

## [cli_utils.c](./src/cli_utils.c)

- `void	ft_count(t_data *data)` - ela é responsável por contar quantas requisições dos métodos válidos foram feitas e armazenadas no log. Essa é uma função que nos dá os valores que usaremos para printar no terminal.

- `int	ft_check_args(t_data *data)` - é a responsável por validar os argumentos passados pelo usuário.

- `void	ft_init_data(int arg_c, char **arg_v, t_data *data)` - é onde iniciamos o tipo `t_data` que nos ajuda a guardar informações que serão retornadas e tratar os argumentos.

## [cli.c](./src/cli.c)

Nesse arquivos temos apenas a função `main` que apenas chama as outras funções.