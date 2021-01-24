##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## lib
##

SRC		=		ncurses/Ncurses.cpp	\
				ncurses/launch_ncurses.cpp	\
				ncurses/Windowcurses.cpp	\
				ModuleHandling/Memory.cpp	\
				ModuleHandling/CPU.cpp	\
				ModuleHandling/System.cpp	\
				ModuleHandling/Network.cpp	\
				ModuleHandling/Swap.cpp	\
				ModuleHandling/Date.cpp	\
				main.cpp	\

RM		=		rm -fr

NAME	=		MyGKrellm

OBJ		=		$(SRC:.cpp=.o)

CXXFLAGS	=	-Wall -Werror -Wextra -g

$(NAME):	$(OBJ)
			@g++ -std=c++11 -o $(NAME) $(OBJ) $(LDFLAGS) $(OFLAGS) -lcurses -lsfml-graphics -lsfml-window -lsfml-system

all:		$(NAME)

clean:
			@$(RM) $(OBJ)
			@$(RM) *~
			@$(RM) *.o

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
