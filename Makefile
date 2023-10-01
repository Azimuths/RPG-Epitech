##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	src/collectable/duck_collectables/duck_collectable_star_particle.c	\
		src/collectable/duck_collectables/create_water_duck_collectable.c	\
		src/collectable/duck_collectables/create_rock_duck_collectable.c	\
		src/collectable/duck_collectables/create_fire_duck_collectable.c	\
		src/collectable/duck_collectables/create_ice_duck_collectable.c		\
		src/menu/pause_settings_menu/button_check_pause_settings_menu.c		\
		src/menu/boss_menu/lich_spells/fire_spell_second_wave.c			\
		src/menu/pause_settings_menu/init_pause_settings_menu.c			\
		src/menu/pause_settings_menu/pause_settings_menu_func.c			\
		src/menu/boss_menu/lich_spells/create_skull_particle.c			\
		src/menu/skill_tree_menu/on_click_skill_health_func.c			\
		src/menu/end_screen/create_end_screen_star_particle.c			\
		src/player/animate_player/animate_player_attacking.c			\
		src/menu/skill_tree_menu/on_click_skill_speed_func.c			\
		src/menu/settings_menu/button_check_settings_menu.c			\
		src/menu/skill_tree_menu/on_click_skill_atk_func.c			\
		src/menu/skill_tree_menu/button_check_skill_menu.c			\
		src/menu/end_screen/create_end_screen_water_duck.c			\
		src/menu/pause_settings_menu/pause_settings_menu.c			\
		src/menu/pause_settings_menu/pause_settings_text.c			\
		src/player/animate_player/animate_player_moving.c			\
		src/menu/boss_menu/lich_spells/lich_boss_summon.c			\
		src/menu/boss_menu/lich_spells/lich_water_spell.c			\
		src/menu/skill_tree_menu/init_button_skill_menu.c			\
		src/menu/how_to_play_menu/button_check_htp_menu.c			\
		src/menu/end_screen/create_end_screen_fire_duck.c			\
		src/menu/end_screen/create_end_screen_rock_duck.c			\
		src/menu/boss_menu/lich_spells/lich_rock_spell.c			\
		src/menu/boss_menu/lich_spells/lich_fire_spell.c			\
		src/menu/boss_menu/lich_boss/lich_boss_animate.c			\
		src/menu/end_screen/create_end_screen_ice_duck.c			\
		src/player/animate_player/animate_player_idle.c				\
		src/player/animate_player/update_player_state.c				\
		src/menu/boss_menu/lich_spells/lich_ice_spell.c				\
		src/menu/boss_menu/lich_boss/lich_boss_update.c				\
		src/editor/get_selected/get_selected_circle.c				\
		src/enemy/dread_knight/dread_knight_animate.c				\
		src/enemy/death_knight/death_knight_animate.c				\
		src/menu/quest_menu/button_check_quest_menu.c				\
		src/menu/skill_tree_menu/destroy_skill_menu.c				\
		src/menu/skill_tree_menu/update_skill_point.c				\
		src/menu/stats_menu/button_check_stats_menu.c				\
		src/menu/settings_menu/settings_menu_volume.c				\
		src/menu/pause_menu/button_check_pause_menu.c				\
		src/enemy/dread_knight/dread_knight_update.c				\
		src/enemy/death_knight/death_knight_update.c				\
		src/enemy/dread_knight/dread_knight_shoot.c				\
		src/enemy/death_knight/death_knight_shoot.c				\
		src/enemy/necromancer/necromancer_animate.c				\
		src/menu/main_menu/button_check_main_menu.c				\
		src/menu/settings_menu/settings_menu_func.c				\
		src/menu/settings_menu/init_settings_menu.c				\
		src/editor/framebuffer/framebuffer_utils.c				\
		src/editor/init_elements/init_text_state.c				\
		src/player/animate_player/animate_player.c				\
		src/projectile/other_ice_duck_projectile.c				\
		src/enemy/necromancer/necromancer_update.c				\
		src/menu/boss_menu/lich_boss/create_boss.c				\
		src/menu/skill_tree_menu/skill_menu_func.c				\
		src/menu/skill_tree_menu/init_skill_menu.c				\
		src/enemy/necromancer/necromancer_shoot.c				\
		src/menu/stats_menu/update_stats_points.c				\
		src/menu/how_to_play_menu/init_htp_menu.c				\
		src/enemy/pnj_quest/init_pnj_talks_obj.c				\
		src/editor/utils/circleshape_contains.c					\
		src/player/animate_player/check_death.c					\
		src/editor/matrix/update_proj_matrix.c					\
		src/editor/init_elements/init_circle.c					\
		src/editor/init_elements/init_matrix.c					\
		src/projectile/water_duck_projectile.c					\
		src/enemy/pnj_quest/pnj_quest_update.c					\
		src/menu/settings_menu/settings_menu.c					\
		src/menu/settings_menu/settings_text.c					\
		src/editor/isometry/normalize_angle.c					\
		src/collectable/destroy_collectable.c					\
		src/projectile/rock_duck_projectile.c					\
		src/projectile/fire_duck_projectile.c					\
		src/menu/quest_menu/init_quest_menu.c					\
		src/menu/main_menu/switch_to_editor.c					\
		src/menu/skill_tree_menu/skill_text.c					\
		src/menu/skill_tree_menu/skill_menu.c					\
		src/menu/stats_menu/init_stats_menu.c					\
		src/menu/end_screen/init_end_screen.c					\
		src/menu/pause_menu/init_pause_menu.c					\
		src/editor/utils/triangle_contains.c					\
		src/editor/init_elements/init_game.c					\
		src/editor/isometry/draw_spritemap.c					\
		src/config/conf_update_window_size.c					\
		src/collectable/update_collectable.c					\
		src/collectable/create_collectable.c					\
		src/projectile/ice_duck_projectile.c					\
		src/menu/how_to_play_menu/htp_menu.c					\
		src/editor/matrix/calc_end_matrix.c					\
		src/editor/matrix/multiply_matrix.c					\
		src/collectable/check_collectable.c					\
		src/menu/boss_menu/switch_to_boss.c					\
		src/menu/main_menu/init_main_menu.c					\
		src/menu/main_menu/main_menu_func.c					\
		src/editor/isometry/pos_3d_to_2d.c					\
		src/collectable/draw_collectable.c					\
		src/projectile/update_projectile.c					\
		src/projectile/fire_duck_explode.c					\
		src/menu/start_menu/start_screen.c					\
		src/editor/matrix/rotate_matrix.c					\
		src/editor/my_world/change_view.c					\
		src/editor/isometry/draw_points.c					\
		src/event/event_menu/event_menu.c					\
		src/utils/read_line_from_stream.c					\
		src/projectile/sword_projectile.c					\
		src/editor/matrix/apply_matrix.c					\
		src/editor/utils/free_char_arr.c					\
		src/editor/isometry/render_map.c					\
		src/editor/isometry/update_dir.c					\
		src/utils/my_str_to_word_array.c					\
		src/projectile/draw_projectile.c					\
		src/particles/update_particles.c					\
		src/enemy/change_enemy_element.c					\
		src/inventory/update_inventory.c					\
		src/menu/quest_menu/quest_menu.c					\
		src/menu/quest_menu/quest_text.c					\
		src/menu/stats_menu/stats_menu.c					\
		src/menu/stats_menu/stats_text.c					\
		src/menu/end_screen/end_screen.c					\
		src/menu/pause_menu/menu_pause.c					\
		src/editor/matrix/show_matrix.c						\
		src/editor/matrix/free_matrix.c						\
		src/editor/isometry/draw_line.c						\
		src/projectile/check_colision.c						\
		src/enemy/pnj_quest/pnj_quest.c						\
		src/enemy/get_player_distance.c						\
		src/editor/utils/free_states.c						\
		src/editor/my_world/my_world.c						\
		src/menu/boss_menu/boss_menu.c						\
		src/editor/tools/level_tool.c						\
		src/config/conf_update_skin.c						\
		src/config/conf_update_part.c						\
		src/particles/snow_particle.c						\
		src/particles/rain_particle.c						\
		src/particles/star_particle.c						\
		src/inventory/add_inventory.c						\
		src/editor/utils/my_usleep.c						\
		src/editor/my_world/events.c						\
		src/editor/isometry/points.c						\
		src/event/event_game/event.c						\
		src/projectile/deal_damage.c						\
		src/error_check/check_env.c						\
		src/event/check_collision.c						\
		src/day_night/update_date.c						\
		src/init/init_all_texture.c						\
		src/home/home_move_player.c						\
		src/particles/xp_particle.c						\
		src/day_night/put_filter.c						\
		src/player/attack_player.c						\
		src/home/check_home_exit.c						\
		src/utils/destroy_array.c						\
		src/inventory/inventory.c						\
		src/sounds/change_music.c						\
		src/menu/main_menu/menu.c						\
		src/config/load_config.c						\
		src/player/draw_player.c						\
		src/player/move_player.c						\
		src/home/draw_home_map.c						\
		src/particles/particle.c						\
		src/enemy/spawn_entity.c						\
		src/enemy/create_enemy.c						\
		src/enemy/update_enemy.c						\
		src/event/on_keypress.c							\
		src/utils/get_map_pos.c							\
		src/init/destroy_game.c							\
		src/enemy/face_player.c							\
		src/sounds/set_volume.c							\
		src/view/clear_screen.c							\
		src/utils/print_help.c							\
		src/utils/set_center.c							\
		src/utils/get_hitbox.c							\
		src/init/init_player.c							\
		src/init/init_config.c							\
		src/enemy/move_enemy.c							\
		src/enemy/draw_enemy.c							\
		src/view/scroll_view.c							\
		src/menu/select_menu.c							\
		src/utils/print_fps.c							\
		src/utils/get_time.c							\
		src/utils/absolute.c							\
		src/init/init_game.c							\
		src/home/home_game.c							\
		src/view/move_view.c							\
		src/object/object.c							\
		src/window/window.c							\
		src/init/init_map.c							\
		src/sounds/sounds.c							\
		src/game/show_fps.c							\
		src/sounds/music.c							\
		src/object/text.c							\
		src/game/game.c								\
		src/my_rpg.c

