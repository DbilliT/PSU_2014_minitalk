/*
** my_server.h for server.h in /home/bechad_p/rendu/PSU_2014_minitalk/include
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Mon Nov 10 14:47:24 2014 Pierre Bechade
** Last update Tue Nov 11 21:58:02 2014 Pierre Bechade
*/

#ifndef _MY_SERVER_H_
# define _MY_SERVER_H_

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

# define MY_P my_putchar

/* IN SRC/BASIC_FUNCTIONS.C */
int	my_getnbr_calc(char *str, int i, double nb_final, int nb_return);
int	my_getnbr(char *str);
void	my_put_nbr_calc(int nb);
int	my_put_nbr(int nb);
void	*my_xmalloc(int size);

/* IN SRC/ERROR_FUNCTIONS.C */
void	my_putchar_e(char c);
void	my_putstr_e(char *str);
void	my_put_nbr_calc_e(int nb);
int	my_put_nbr_e(int nb);

/* IN SRC/MY_TOOLS2.C */
char	*my_strcat(char *dest, char *src);
char	*my_evil_str(char* str);
int	my_strncmp(char *s1, char *s2, int n);

/* IN SRC/MY_TOOLS.C */
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
char	*my_strdup(char *src);

/* IN D_SERVER/MY_SERVER.C */
int	get_pid_client(int sig, int a, int pid_c);
void	sig_handler(int sig);

#endif /* _MY_SERVER_H_ */
