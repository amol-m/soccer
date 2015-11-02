//
//  Team.h
//  soccerGame
//
//  Created by Amol Mane on 10/26/15.
//
//

#ifndef __soccerGame__Team__
#define __soccerGame__Team__

#include <stdio.h>

#include <utility>
#include <iostream>
#include <vector>

#include "Player.h"
#include "Formation.h"

using namespace std;

class Team {
public:
    Team();
    Team(string formationCode);
    int color;
//    Formation formations;
    vector<pair<int, int> > formation {
        {1,5},
        {2,2},
        {2,4},
        {2,6},
        {2,8},
        {3,5},
        {4,4},
        {4,6},
        {6,2},
        {6,8},
        {7,5},
    };
    Player* players[11];
    void update(Player* activePlayer);
    
private:
    //initial positioning
    int gridTop = 1;
    int gridBottom = 9;
    int numRows = gridBottom + gridTop;
    int gridLeft = 1;
    int gridRight = 7;
    int numCols = gridRight - gridLeft;
    int windowWidth = 1024;
    int windowHeight = 768;
    int rowHeight = windowHeight/numRows;
    int colWidth = windowWidth/(numCols*2);
    
    //player movements helper
    int idealLineLength = 500;
    int idealLineHeight = 300;
    int numOutfieldCols = numCols -1;
    int outfieldColWidth = idealLineLength/numOutfieldCols;
    int oppDefensiveLine = 900;
    int defensiveEndLine = idealLineHeight; //later, add code for opponent's last player's line
    
};

#endif /* defined(__soccerGame__Team__) */
