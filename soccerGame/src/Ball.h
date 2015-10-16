//
//  Ball.h
//  soccerGame
//
//  Created by Amol Mane on 9/19/15.
//
//

#ifndef __soccerGame__Ball__
#define __soccerGame__Ball__

#include <stdio.h>
#include "cinder/Vector.h"
#include "Player.h"

class Ball {
public:
    Ball();
    void update(Player* (players)[], Player* &activePlayer);
    void draw();
    int findClosestPlayer(Player* (players)[]);
    
    double decay = .25;
    
    Vec2i loc;
    Vec4i dir;
    double speed;
    int radius;
    
private:
    
};


#endif /* defined(__soccerGame__Ball__) */
