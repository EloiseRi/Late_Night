NAME    	=    late_night
CC      	=     @g++

SRC     	=    $(wildcard src/*.cpp)

OBJ        	= $(SRC:.cpp=.o)

INCLUDE   	+=    -I./include

CXXFLAGS    +=    -Wall -Wextra -pedantic -O0 -g3

.cpp.o:
	@echo "\e[1;91m[\e[1;92mOK\e[1;91m]\e[0m" "\e[1;91m Compile\e[1;93m" $< "\e[1;91mto\e[1;92m" $@ "\e[0m"
		$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

all: $(OBJ)
	@echo "\e[1;91m[\e[1;92mOK\e[1;91m]\e[0m" "\e[1;91m LINK\e[1;93m" $< "\e[1;91mto\e[1;92m" $(NAME) "\e[0m"
		$(CC) -o $(NAME) $(OBJ) -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:    fclean all