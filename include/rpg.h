/*
** EPITECH PROJECT, 2021
** ex
** File description:
** ex header
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Types.h>
#include <SFML/Audio.h>

#include "my_linked_list.h"
#include <stdint.h>
#include <stdio.h>

#ifndef RPG_H_
    #define RPG_H_

typedef struct map_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2u screen_pos;
    sfVector2f scale;
    sfView *view;
    int col_pos;
    sfVector2f offset;
    char *collision_map;
    int move_x;
    int move_y;
} map_t;

typedef struct every_sounds_s every_sounds_t;
typedef struct game_s game_t;
typedef struct wd_game_s wd_game_t;

typedef enum element_e {
    NO_ELEMENT = -1,
    FIRE,
    ICE,
    WATER,
    ROCK,
    NB_ELEMENT
} element_t;

    #define FIRE_COLOR ((sfColor){.r = 150, .g = 0, .b = 0, .a = 255})
    #define ICE_COLOR ((sfColor){.r = 102, .g = 255, .b = 200, .a = 255})
    #define ROCK_COLOR ((sfColor){.r = 254, .g = 105, .b = 0, .a = 255})
    #define WATER_COLOR ((sfColor){.r = 0, .g = 75, .b = 255, .a = 255})

typedef struct all_texture_s {
    sfTexture **particles;
    sfTexture **projectile;
    sfTexture **enemies;
} all_texture_t;

typedef struct text_s {
    sfFont *font;
    sfText *text;
    int size;
    sfVector2f pos;
    sfColor color;
} text_t;

typedef struct every_text_s {
    text_t *fps_text;
    text_t *set_fps;
    text_t *fps;
    text_t *volume;
    text_t *volume_nb;
    text_t *resolution;
    text_t *res_val;
    text_t *stats_health;
    text_t *stats_dmg;
    text_t *stats_speed;
    text_t *atk_point;
    text_t *health_point;
    text_t *speed_point;
    text_t *skill;
    text_t *skill_points;
    text_t *skill_nb;
    text_t *quest_one;
    text_t *quest_two;
    text_t *quest_three;
    text_t *quest_four;
    text_t *text_pnj_talks;
    text_t *health;
} every_text_t;

typedef struct object_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    char *texture_path;
    void (*on_click)(struct game_s *);
    void (*on_hover)(struct game_s *);
    struct object_s *next;
} object_t;

typedef struct every_object_s {

    object_t *button_play;
    object_t *button_exit;
    object_t *button_option;
    object_t *button_menu;
    object_t *ux_win_one;
    object_t *ux_win_two;
    object_t *ux_win_three;
    object_t *ux_win_four;
    object_t *button_sound;
    object_t *button_resume;
    object_t *table;
    object_t *ux_bg;
    object_t *ux_bg_little;
    object_t *htp_bg;
    object_t *good_job;
    object_t *button_plus;
    object_t *button_plus_two;
    object_t *button_less;
    object_t *button_less_two;
    object_t *button_left;
    object_t *button_left_two;
    object_t *button_right;
    object_t *button_htp;
    object_t *button_door;
    object_t *button_dmg_one;
    object_t *button_dmg_two;
    object_t *button_dmg_three;
    object_t *button_health_one;
    object_t *button_health_two;
    object_t *button_health_three;
    object_t *button_speed_one;
    object_t *button_speed_two;
    object_t *button_speed_three;
    object_t *title;
    object_t *background;
    object_t *inventory;
    object_t *button_editor;
    object_t *obj_pnj_talks;
} every_object_t;

typedef enum menu_type_e {
    EXIT = -1,
    MAIN_MENU,
    GAME,
    PAUSE,
    OPTION,
    HTP_MENU,
    PAUSE_SETTINGS,
    SKILL_TREE,
    QUEST_MENU,
    STATS_MENU,
    BOSS_MENU,
    EDITOR,
    HOME_GAME,
    END_SCREEN,
    START_SCREEN,
    NB_SCREEN
} menu_type_t;

typedef enum weather_e {
    CLEAR,
    RAINING,
    SNOW,
    NB_WEATHER
} weather_t;

typedef enum daytime_e {
    MORNING,
    AFTERNOON,
    EVENING,
    NIGHT
} daytime_t;

typedef struct player_s player_t;
typedef struct config_s config_t;
typedef struct inventory_s inventory_t;
typedef struct quest_s quest_t;
typedef struct skill_tree_s skill_tree_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    int win_size;
    int volume;
    int skill_points;
    sfEvent event;
    object_t *object;
    map_t *map;
    sfClock *clock_game;
    sfClock *clock_anim;
    every_sounds_t *sounds;
    every_text_t *text;
    every_text_t *skill_text;
    every_text_t *stats_text;
    every_text_t *quest_text;
    every_object_t *htp;
    every_object_t *end_screen;
    every_object_t *quest;
    every_object_t *stats;
    every_object_t *skill;
    every_object_t *pause_settings;
    every_object_t *all_obj;
    every_object_t *pause;
    every_object_t *settings;
    inventory_t *inventory;
    int time;
    daytime_t daytime;
    weather_t weather;
    linked_list_t *particles;
    sfView *game_view;
    linked_list_t *projectiles;
    linked_list_t *enemy_proj;
    linked_list_t *enemies;
    linked_list_t *collectables;
    all_texture_t *textures;
    menu_type_t screen;
    player_t *player;
    config_t *config;
    wd_game_t *editor;
    quest_t *list_quest;
    skill_tree_t *skill_tree;
} game_t;

    #define VIEW_MOVE 40

//-----core functions-----
int put_filter(game_t *game);
int update_date(game_t *game);
int get_time(sfClock *clock, double seconds);
int change_speed(game_t *game);
int change_dir(game_t *game);
int iabsolute(int a);
double dabsolute(double a);
float fabsolute(float a);
void destroy_all_texture(all_texture_t *all_text);
all_texture_t *init_all_texture(game_t *game);
int game_menu(game_t *game);
int boss_game(game_t *game);
void draw_menu(game_t *game);
int sprite_set_center(sfSprite *sprite);
sfFloatRect get_hitbox(sfVector2f center, sfFloatRect hitbox);
sfFloatRect show_hitbox(sfVector2f pt, sfFloatRect box, sfRenderWindow *win);

//Protos of objects creations
object_t *create_object(char *filepath, sfIntRect rect, sfVector2f position,
sfVector2f scale);
void draw_object(object_t *obj, game_t *game);
void delete_object(object_t *object);

//Protos of text creations
text_t *create_text(char *txt, int size, sfVector2f pos, sfColor color);
void delete_text(text_t *text);
void draw_text(text_t *text, game_t *game);
void draw_fps(game_t *game);

//Protos of main_menu buttons
int init_button_main_menu(every_object_t *obj);
void button_check_main_menu(game_t *game);
void draw_map_scrolling(game_t *game);
int init_main_menu_second(every_object_t *obj);

void exit_game(game_t *game);
void switch_to_game(game_t *game);
void switch_to_settings_menu(game_t *game);
void main_menu_to_game(game_t *game);
void switch_to_editor(game_t *game);

//Protos of pause_settings_menu buttons
void draw_pause_settings_menu(game_t *game);
void destroy_pause_settings_menu(every_object_t *obj);
every_object_t *init_pause_settings_menu_second(void);
int init_pause_settings_menu(every_object_t *obj);
void button_check_pause_settings_menu(game_t *game);
int init_button_pause_settings_menu(every_object_t *obj);
int pause_settings_menu(game_t *game);
every_text_t *init_pause_text_settings(void);
void draw_pause_text_settings(game_t *game);
void destroy_pause_text_settings_menu(every_text_t *text);

void switch_to_pause_settings_menu(game_t *game);
void switch_to_pause_menu(game_t *game);

//Protos of stats_menu
int stats_menu(game_t *game);
int init_stats_menu(every_object_t *obj);
every_object_t *init_stats_menu_second(void);
void draw_stats_menu(game_t *game);
void destroy_stats_menu(every_object_t *obj);
every_text_t *init_text_stats(void);
void draw_text_stats(game_t *game);
void destroy_text_stats_menu(every_text_t *text);
void button_check_stats_menu(game_t *game);
int init_button_stats_menu(every_object_t *obj);

int update_speed_point(game_t *game);
int update_attack_point(game_t *game);
int update_health_point(game_t *game);

//Protos of settings_menu buttons
int init_button_settings_menu(every_object_t *obj);
void button_check_settings_menu(game_t *game);
int init_settings_menu_third(every_object_t *obj);

void switch_to_main_menu(game_t *game);
void settings_to_main_menu(game_t *game);
void set_fps_up(game_t *game);
void set_fps_down(game_t *game);
void set_volume_up(game_t *game);
void set_volume_down(game_t *game);
void set_render_window(game_t *game);
void switch_to_htp_menu(game_t *game);

every_text_t *init_text_settings(void);

//Protos of settings_menu
void button_check_pause_menu(game_t *game);
int init_button_pause_menu(every_object_t *obj);
void draw_text_settings(game_t *game);

//Protos of tools functions
double dabsolute(double a);
int iabsolute(int a);
char *read_line_from_stream(FILE *file);
char **my_str_to_word_array(char *str, char *sep);
void calculate_framerate(game_t *game);
int print_help(void);
int check_env(char **env);
char *int_to_str(int value);

//Protos of htp menu
every_object_t *init_htp_menu(void);
void draw_htp_menu(game_t *game);
void destroy_htp_menu(every_object_t *obj);
int htp_menu(game_t *game);
int init_button_htp_menu(every_object_t *obj);

//Protos of skill menu
int skill_menu(game_t *game);
void button_check_click_skill_menu(game_t *game);
int init_button_click_skill_menu(every_object_t *obj);
every_object_t *init_skill_menu_second(void);
every_text_t *init_text_skill(void);
void destroy_skill_menu(every_object_t *obj);
void destroy_text_skill_menu(every_text_t *text);
int init_skill_menu(every_object_t *obj);
int init_skill_menu_third(every_object_t *obj);
void draw_skill_menu(game_t *game);
void draw_text_skill(game_t *game);
int init_skill_button_damage(every_object_t *obj);
int init_skill_button_health(every_object_t *obj);
int init_skill_button_speed(every_object_t *obj);
int init_button_hover_skill_menu(every_object_t *obj);
int init_skill_menu_four(every_object_t *obj);
void button_check_hover_skill_menu(game_t *game);

void show_text_dmg(game_t *game);
void show_text_health(game_t *game);
void show_text_speed(game_t *game);

//Protos of quest menus
int init_quest_menu(every_object_t *obj);
every_object_t *init_quest_menu_second(void);
void destroy_quest_menu(every_object_t *obj);
void draw_quest_menu(game_t *game);
void button_check_quest_menu(game_t *game);
void init_button_quest_menu(every_object_t *obj);
void draw_text_quest(game_t *game);
void destroy_text_quest_menu(every_text_t *text);
every_text_t *init_text_quest(void);

int quest_menu(game_t *game);

//Protos of menus functions
every_object_t *init_pause_menu(void);
every_object_t *init_main_menu(void);
int init_settings_menu(every_object_t *obj);
every_object_t *init_settings_menu_second(void);

void draw_main_menu(game_t *game);
void draw_pause_menu(game_t *game);
void draw_settings_menu(game_t *game);

int settings_menu(game_t *game);
int main_menu(game_t *game);
int pause_menu(game_t *game);
int gameloop(game_t *game);

int select_menu(game_t *game);
void destroy_main_menu(every_object_t *obj);
void destroy_pause_menu(every_object_t *obj);
void destroy_settings_menu(every_object_t *obj);

void destroy_text_settings_menu(every_text_t *text);

//Protos of game managments
game_t *init_game(void);
void destroy_game(game_t *game);
int reset_game(game_t *game);
int my_rpg(void);

//Protos of window functions
int destroy_window(sfRenderWindow *window);
sfRenderWindow *create_window(int width, int heigth);
int open_window(game_t *game);

//--animations functions--
void animate_main_game(game_t *game);
int draw_player(game_t *game);
void draw_map_scrolling(game_t *game);

//-----view functions-----
void scroll_view_right(game_t *game, sfVector2f mov);
void scroll_view_down(game_t *game, sfVector2f mov);
void scroll_view_left(game_t *game, sfVector2f mov);
void scroll_view_up(game_t *game, sfVector2f mov);
void clear_screen(game_t *game);
void spawn_entity(game_t *game);

//-----init functions-----
int map_init(game_t *game);
int map_destroy(game_t *game);

//----event functions-----
void analyse_keyboard(game_t *game);
void analyse_mouse(game_t *game);
int check_collision(game_t *game, sfVector2f pos);
int destroy_array(void **array);
void check_game_condition(game_t *game);

int show_map_coll(game_t *game);
int show_screen_coll(game_t *game);
void move_view(game_t *game);
int get_map_pos(game_t *game, sfVector2f pos);

int editor(game_t *game);
void analyse_win_events(game_t *game, sfEvent event);
void draw_home_map(game_t *game);
int home_game(game_t *game);
int check_home_exit(game_t *game);

void analyse_main_game_events(game_t *game);
void animate_main_game(game_t *game);
int init_pnj_talks_onj(game_t *game);
int text_set_center(sfText *text);
int update_skill_point(game_t *game);
void switch_to_boss(game_t *game);
int end_screen(game_t *game);
every_object_t *init_end_screen(void);
void destroy_end_menu(every_object_t *obj);
void draw_end_menu(game_t *game);
int start_screen(game_t *game);

#endif
