/*
** client.c for Makefile in /home/bechad_p/rendu/PSU_2014_minitalk/client
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Mon Nov 10 14:45:00 2014 Pierre Bechade
** Last update Tue Nov 11 21:25:07 2014 Pierre Bechade
*/

#include "my_client.h"

void	send_pid(pid_t my_pid, pid_t pid)
{
  char	bit;
  char	i;

  i = 0;
  bit = 0;
  while (i < 32)
    {
      bit = (my_pid >> i) & 1;
      if (bit == 0)
	{
	  if (kill(pid, SIGUSR1) == -1)
	    {
	      my_putstr_e("kill error on send SIGUSR1 (PID).\n");
	      exit(0);
	    }
	}
      else if (kill(pid, SIGUSR2) == -1)
	{
	  my_putstr_e("kill error on send SIGUSR2 (PID)\n");
	  exit(0);
	}
      usleep(100);
      i++;
    }
}

void	send_signal(char n, pid_t pid)
{
  char	bit;
  char	i;

  i = 0;
  bit = 0;
  while (i < 8)
    {
      bit = (n >> i) & 1;
      if (bit == 0)
	{
	  if (kill(pid, SIGUSR1) == -1)
	    {
	      my_putstr_e("kill error on send SIGUSR1 to the server\n");
	      exit(0);
	    }
	}
      else if (kill(pid, SIGUSR2) == -1)
	{
	  my_putstr_e("kill error on send SIGUSR2 to the server\n");
	  exit(0);
	}
      pause();
      i++;
    }
}

void	my_char_to_bin(char *sms, pid_t pid)
{
  int	i;

  i = 0;
  while (sms[i])
    {
      send_signal(sms[i], pid);
      i++;
    }
  send_signal(sms[i], pid);
}

void	my_get_pid(pid_t pid)
{
  pid_t	my_pid;

  my_pid = getpid();
  send_pid(my_pid, pid);
}

int	main(int ac, char **av)
{
  char	*sms;
  pid_t	pid;

  if (signal(SIGUSR1, sig_handler) == SIG_ERR)
    {
      my_putstr_e("signal error receive by the client\n");
      exit(0);
    }
  if (ac != 3)
    {
      my_putstr_e("Usage : ./client PID message\n");
      return (-1);
    }
  if ((pid = my_getnbr(av[1])) == 0)
    {
      my_putstr_e("PID invalide\n");
      return (-1);
    }
  my_get_pid(pid);
  sms = my_strdup(av[2]);
  my_char_to_bin(sms, pid);
  return (0);
}
