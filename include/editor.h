/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** editor
*/

#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Audio.h>
#include <time.h>
#include "my.h"
#include <math.h>

#ifndef EDITOR_H
    #define EDITOR_H

typedef enum wd_dir_e {
    SE,
    NO,
    NE,
    SO
} wd_dir_t;

typedef enum wd_type_e {
    LEVEL,
    UNIFORM,
    SKIN
} wd_type_t;

typedef struct wd_vector2d_s {
    double x;
    double y;
} wd_vector2d_t;

typedef struct framebuffer_s {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
    sfTexture *texture;
    sfSprite *sprite;
} framebuffer_t;

typedef enum wd_spritetype {
    GRASS_SPRITE,
    SWAMP_SPRITE,
    ICE_SPRITE,
    FIRE_SPRITE,
    NB_SPRITES
} wd_spritetype_t;

typedef struct wd_map_s {
    int **map;
    int **map_text;
    char *path;
    int height;
    int width;
    float fov;
    sfVector2f **points;
    sfVertexArray **line;
    sfVector2i selected;
    wd_type_t type;
    wd_spritetype_t spritetype;
} wd_map_t;

typedef struct wd_matrix4x4_s {
    float **base_matrix;
    float **rotx_matrix;
    float **roty_matrix;
    float **end_matrix;
    float **proj_matrix;
} wd_matrix4x4_t;

typedef struct wd_game_s {
    wd_vector2d_t angle;
    framebuffer_t *fb;
    sfRenderWindow *win;
    wd_matrix4x4_t matrix;
    int status;
    wd_map_t *map;
    wd_dir_t dir;
    sfVideoMode mode;
    sfEvent event;
    sfTexture **textures;
} wd_game_t;

    #define WIDTH 1920
    #define HEIGHT 1080
    #define SCREEN_RATIO WIDTH / HEIGHT
    #define FPS 80
    #define FNEAR 1.0
    #define FFAR 10.0
    #define MAP_SIZE_X 21
    #define MAP_SIZE_Y 12
    #define FOV 45.0
    #define FOVRAD(x) (1.0 / tan((x) * 0.5 / 180.0f * M_PI))
    #define SELECTED_TILE game->map->map[game->map->selected.x]\
                                                [game->map->selected.y]

    #define FIRE_TILE_TEXT "assets/fire_set.png"
    #define GRASS_TILE_TEXT "assets/basic_green.png"
    #define SWAMP_TILE_TEXT "assets/swamp_set.png"
    #define ICE_TILE_TEXT "assets/ice_set.png"

int my_world(char **av, int ac);
void analyse_events(wd_game_t *game, sfEvent event);
char *file_to_str(char *filepath);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *framebuffer);
void my_put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color);
int render_map(wd_game_t*game);
sfVertexArray *create_line(sfVector2f point1, sfVector2f point2);
sfRenderStates *init_text_state(wd_game_t *game, wd_spritetype_t type);
sfVector2f pos_3d_to_2d(int x, int y, int z, wd_game_t *game);
int draw_spritemap(wd_game_t *game);
double to_radiant(double angle);
int draw_lines(wd_game_t *game);
sfVector2f **get_points(wd_game_t *game);
float **init_matrix(int empty);
int show_matrix(float **matrix);
float **multiply_matrix(float **matrix1, float **matrix2);
sfVector3f apply_matrix(sfVector3f vector, float **matrix);
void rotate_matrix_x(wd_game_t *game, double angle_x);
void rotate_matrix_y(wd_game_t *game, double angle_y);
float **init_proj_matrix(void);
int calc_end_matrix(wd_game_t *game);
int free_states(sfRenderStates *states);
int normalize_angle(wd_game_t *game);
int free_matrix(float **matrix);
int free_game(wd_game_t *game);
void on_click(wd_game_t *game, sfEvent event);
int update_dir(wd_game_t *game);
void update_proj_matrix(wd_game_t *game);
int draw_points(wd_game_t *game);
sfVector2i get_selected_circle(wd_game_t *game, float radius);
sfCircleShape *init_circle(float radius);
int circleshape_contains(sfCircleShape *circle, sfVector2i dot);
int circleshape_draw(wd_game_t *game, sfCircleShape *circle, int x, int y);
int update_x(int i, wd_game_t *game, int width, int height);
int update_y(int i, wd_game_t *game, int width, int height);
int draw_spritetile(wd_game_t *game, unsigned int x, unsigned int y,
        sfVertexArray *vertex_array);
int draw_line(wd_game_t *game, sfVector2f **points, int x, int y);
int my_usleep(long long time);
void level_tool(wd_game_t *game);
void union_tool(wd_game_t *game);
int tile_contains(wd_game_t *game, sfVector2i point, sfVector2f dot);
void change_zoom(wd_game_t *game, sfEvent event);
void change_angle(wd_game_t *game, sfEvent event);
void skin_tool(wd_game_t *game);
wd_game_t *init_editor_game(sfRenderWindow *win, sfVideoMode mode);

#endif
