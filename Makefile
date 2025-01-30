NAME = banksystem

CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -std=c++17

SRCS = main.cpp add_client.cpp client_system.cpp list_clients.cpp search_clients.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re