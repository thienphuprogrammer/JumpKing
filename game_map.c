#include "game_map.h"

void LoadMap(GameMap* game_map, char* name) {
    FILE* fp = NULL;
    fopen_s(&fp, name, "rb");
    if (fp == NULL) {
        return;
    }

    game_map->game_map_.max_x_ = 0;
    game_map->game_map_.max_y_ = 0;
    for (int i = 0; i < MAX_MAP_Y; i++) {
        for (int j = 0; j < MAX_MAP_X; j++) {
            fscanf_s(fp, "%d", &game_map->game_map_.tile[i][j]);
            int val = game_map->game_map_.tile[i][j];
            if (val > 0) {
                if (j > game_map->game_map_.max_x_) {
                    game_map->game_map_.max_x_ = j;
                }
                if (i > game_map->game_map_.max_y_) {
                    game_map->game_map_.max_y_ = i;
                }
            }
        }
    }
    game_map->game_map_.max_x_ = (game_map->game_map_.max_x_ + 1) * TILE_SIZE;
    game_map->game_map_.max_y_ = (game_map->game_map_.max_y_ + 1) * TILE_SIZE;

    game_map->game_map_.start_x_ = 0;
    game_map->game_map_.start_y_ = 0;

    game_map->game_map_.file_name = name;
    fclose(fp);
}

void LoadTiles(GameMap* game_map, SDL_Renderer* screen) {
    char file_img[30];
    FILE* fp = NULL;

    for (int i = 0; i < MAX_TILES; i++) {
        sprintf_s(file_img, "map/%d.png", i);

        fopen_s(&fp, file_img, "rb");
        if (fp == NULL) {
            continue;
        }
        fclose(fp);

        game_map->tile_mat[i].base_objectLoadImg(file_img, screen);
    }
}

void DrawMap(GameMap* game_map, SDL_Renderer* des) {
    int x1 = 0;
    int x2 = 0;

    int y1 = 0;
    int y2 = 0;

    int map_x = 0;
    int map_y = 0;

    map_x = game_map->game_map_.start_x_ / TILE_SIZE;
    x1 = (game_map->game_map_.start_x_ % TILE_SIZE) * -1;
    x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);

    map_y = game_map->game_map_.start_y_ / TILE_SIZE;
    y1 = (game_map->game_map_.start_y_ % TILE_SIZE) * -1;
    y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);

    for (int i = y1; i < y2; i++, i += TILE_SIZE) {
        map