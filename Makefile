##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Made by Hugo SOHM
##

NAME		=	client

SRCS    	=	src/main.c		\
				src/mychap.c	\
				src/mychap2.c	\
				src/init.c		\
				src/sending.c	\
				src/functions.c

OBJS		=	$(SRCS:.c=.o)
INCL		=	-Iinclude

####################################################

CC			=	gcc
RM			=	rm -f
CFLAGS		=

#####################################################

.c.o	:
	@$(CC) $(CFLAGS) $(INCL) -c $< -o $@
	@printf " \033[34m[Compilation]\033[39m %s\n" $<

all	:	$(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@printf "\n \033[33m[Message]\033[39m Server compilation done\n"

clean	:
	@$(RM) *~ $(OBJS)
	@printf " \033[31m[Delete] \033[39m%s\n" $(OBJS)

fclean	:	clean
	@$(RM) $(NAME)
	@printf "\n \033[31m[Delete] \033[39m%s\n\n" $(NAME)

re	:	fclean all