//
//  Player.cpp
//  soccerGame
//
//  Created by Amol Mane on 9/19/15.
//
//

#include "Player.h"
#include "cinder/Rand.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Ball.h"


Player::Player() {
    int x = 512;
    int y = 384;
    loc = Vec2i(x,y);
    radius = 10.0f;
    moveUp = moveDown = moveLeft = moveRight = false;
}

Player::Player(int x, int y) {
    loc = Vec2i(x,y);
    radius = 10.0f;
    moveUp = moveDown = moveLeft = moveRight = false;
//    isActive = false;
}

void Player::update() {
//    if(isActive) {
        if (moveUp)
            loc.y -= 1;
        if (moveDown)
            loc.y += 1;
        if (moveRight)
            loc.x += 1;
        if (moveLeft)
            loc.x -= 1;
    
//        if
//    }
    //non-active players automatic movement
//    else {
    
//    }
}

void Player::draw() {
    if(isActive) {
        gl::color(0, 0, 1);
//        gl::drawSolidTriangle(Vec2f(loc.x+radius*2, loc.y), Vec2f(loc.x+radius, loc.y+radius), Vec2f(loc.x+radius, loc.y-radius));
        gl::drawStrokedCircle(loc, radius*1.5);
        gl::color(1,1,1);
    }
    gl::drawSolidCircle(loc, radius);
}