OBJ = $(SRC:.c=.o)

TEST_SRC   	=

TEST_OBJ    =    $(TEST_SRC:.c=.o)

MAIN_SRC    =    src/main.c                \

MAIN_OBJ    =    $(MAIN_SRC:.c=.o)        \

NAME    =    my_rpg

LIBMY    = 	   libmyll.a

CPPFLAGS    +=	-I./include/
CFLAGS        +=	-fno-builtin -W -Wall -Wextra -L ./lib \
-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm -lmyll

all:    $(NAME)

$(NAME):    $(LIBMY) $(OBJ) $(MAIN_OBJ)
	make $(LIBMY)
	gcc -o $(NAME) $(OBJ) $(MAIN_OBJ) $(LIB) $(CFLAGS)

$(LIBMY):
	make -C lib/linked_list/

debug:	CPPFLAGS += -g
debug:	NAME = debug
debug:
	all
	valgrind ./debug

gcovr:
	gcovr --exclude tests
	gcovr --exclude tests --branches

clean:
	make clean -C./lib/linked_list/
	rm -f $(OBJ) $(MAIN_OBJ)
	rm -f $(TEST_OBJ)

fclean: clean
	make fclean -C ./lib/linked_list/
	rm -f tests_run
	rm -f $(TEST_OBJ)
	rm -f $(NAME)
	rm -f *.gc*

re:	fclean all

.PHONY:	all clean fclean re debug tests_run $(LIBMY)
