/*
** my_tools.c for my_tools in /home/bechad_p/rendu/PSU_2014_minitalk/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Mon Nov 10 16:12:05 2014 Pierre Bechade
** Last update Tue Nov 11 21:52:50 2014 Pierre Bechade
*/

#include "my_server.h"
#include "my_client.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	size;

  i = 0;
  if (my_strlen(s1) > my_strlen(s2))
    size = my_strlen(s2);
  else
    size = my_strlen(s1);
  while (size >= 0)
    {
      if (s1[i] > s2[i] && s2[i] != '*')
        return (s1[i] - s2[i]);
      if (s1[i] < s2[i] && s2[i] != '*')
        return (s1[i] - s2[i]);
      i++;
      size--;
    }
  return (0);
}

char	*my_strdup(char *src)
{
  int	i;
  char	*dest;

  i = 0;
  dest = my_xmalloc(sizeof(char) * (my_strlen(src) + 1));
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
