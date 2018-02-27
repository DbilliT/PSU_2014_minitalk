##
## Makefile for Makefile in /home/bechad_p/rendu/PSU_2014_minitalk
## 
## Made by Pierre Bechade
## Login   <bechad_p@epitech.net>
## 
## Started on  Mon Nov 10 14:38:14 2014 Pierre Bechade
## Last update Tue Nov 11 21:09:34 2014 Pierre Bechade
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-Werror -Wall -W -Wextra -g3

CFLAGS	+=	-I./include/

NAMES	=	d_server/server

NAMEC	=	d_client/client

SRCS	=	d_server/my_server.c		\
		src/basic_functions.c		\
		src/error_functions.c		\
		src/my_tools.c			\
		src/my_tools2.c

SRCC	=	d_client/my_client.c		\
		d_client/sig_handler.c		\
		src/basic_functions.c		\
		src/error_functions.c		\
		src/my_tools.c			\
		src/my_tools2.c

OBJS	=	$(SRCS:.c=.o)

OBJC	=	$(SRCC:.c=.o)

all:		$(NAMES) $(NAMEC)

$(NAMES):	$(OBJS)
		$(CC) $(OBJS) -o $(NAMES) $(CFLAGS)

$(NAMEC):	$(OBJC)
		$(CC) $(OBJC) -o $(NAMEC) $(CFLAGS)

clean:
		$(RM) $(OBJS)
		$(RM) $(OBJC)

fclean:		clean
		$(RM) $(NAMES)
		$(RM) $(NAMEC)

re:		fclean all
