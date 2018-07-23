/*
** EPITECH PROJECT, 2021
** PSU_myftp_2017
** File description:
** Created by j-f,
*/

#include "myftp.h"

bool	check_cmd(char *cmd, t_commands *c)
{
	int	index = 0;

	while (index < 9) {
		if (strncasecmp(c[index].str, cmd, strlen(cmd) - 1) != 0)
			index = index + 1;
		else
			return (true);
	}
	return (false);
}

void	dl(char **cmd_tab, t_socket_info *sock)
{
	if (!cmd_tab)
		return;
	print_message(__250MSG__, sock->fd_client);
}

void	check_allcmd(char **cmd_tab, t_socket_info *sock)
{
	t_commands	all[] = {{"USER", &identification}, {"PASS", &password},
		{"HELP", &help_message}, {"NOOP", &noop}, {"PWD", &pwd},
		{"PASV", &pasv}, {"LIST", &list}, {"CWD", &cwd}, {"DELE", &dl}};
	int	i = 0;

	if (sock->user_value == false) {
		print_message(__530MSG__, sock->fd_client);
		return;
	}
	if (sock->user_value == true) {
		if (check_cmd(cmd_tab[0], all) == false)
			print_message(__ERROR__, sock->fd_client);
		while (i < 9) {
			if (strncasecmp(cmd_tab[0], all[i].str,
				strlen(all[i].str)) == 0) {
				all[i].fct(cmd_tab, sock);
				return;
			}
			i = i + 1;
		}
	}
}

int	cmd_gestion(t_socket_info sock)
{
	char	*cmd, **cmd_tab;

	cmd = malloc(sizeof(char *));
	sock.user_value = false;
	sock.password_value = false;
	while (read(sock.fd_client, cmd, 100000)) {
		cmd_tab = my_str_to_wordtab(cmd);
		if (strncasecmp(cmd_tab[0], "USER", 4) == 0
			&& cmd_tab[1])
			sock.user_value = true;
		if (check_quit_function(cmd, sock) == true) {
			kill(sock.pid, SIGINT);
			free(cmd);
			free(cmd_tab);
			break;
		}
		check_allcmd(cmd_tab, &sock);
	}
	return (0);
}