/*
** server.c for server in /home/bechad_p/rendu/PSU_2014_minitalk/server
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Mon Nov 10 14:46:10 2014 Pierre Bechade
** Last update Tue Nov 11 21:58:21 2014 Pierre Bechade
*/

#include "my_server.h"

char	c;

int	get_pid_client(int sig, int a, int pid_c)
{
  if (sig == SIGUSR1)
    pid_c += (0 << a++);
  else if (sig == SIGUSR2)
    pid_c += (1 << a++);
  return (pid_c);
}

void		sig_handler(int sig)
{
  static int	a = 0;
  static int	size_pid_c = 0;
  static int	pid_c = 0;
  int		tmp;

  if (size_pid_c < 32)
    {
      pid_c = get_pid_client(sig, a, pid_c);
      (1) ? a++, size_pid_c++ : 0;
    }
  else
    {
      (a == 32) ? a = 0 : 0;
      (sig == SIGUSR1) ? c += (0 << a++) : 0;
      (sig == SIGUSR2) ? c += (1 << a++) : 0;
      tmp = pid_c;
      if (a == 8)
	{
	  (c == '\0') ? size_pid_c = 0, pid_c = 0, MY_P('\n') : MY_P(c);
	  (1) ? c = 0, a = 0 : 0;
	}
      usleep(100);
      if (kill(tmp, SIGUSR1) == -1)
	(1) ? my_putstr_e("kill error\n"), exit(0) : 0;
    }
}

int	main()
{
  pid_t	server;

  c = 0;
  server = getpid();
  my_putstr("PID server : '");
  my_put_nbr(server);
  my_putstr("'\n");
  if (signal(SIGUSR1, sig_handler) == SIG_ERR)
    {
      my_putstr_e("signal error (SIGUSR1)\n");
      exit(0);
    }
  if (signal(SIGUSR2, sig_handler) == SIG_ERR)
    {
      my_putstr_e("signal error (SIGUSR1)\n");
      exit(0);
    }
  while (42)
    pause();
  return (0);
}
