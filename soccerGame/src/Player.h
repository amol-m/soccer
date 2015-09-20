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
    Player(int x, int y);
    void update();
    void draw();
    
    Vec2i loc;
    bool isActive;
    bool moveUp;
    bool moveDown;
    bool moveLeft;
    bool moveRight;
    float radius;
};

#endif /* defined(__soccerGame__Player__) */
