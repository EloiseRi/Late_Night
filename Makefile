NAME	=	late_night
CC		= 	@g++
SRC		=	$(shell find . -name '*.cpp')

OBJ		= $(SRC: .cpp=.o)

CXXFLAGS	+=	-Wall -Wextra
CXXFLAGS    +=  -Wno-unused-parameter
CXXFLAGS    +=	-I./include

all: $(OBJ)
		$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ) -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system			

clean:
		find . -name "*.o" -type f -delete
		find . -name "vgcore.*" -type f -delete

fclean: clean
	rm -f $(NAME)

re:	fclean