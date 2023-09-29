NAME		=	miniRT
MLX_NAME	=	libmlx.a
LIBFT_NAME	=	libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
MLX_CFLAGS	=	-L/usr/X11R6/lib -lX11 -lXext -lm

SRC_DIR		=	./src
OBJ_DIR		=	./obj
MLX_DIR		=	./minilibx-linux
LIBFT_DIR	=	./libft
INCLUDE		=	-Iinclude -I${MLX_DIR} -I${LIBFT_DIR}

# find src -type f -name "*.c" | sort | sed 's/^src\//\${SRC_DIR}\//;s/$/ \\/' | pbcopy
SRCS	=	\
			main.c \
${SRC_DIR}/init/set_vector2d.c \
${SRC_DIR}/init/set_vector3d.c \
${SRC_DIR}/make_image.c \
${SRC_DIR}/ray/set_ray.c \
${SRC_DIR}/sphere/get_normal_vector_for_sphere.c \
${SRC_DIR}/sphere/hit_sphere.c \
${SRC_DIR}/utils/calculator/get_num_of_positive_solutions.c \
${SRC_DIR}/utils/calculator/get_num_of_solutions.c \
${SRC_DIR}/utils/calculator/get_t_of_contact_point.c \
${SRC_DIR}/utils/calculator/scale_to_minus_one_to_one.c \
${SRC_DIR}/utils/calculator/scale_to_zero_to_one.c \
${SRC_DIR}/utils/color/convert_rgb_in_int.c \
${SRC_DIR}/utils/color/get_pixel_color.c \
${SRC_DIR}/utils/error_utils/exit_with_errno.c \
${SRC_DIR}/utils/mlx_utils/handle_key_press.c \
${SRC_DIR}/utils/mlx_utils/handle_window_close.c \
${SRC_DIR}/utils/mlx_utils/my_mlx_pixel_put.c \
${SRC_DIR}/utils/mlx_utils/set_color_in_image.c \
${SRC_DIR}/utils/x_wrapper/ft_xcalloc.c \
${SRC_DIR}/vector/addition_vector3d.c \
${SRC_DIR}/vector/dot_vector3d.c \
${SRC_DIR}/vector/normalize_vector3d.c \
${SRC_DIR}/vector/subtraction_vector3d.c \
${SRC_DIR}/vector/subtraction_vector3d_xyz.c \
${SRC_DIR}/vector/vector3d_dot_double.c \
${SRC_DIR}/vector/vector3d_magnitude.c \

OBJS	=	${addprefix ${OBJ_DIR}/, ${SRCS:.c=.o}}
DEPS	=	${OBJS:.o=.d}
RM		=	rm -rf
MKDIR	=	mkdir -p

.DEFAULT_GOAL = all
all		:	${NAME}

${NAME}: ${OBJS}
	-$(MAKE) -C ${MLX_DIR}
	$(MAKE) -C ${LIBFT_DIR}
	${CC} ${CFLAGS} ${MLX_DIR}/${MLX_NAME} ${MLX_CFLAGS} ${LIBFT_DIR}/${LIBFT_NAME} -o $@ ${OBJS}

${OBJ_DIR}/%.o : %.c
	${MKDIR} $(@D)
	${CC} ${CFLAGS} ${INCLUDE} -MMD -MP -o $@ -c $<

clean	:
	$(MAKE) clean -C ${MLX_DIR}
	$(MAKE) clean -C ${LIBFT_DIR}
	${RM} ${OBJ_DIR}

fclean	:	clean
	${RM} ${NAME} ${MLX_DIR}/${MLX_NAME} ${LIBFT_DIR}/${LIBFT_NAME}

re		:	fclean all

norm	:
	norminette main.c ${SRC_DIR} include ${LIBFT_DIR}

# Test rule
test: CFLAGS += -fsanitize=address
test: re

-include ${DEPS}

.PHONY: all clean fclean re

# m1, m2チップのmacでコンパイルする方法
# xquartzのインストール方法
# 	brew install --cask xquartz
# 以下のコマンドでDISPLAY環境変数が設定されているか確認する
# 	echo $DISPLAY
# 出力されない場合は、macから再ログインすれば表示される
