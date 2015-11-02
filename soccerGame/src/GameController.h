//
//  PlayerController.h
//  soccerGame
//
//  Created by Amol Mane on 9/19/15.
//
//

#ifndef __soccerGame__GameController__
#define __soccerGame__GameController__

#include <stdio.h>
#include "cinder/app/AppBasic.h"

#include "Player.h"
#include "Ball.h"
#include "Team.h"

class GameController {
public:
    GameController();
    void update();
    void draw();
    void keyDown(cinder::app::KeyEvent event);
    void keyUp(cinder::app::KeyEvent event);
    Player* findClosestPlayer();

    void switchPlayer();
    
    Team* homeTeam;
    Team* awayTeam;
//    Player* players[5];
    Ball* ball;
    Player* activePlayer;
    
private:
    
};

#endif /* defined(__soccerGame__GameController__) */

