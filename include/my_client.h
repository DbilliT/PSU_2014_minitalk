/*
** my_client.h for client in /home/bechad_p/rendu/PSU_2014_minitalk/include
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Mon Nov 10 14:50:19 2014 Pierre Bechade
** Last update Tue Nov 11 21:04:03 2014 Pierre Bechade
*/

#ifndef _MY_CLIENT_H_
# define _MY_CLIENT_H_

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

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

/* IN D_CLIENT/MY_CLIENT */
void	send_pid(pid_t my_pid, pid_t pid);
void	send_signal(char n, pid_t pid);
void	sig_handler(int sig);
void	my_char_to_bin(char *sms, pid_t pid);
void	my_get_pid(pid_t pid);

#endif /* _MY_CLIENT_H_ */
