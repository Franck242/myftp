/*
** EPITECH PROJECT, 2021
** my_ftp
** File description:
** Created by j-f,
*/

#include "myftp.h"

void	print_help(char *name)
{
	printf("USAGE:  %s port path\n", name);
	printf("\tport is the port number on which the server ");
	printf("socket listens\n");
	printf("\tpath is the path to the home directory for ");
	printf("the Anonymous user\n");
}