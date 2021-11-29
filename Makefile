CC 		= 	clang
RM		= 	rm -rf
EXEC	=	server client
LIBRARY =	libft/libft.a libft/Printf/libftprintf.a
CFLAGS	= 	-Wall -Wextra -Werror

HEADERS	=	./

all :		${EXEC}

client :
			@$(MAKE) -C ./libft
			@${CC} ${CFLAGS} -I ${HEADERS} client.c -o $@ ${LIBRARY}

server :
			@$(MAKE) -C ./libft
			@${CC} ${CFLAGS} -I ${HEADERS} server.c -o $@ ${LIBRARY}

clean :	
			@$(MAKE) -C ./libft clean
			@${RM} server.o client.o

fclean :	clean 
			@$(MAKE) -C ./libft fclean
			@${RM} server client minitalk.h.gch

re :		fclean all

.PHONY :	all clean fclean re



