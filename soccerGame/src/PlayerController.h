//
//  PlayerController.h
//  soccerGame
//
//  Created by Amol Mane on 9/19/15.
//
//

#ifndef __soccerGame__PlayerController__
#define __soccerGame__PlayerController__

#include <stdio.h>
#include "Player.h"
class PlayerController {
public:
    PlayerController();
    void createTeams(int side1);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void switchPlayer();
    void update();
    void draw();
    
    std::list<Player> players;
private:
    
};

#endif /* defined(__soccerGame__PlayerController__) */

