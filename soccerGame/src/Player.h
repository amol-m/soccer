//
//  Player.h
//  soccerGame
//
//  Created by Amol Mane on 9/19/15.
//
//

#ifndef __soccerGame__Player__
#define __soccerGame__Player__

#include <stdio.h>
#include "cinder/Vector.h"
#include <vector>

using namespace ci;
using namespace std;

class Player {
public:
    Player();
    Player(int gridX, int gridY, int x, int y);
    void update();
    void releaseBall();
    void draw();
    
    Vec2i grid;
    Vec2i targetLoc;
    Vec2d loc;
    Vec4i dir;
    int speed;
    int radius;
    
    bool isActive;
    bool hasBall;
    bool justReleasedBall;
    
    int playerId;
    
//    bool moveUp;
//    bool moveDown;
//    bool moveLeft;
//    bool moveRight;
    
};

#endif /* defined(__soccerGame__Player__) */
