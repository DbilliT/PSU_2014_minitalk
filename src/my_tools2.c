/*
** my_tools2.c for my_tools2 in /home/bechad_p/rendu/PSU_2014_minitalk/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Mon Nov 10 16:11:34 2014 Pierre Bechade
** Last update Mon Nov 10 16:11:35 2014 Pierre Bechade
*/

#include "my_server.h"
#include "my_client.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*new;

  i = 0;
  j = 0;
  new = my_xmalloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)));
  while (dest[i] != '\0')
    {
      new[i] = dest[i];
      i++;
    }
  i--;
  while (src[j] != '\0')
    {
      new[i] = src[j];
      j++;
      i++;
    }
  new[i] = '\0';
  return (new);
}

char	*my_evil_str(char* str)
{
  int	a;
  int	b;
  char	c;

  a = 0;
  b = my_strlen(str) - 1;
  while (a < b)
    {
      c = str[a];
      str[a] = str[b];
      str[b] = c;
      a = a + 1;
      b = b - 1;
    }
  return (str);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  if (n < 0)
    n = n * (-1);
  if (my_strlen(s1) < n && my_strlen(s2) < n)
    {
      if (my_strlen(s1) > my_strlen(s2))
        n = my_strlen(s1);
      else
        n = my_strlen(s2);
    }
  while (n > 0)
    {
      if (s1[i] > s2[i])
        return (s1[i] - s2[i]);
      if (s1[i] < s2[i])
        return (s1[i] - s2[i]);
      i++;
      n--;
    }
  return (0);
}
