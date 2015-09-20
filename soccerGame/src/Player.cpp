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



Player::Player() {
    int x = 512;
    int y = 384;
    loc = Vec2i(x,y);
    radius = 10.0f;
    moveUp = moveDown = moveLeft = moveRight = false;
}

void Player::update() {
    if (moveUp)
        loc.y -= 1;
    if (moveDown)
        loc.y += 1;
    if (moveRight)
        loc.x += 1;
    if (moveLeft)
        loc.x -= 1;
}

void Player::draw() {
    gl::drawSolidCircle(loc, radius);
}