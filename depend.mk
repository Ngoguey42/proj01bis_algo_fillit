MKGEN_SRCSBIN_DEFAULT :=\
	obj/srcs/main.o\
	obj/srcs/parse.o\
	obj/srcs/parse2.o\
	obj/srcs/solve.o\
	obj/srcs/solve128.o\
	obj/srcs/solve128_plus.o\
	obj/srcs/solve64.o\
	obj/srcs/solveptr.o
obj/srcs/main.o: libft/include/ft_macroes.h libft/include/ft_typedefs.h libft/include/libft.h libft/include/ft_string.h libft/include/ft_stdlib.h srcs/main.c libft/include/ft_ctype.h include/fillit.h libft/include/ft_stdio.h | obj/srcs/
obj/srcs/parse.o: libft/include/ft_macroes.h libft/include/ft_typedefs.h libft/include/libft.h libft/include/ft_string.h libft/include/ft_stdlib.h libft/include/ft_ctype.h include/fillit.h libft/include/ft_stdio.h srcs/parse.c | obj/srcs/
obj/srcs/parse2.o: libft/include/ft_macroes.h libft/include/ft_typedefs.h libft/include/libft.h srcs/parse2.c libft/include/ft_string.h libft/include/ft_stdlib.h libft/include/ft_ctype.h include/fillit.h libft/include/ft_stdio.h | obj/srcs/
obj/srcs/solve.o: libft/include/ft_macroes.h libft/include/ft_typedefs.h libft/include/libft.h libft/include/ft_string.h libft/include/ft_stdlib.h srcs/solve.c libft/include/ft_ctype.h include/fillit.h libft/include/ft_stdio.h | obj/srcs/
obj/srcs/solve128.o: srcs/solve128.c libft/include/ft_macroes.h libft/include/ft_typedefs.h libft/include/libft.h libft/include/ft_string.h libft/include/ft_stdlib.h libft/include/ft_ctype.h include/fillit.h libft/include/ft_stdio.h | obj/srcs/
obj/srcs/solve128_plus.o: srcs/solve128_plus.c libft/include/ft_macroes.h libft/include/ft_typedefs.h libft/include/libft.h libft/include/ft_string.h libft/include/ft_stdlib.h libft/include/ft_ctype.h include/fillit.h libft/include/ft_stdio.h | obj/srcs/
obj/srcs/solve64.o: srcs/solve64.c libft/include/ft_macroes.h libft/include/ft_typedefs.h libft/include/libft.h libft/include/ft_string.h libft/include/ft_stdlib.h libft/include/ft_ctype.h include/fillit.h libft/include/ft_stdio.h | obj/srcs/
obj/srcs/solveptr.o: libft/include/ft_macroes.h libft/include/ft_typedefs.h libft/include/libft.h libft/include/ft_string.h libft/include/ft_stdlib.h libft/include/ft_ctype.h srcs/solveptr.c include/fillit.h libft/include/ft_stdio.h | obj/srcs/
