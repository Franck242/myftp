/*
** EPITECH PROJECT, 2021
** my_ftp
** File description:
** Created by j-f,
*/
#ifndef MY_FTP_MYFTP_H
#define MY_FTP_MYFTP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <signal.h>
#include <stdbool.h>

#define ERROR_EXIT	(84)
#define SUCCESS_EXIT	(0)
#define __220MSG__	("220 Service ready for new user.\n")
#define __331MSG__	("331 User name okay, need password.\n")
#define __EXIT_MSG__	("Disconnection")
#define __PASS_MSG__	("230 User logged in, proceed.\n")
#define __ERROR__	("500 Unknow command\n")
#define __LOG_MSG__	("332 Need account for login.\n")
#define __HELP_MSG__	("214 Help message.\n")
#define __NOOP_MSG__	("200 Command okay.\n")
#define __530MSG__	("530 Not loged.\n")
#define __250MSG__	("250 Requested file action okay, completed.\n")
#define __250MSG__	("250 Requested file action okay, completed.\n")
#define __150MSG__	("150 File status okay; about open data connection.\n")
#define __226MSG__	("226 Closing data connection.\n")
#define __PASV_MSG__	("227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).\n")
#define __ERROR_ARGS__	write(2, "Error on arguments.Try ./server -help\n", 40);
#define __ERROR_PROTO__	write(2,"Error on port value. Connection failed\n", 40);
#define __ERROR_FILE__	write(2, " : Impossible to read the directory\n", 37);
#define __ERROR_FORK__	write(2, "Error, your programm can't fork\n", 32);

typedef struct	s_socket_info
{
	struct protoent		*proto;
	struct sockaddr_in	s_in, client_s_in;
	int			fd, b, fd_client;
	socklen_t		size;
	char			*ip_client;
	pid_t			pid;
	bool			user_value;
	bool			password_value;
	char			*path;
}				t_socket_info;

typedef struct	s_commands
{
	char	*str;
	void (*fct)(char**, t_socket_info*);
}		t_commands;

void	print_help(char*);
void	check_nb_args(int , char**);
void	check_proto_name(struct protoent*);
void	create_socket(int, char*);
void	check_closing_file(int);
void	check_bind_value(int, int);
void	check_listen(int);
void	check_client_fd(int);
void	check_path(char *file_name);
void	check_port_and_fd(int, int);
void	check_pid(pid_t, t_socket_info);
void	check_closing(int, int);
void	print_message(char*, int);
int	cmd_gestion(t_socket_info);
char	**my_str_to_wordtab(char*);
bool	check_quit_function(char*, t_socket_info);
void	identification(char**, t_socket_info*);
void	noop(char**, t_socket_info*);
void	help_message(char**, t_socket_info*);
void	password(char**, t_socket_info*);
void	pwd(char**, t_socket_info*);
void	pasv(char**, t_socket_info*);
void	check_client_fd(int);
void	check_path(char*);
void	check_port_and_fd(int, int);
void	check_closing(int, int);
void	check_pid(pid_t, t_socket_info);
void	list(char**, t_socket_info*);
void	cwd(char**, t_socket_info*);

#endif //MY_FTP_MYFTP_H
