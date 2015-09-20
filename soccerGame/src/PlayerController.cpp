//
//  PlayerController.cpp
//  soccerGame
//
//  Created by Amol Mane on 9/19/15.
//
//

#include "PlayerController.h"
#include "cinder/app/AppBasic.h"


PlayerController::PlayerController() {
    
}

void PlayerController::createTeams(int side1) {
    for(int i=0;i<side1;i++) {
        float x = app::getWindowWidth()/(i*100);
        float y = app::getWindowHeight()/(i*100);
        players.push_back(Player(x,y));
    }
    players.begin()->isActive = true;
}

void PlayerController::switchPlayer() {
    for(list<Player>::iterator it = players.begin(); it!= players.end();++it) {
        if(it->isActive) {
            it->isActive = false;
            it->moveUp = it->moveDown = it->moveLeft = it->moveRight = false;
            ++it;
            it->isActive = true;
            return;
        }
    }
}

void PlayerController::update() {
    for(list<Player>::iterator it = players.begin(); it!= players.end();++it) {
        it->update();
    }
}

void PlayerController::draw() {
    for(list<Player>::iterator it = players.begin(); it!= players.end();++it) {
        it->draw();
    }
}