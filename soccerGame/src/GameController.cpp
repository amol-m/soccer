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
//    homeTeam = new Team("4-3-3");
//    awayTeam = new Team("4-2-3-1");
    homeTeam = new Team();
    
//    for(int i=1;i<6;i++) {
////        int x = (int)app::getWindowWidth()/(i*100);
////        int y = (int)app::getWindowHeight()/(i*100);
//        int x = 1024/(i+1);
//        int y = 768/(i+1);
//        players[i-1] = new Player(x,y);
//    }
    //call constructors for two teams
//    ball = new Ball();
    activePlayer = homeTeam->players[0]; //using overloaded [] operator
    activePlayer->isActive = true;
//    switchPlayer();
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
    for(int i=0;i<11;i++) {
        double distToBall = sqrt( pow((ball->loc.x - homeTeam->players[i]->loc.x), 2) + pow((ball->loc.y - homeTeam->players[i]->loc.y), 2) );
        if( distToBall < minDistance) {
            closestPlayer = i;
            minDistance = distToBall;
        }
    }
    return homeTeam->players[closestPlayer];
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
        ball->speed = ball->maxSpeed;
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
//    for(int i=0;i<5;i++) {
//        players[i]->update();
//    }
    homeTeam->update(activePlayer);
//    ball->update(players, activePlayer);
}

void GameController::draw() {
    for(int i=0;i<11;i++) {
        homeTeam->players[i]->draw();
//        awayTeam->players[i]->draw();
    }
//    ball->draw();
}