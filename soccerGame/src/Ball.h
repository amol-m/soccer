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
//#include <vector>
#include "Player.h"

class Ball {
public:
    Ball();
//    void update(Player* team[], int activePlayer);
    void update();
    void draw();
    
    float decay = .25f;
    float speed;
    cinder::Vec2f dir;
    cinder::Vec2i loc;
    bool isAttachedToPlayer;
    float radius;
private:
    
};


#endif /* defined(__soccerGame__Ball__) */
