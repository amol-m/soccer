//
//  Ball.cpp
//  soccerGame
//
//  Created by Amol Mane on 9/19/15.
//
//

#include "Ball.h"
#include "cinder/Vector.h"
#include "Player.h"
#include "cinder/gl/gl.h"

using namespace ci;

Ball::Ball() {
    int x = 100;
    int y = 100;
    loc = Vec2i(x ,y);
    speed = 4.0f;
    dir = Vec2i(1,1);
    radius = 5.0f;
    isAttachedToPlayer = false;
}

//void Ball::update(Player team[], int activePlayer) {
//    if (isAttachedToPlayer == false) {
//        loc += speed * dir;
//    }
//    else {
//        
//    }
//}

void Ball::update() {
    float tempX = loc.x + (dir.x * speed);
    float tempY = loc.y + (dir.y * speed);
    if(tempX < radius/2 || tempX > 1028 - radius/2) {
        dir.x = dir.x * -1;
    }
    loc.x += dir.x * speed;
    if(tempY < radius/2 || tempY > 768 - radius/2) {
        dir.y = dir.y * -1;
    }
    loc.y += dir.y * speed;
}

void Ball::draw() {
    gl::color(1, 0, 0);
    gl::drawSolidCircle(loc, radius);
    gl::color(1,1,1);
}