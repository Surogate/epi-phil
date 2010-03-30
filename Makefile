##
## Makefile for project in /u/all/ancel_a/cu/travail/c/
##
## Made by francois1 ancel
## Login   <ancel_a@epitech.net>
##
## Started on  Tue Mar 23 15:29:31 2010 francois1 ancel
## Last update Tue Mar 23 15:29:31 2010 francois1 ancel
##

NAME	= philo1
CC	= gcc
RM	= rm -rf
SRCS	= phil_fct.c		\
	table_fct.c		\
	xpthread.c		\
	main.c

OBJS	= $(SRCS:.c=.o)
CFLAGS	= -W -Wall -Wextra -O3 -ansi
LDFLAGS	= -lpthread

$(NAME)	: $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all