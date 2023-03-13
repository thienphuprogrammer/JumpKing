#ifndef GAME_MAP_H_
#define GAME_MAP_H_

#include "CommonFunction.h"
#include "BaseObject.h"

#define MAX_TILES 20

typedef struct TileMat {
} TileMat;

typedef struct GameMap {
    Map game_map_;
    TileMat tile_mat[MAX_TILES];
} GameMap;

void LoadMap(GameMap* game_map, char* name);
void LoadTiles(GameMap* game_map, SDL_Renderer* screen);
void DrawMap(GameMap* game_map, SDL_Renderer* des);

#endif // !GAME_MAP_H_