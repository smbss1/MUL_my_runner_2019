#
# EPITECH PROJECT, 2019
# Makefile
# File description:
# make an executable
#

SRC = 	main.c \
		update.c \
		src/parallax_system.c \
		src/analyse_events.c \
		src/init_window.c \
		src/animation_system.c \
		src/close_window.c \
		src/create_text.c \
		src/move_rect.c \
		src/music_create_from_file.c \
		src/create_entity.c \
		src/sprite_t_create.c \
		src/draw.c \
		src/destroy_entity.c \
		src/entity_move.c \
		src/vector2f_set.c \
		src/state_manager.c \
		src/create_int_rect.c \
		src/sort_by_order_layer.c \
		src/game_state.c \
		src/menu_state.c \
		src/tile_map.c \
		src/set_rb2d_collision.c \
		src/game_over.c \
		src/update_rect.c \
		src/update_coll.c \
		src/init_tiles_sprite.c \
		src/entity_set_position.c \
		src/lerp.c \
		src/camera_system.c \
		src/menu_mouse_events.c \
		src/init_player.c \
		src/move.c \
		src/init_background.c \
		src/state_init.c \
		src/state_manager_draw.c \
		src/state_manager_update.c \
		src/state_manager_init.c \
		src/state_manager_contain.c \
		src/init_music.c \
		my_event.c
OBJ = $(SRC:.c=.o)
NAME = my_runner

CFLAGS += -I ./include/
CFLAGS += -L ./lib/
CFLAGS += -lmy

CFLAGS += -lcsfml-graphics
CFLAGS += -lcsfml-window
CFLAGS += -lcsfml-system
CFLAGS += -lcsfml-audio

bold = [1m
green = [32m
yellow = [33m
blue = [34m
reset = (B[m

all: $(NAME)

lib_make:
	@make -C lib/my

$(NAME): lib_make $(OBJ)
	@echo '$(bold)$(green)Creating the $(NAME)...$(reset)'
	@gcc -g3 -o $(NAME) $(OBJ) $(CFLAGS)
	@echo '$(bold)$(yellow)Executable created...$(reset)'
clean:
	@echo '$(bold)$(blue)Clean the directory in process...$(reset)'
	@rm -f $(OBJ)
	@echo '$(bold)$(yellow)Executable cleaned..$(reset)'

fclean: clean
	@rm -f $(NAME)
	@make fclean -C lib/my

re: fclean all