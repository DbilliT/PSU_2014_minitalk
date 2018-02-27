/*
** basic_functions.c for basic_functions in /home/bechad_p/rendu/PSU_2014_minitalk/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Mon Nov 10 16:09:44 2014 Pierre Bechade
** Last update Mon Nov 10 16:21:53 2014 Pierre Bechade
*/

#include "my_server.h"
#include "my_client.h"

int	my_getnbr_calc(char *str, int i, double nb_final, int nb_return)
{
  while (((str[i] != '\0') && ((str[i] >= '0') && (str[i] <= '9')))
         || ((str[i] == '-') || (str[i] == '+')))
    {
      if (str[i] >= '0' && str[i] <= '9')
        nb_final = (nb_final * 10) + (str[i] - 48);
      if (str[i] == '-')
        nb_return = nb_return + 1;
      i++;
    }
  if ((nb_return % 2) != 0)
    nb_final = nb_final - (2 * nb_final);
  if (nb_final > 2147483647 || nb_final < -2147483648)
    return (0);
  nb_return = nb_final;
  return (nb_return);
}

int		my_getnbr(char *str)
{
  int		result;
  double	nb_final;
  int		i;
  int		nb_return;

  result = 0;
  nb_final = 0;
  i = 0;
  nb_return = 0;
  result = my_getnbr_calc(str, i, nb_final, nb_return);
  return (result);
}

void	my_put_nbr_calc(int nb)
{
  if (nb == -2147483648)
    {
      my_putchar('-');
      my_putchar('2');
      my_putchar('1');
      my_putchar('4');
      my_putchar('7');
      my_putchar('4');
      my_putchar('8');
      my_putchar('3');
      my_putchar('6');
      my_putchar('4');
      my_putchar('8');
    }
  else
    {
      if (nb < 0)
        {
          my_putchar('-');
          nb = nb * -1;
        }
      if (nb >= 10)
        my_put_nbr_calc(nb / 10);
      my_putchar(nb % 10 + '0');
    }
}

int	my_put_nbr(int nb)
{
  my_put_nbr_calc(nb);
  return (0);
}

void	*my_xmalloc(int size)
{
  void	*tmp;

  if ((tmp = malloc(size)) == NULL)
    {
      write(2, "Error malloc\n", 13);
      exit(0);
    }
  return (tmp);
}
