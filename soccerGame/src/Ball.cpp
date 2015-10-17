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
#include "cinder/app/AppBasic.h"


using namespace ci;


Ball::Ball() {
//    int x = app::getWindowWidth()/2;
//    int y = app::getWindowWidth()/2;
//    int x = 1024/2;
//    int y = 768/2;
    int x = 700;
    int y = 700;
    loc = Vec2i(x ,y);
    speed = 8.0;
    dir = Vec4i(0,0,0,0);
    radius = 7;
}

void Ball::update(Player* (players)[], Player* &activePlayer) {
    
    if(activePlayer->hasBall) {
        loc = activePlayer->loc;
        dir = activePlayer->dir;
    }
    else {
        //move ball
        double temp;
        
        if (dir.y) {
            temp = loc.y - speed;
            if(temp < radius/2) {
                dir.y = 0;
                dir.w = 1;
                loc.y += speed;
            }
            else {
                loc.y -= speed;
            }
        }
        
        else if (dir.w) {
            temp = loc.y + speed;
            if(temp > 768 - radius/2) {
                dir.y = 1;
                dir.w = 0;
                loc.y -= speed;
            }
            else {
                loc.y += speed;
            }
        }

        if (dir.x) {
            temp = loc.x + speed;
            if(temp > 1024 - radius/2) {
                dir.x = 0;
                dir.z = 1;
                loc.x -= speed;
            }
            else {
                loc.x += speed;
            }
        }
        
        else if (dir.z) {
            temp = loc.x - speed;
            if(temp < radius/2) {
                dir.x = 1;
                dir.z = 0;
                loc.x += speed;
            }
            else {
                loc.x -= speed;
            }
        }
        
        //check if ball is in the radius of another player
        int closestPlayerIndex = findClosestPlayer(players);
//        cout<<closestPlayerIndex<<endl;
        Player* closestPlayer = players[closestPlayerIndex];
//        cout<<"just released ball: "<<closestPlayer->justReleasedBall<<endl;
//        cout<<"lhs: "<<pow((closestPlayer->loc.x - loc.x), 2) + pow((closestPlayer->loc.y - loc.y), 2)<<" r2:"<<pow(radius + 3, 2)<<endl;
        cout<<"ball: ( "<<loc.x<<", "<<loc.y<<" ) player: ( "<<closestPlayer->loc.x<<", "<<closestPlayer->loc.y<<" )"<<endl;
        if( pow((closestPlayer->loc.x - loc.x), 2) + pow((closestPlayer->loc.y - loc.y), 2) < pow(radius + 3, 2) ) {
            cout<<"fucked it up"<<endl;
            activePlayer->isActive = false;
            activePlayer->hasBall = false;
//            activePlayer->dir.x = activePlayer->dir.y = activePlayer->dir.z = activePlayer->dir.w = 0;
            activePlayer = players[closestPlayerIndex];
            activePlayer->isActive = true;
            activePlayer->hasBall = true;
            
            loc = activePlayer->loc;
            dir = activePlayer->dir;
        }
    }
}

int Ball::findClosestPlayer(Player* (players)[]) {
    int closestPlayer;
    double minDistance = 1024;
    for(int i=0;i<5;i++) {
        double distToBall = sqrt( pow((loc.x - players[i]->loc.x), 2) + pow((loc.y - players[i]->loc.y), 2) );
        if( distToBall < minDistance) {
            closestPlayer = i;
            minDistance = distToBall;
        }
    }
//    cout<<closestPlayer<<endl;
    return closestPlayer;
}

void Ball::draw() {
    gl::color(1, 0, 0);
    gl::drawSolidCircle(loc, radius);
    gl::color(1,1,1);
}