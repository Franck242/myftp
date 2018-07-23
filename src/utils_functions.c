/*
** EPITECH PROJECT, 2021
** PSU_myftp_2017
** File description:
** Created by j-f,
*/

#include "myftp.h"

void	print_message(char *msg, int fd)
{
	write(fd, msg, strlen(msg));
}

bool	check_quit_function(char *cmd, t_socket_info sock)
{
	if (strncasecmp(cmd, "QUIT", 4) == 0 && strcasecmp(cmd, "QUIT") == 13) {
		print_message(__EXIT_MSG__, sock.fd_client);
		write(sock.fd_client, "\n", 1);
		return (true);
	}
	return (false);
}

void	pasv(char **cmd_tab, t_socket_info *sock)
{
	if (!cmd_tab)
		return;
	print_message(__PASV_MSG__, sock->fd_client);
}

void	list(char **cmd_tab, t_socket_info *sock)
{
	if (!cmd_tab)
		return;
	print_message(__150MSG__, sock->fd_client);
	print_message(__226MSG__, sock->fd_client);
}

void	cwd(char **cmd_tab, t_socket_info *sock)
{
	if (!cmd_tab)
		return;
	print_message(__250MSG__, sock->fd_client);
}
