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
    int x = app::getWindowWidth()/2;;
    int y = app::getWindowHeight()/2;;
    loc = Vec2i(x,y);
    dir = Vec4i(0,0,0,0);
    speed = 1;
    radius = 10;
//    moveUp = moveDown = moveLeft = moveRight = false;
    isActive = hasBall = false;
    playerId = x+y;
    justReleasedBall = false;
}

Player::Player(int gridX, int gridY, int x, int y) {
    grid = Vec2i(gridX, gridY);
    loc = Vec2d(x,y);
    dir = Vec4i(0,0,0,0);
    speed = 1;
    radius = 10;
//    moveUp = moveDown = moveLeft = moveRight = false;
    isActive = hasBall = false;
    playerId = x+y;
    justReleasedBall = false;
}

void Player::update() {
    if(isActive) {
        if (dir.y)
            loc.y -= speed;
        if (dir.w)
            loc.y += speed;
        if (dir.x)
            loc.x += speed;
        if (dir.z)
            loc.x -= speed;
    }
    else {
        //need an algorithm
    }
}

void Player::releaseBall() {
    if(hasBall) {
        hasBall = false;
        cout<<"Release activated: "<<hasBall<<endl;
        justReleasedBall = true;
        //algorithm to set power on ball
        //figure out trajectory of ball and switch to player closest to that point
    }
}

void Player::draw() {
    if(isActive) {
        gl::color(0, 0, 1);
        gl::drawSolidTriangle(Vec2f(loc.x+radius*2, loc.y), Vec2f(loc.x+radius,
                             loc.y+radius), Vec2f(loc.x+radius, loc.y-radius));
//      gl::drawStrokedCircle(loc, radius*1.5);
        gl::color(1,1,1);
    }
    gl::drawSolidCircle(loc, radius);
}