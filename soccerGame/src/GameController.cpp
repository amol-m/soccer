//
//  PlayerController.cpp
//  soccerGame
//
//  Created by Amol Mane on 9/19/15.
//
//

#include "GameController.h"
#include "cinder/app/AppBasic.h"
#include <cmath>

using namespace ci::app;

GameController::GameController() {
    for(int i=1;i<6;i++) {
//        int x = (int)app::getWindowWidth()/(i*100);
//        int y = (int)app::getWindowHeight()/(i*100);
        int x = 1024/(i+1);
        int y = 768/(i+1);
        players[i-1] = new Player(x,y);
    }
    ball = new Ball();
    activePlayer = players[0];
    switchPlayer();
}

void GameController::switchPlayer() {
    cout<<"in switch player"<<endl;
    activePlayer->hasBall = false;
    activePlayer->isActive = false;
    activePlayer->dir.x = activePlayer->dir.y = activePlayer->dir.z = activePlayer->dir.w = 0;
    activePlayer = findClosestPlayer();
    cout<<"id: "<<activePlayer->playerId<<endl;
    activePlayer->isActive = true;
}

Player* GameController::findClosestPlayer() {
    int closestPlayer;
    double minDistance = 1024;
    for(int i=0;i<5;i++) {
        double distToBall = sqrt( pow((ball->loc.x - players[i]->loc.x), 2) + pow((ball->loc.y - players[i]->loc.y), 2) );
        if( distToBall < minDistance) {
            closestPlayer = i;
            minDistance = distToBall;
        }
    }
    return players[closestPlayer];
}

void GameController::keyDown(cinder::app::KeyEvent event) {
    //movement
    if( event.getCode() == cinder::app::KeyEvent::KEY_UP ) {
        activePlayer->dir.y = 1;
//        cout<<"up on"<<endl;
    }
    if( event.getCode() == cinder::app::KeyEvent::KEY_DOWN ) {
        activePlayer->dir.w = 1;
    }
    if( event.getCode() == cinder::app::KeyEvent::KEY_RIGHT ) {
        activePlayer->dir.x = 1;
//        cout<<"right on"<<endl;
    }
    if( event.getCode() == cinder::app::KeyEvent::KEY_LEFT ) {
        activePlayer->dir.z = 1;
    }
    
    //switch player
    if( event.getCode() == cinder::app::KeyEvent::KEY_TAB ) {
        cout<<"tab pressed"<<endl;
        switchPlayer();
    }
    
    //release ball
    if(event.getCode() == cinder::app::KeyEvent::KEY_SPACE) {
        cout<<"space pressed"<<endl;
        activePlayer->releaseBall();
    }
}

void GameController::keyUp(cinder::app::KeyEvent event) {
    if( event.getCode() == KeyEvent::KEY_UP ) {
        activePlayer->dir.y = 0;
//        cout<<"up off"<<endl;
    }
    if( event.getCode() == KeyEvent::KEY_DOWN ) {
        activePlayer->dir.w = 0;
    }
    if( event.getCode() == KeyEvent::KEY_RIGHT ) {
        activePlayer->dir.x = 0;
//        cout<<"right off"<<endl;
    }
    if( event.getCode() == KeyEvent::KEY_LEFT ) {
        activePlayer->dir.z = 0;
    }
}

void GameController::update() {
//    cout<<"y: "<<activePlayer->dir.y<<" x: "<<activePlayer->dir.x<<endl;
    for(int i=0;i<5;i++) {
        players[i]->update();
    }
    ball->update(players, activePlayer);
}

void GameController::draw() {
    for(int i=0;i<5;i++) {
        players[i]->draw();
    }
    ball->draw();
}