/*
** EPITECH PROJECT, 2021
** PSU_myftp_2017
** File description:
** Created by j-f,
*/

#include "myftp.h"

void	identification(char **cmd_tab, t_socket_info *sock)
{
	if (!cmd_tab)
		return;
	print_message(__331MSG__, sock->fd_client);
}

void	password(char **cmd_tab, t_socket_info *sock)
{
	if (!cmd_tab)
		return;
	sock->password_value = true;
	print_message(__PASS_MSG__, sock->fd_client);
}

void	help_message(char **cmd_tab, t_socket_info *sock)
{
	if (!cmd_tab)
		return;
	print_message(__HELP_MSG__, sock->fd_client);
}

void	noop(char **cmd_tab, t_socket_info *sock)
{
	if (!cmd_tab)
		return;
	print_message(__NOOP_MSG__, sock->fd_client);
}

void	pwd(char **cmd_tab, t_socket_info *sock)
{
	if (!cmd_tab)
		return;
	print_message("257 ", sock->fd_client);
	print_message("\'", sock->fd_client);
	print_message(sock->path, sock->fd_client);
	print_message("\'", sock->fd_client);
	print_message(" created.\n", sock->fd_client);

}
