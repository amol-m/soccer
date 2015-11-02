//
//  Team.cpp
//  soccerGame
//
//  Created by Amol Mane on 10/26/15.
//
//

#include <cmath>

#include "Team.h"
#include "Player.h"

Team::Team() {
    for (int i = 0; i < 11; i++) {
        players[i] = new Player(formation[i].first, formation[i].second, formation[i].first * colWidth, (formation[i].second) * rowHeight);
    }
}

void Team::update(Player* activePlayer) {
    for(int i=0; i<11 ; i++) {
        Player* currentPlayer = players[i];
        if(currentPlayer->isActive) {
            if (currentPlayer->dir.y)
                currentPlayer->loc.y -= currentPlayer->speed;
            if (currentPlayer->dir.w)
                currentPlayer->loc.y += currentPlayer->speed;
            if (currentPlayer->dir.x)
                currentPlayer->loc.x += currentPlayer->speed;
            if (currentPlayer->dir.z)
                currentPlayer->loc.x -= currentPlayer->speed;
        }
        else {
            int gridDiff = currentPlayer->grid.x - activePlayer->grid.x;
            currentPlayer->targetLoc.x = activePlayer->loc.x + gridDiff * outfieldColWidth;
            
            if(currentPlayer->grid.x == 2) {
                if(currentPlayer->loc.x > defensiveEndLine) {
                    currentPlayer->targetLoc.x = defensiveEndLine;
                }
            }
            if(currentPlayer->loc.x > oppDefensiveLine - outfieldColWidth * (gridRight - currentPlayer->grid.x)) {
                currentPlayer->targetLoc.x = oppDefensiveLine - outfieldColWidth * (gridRight - currentPlayer->grid.x);
            }
            //code to dodge from other players, find space
            
            //below: code to move the player
            int xDiff = currentPlayer->targetLoc.x - currentPlayer->loc.x;
            int yDiff = currentPlayer->loc.y - currentPlayer->loc.y;
            int distance = sqrt(pow(xDiff, 2) + pow(yDiff, 2));
            int normalizedX = 0, normalizedY = 0;
            if(distance != 0) {
                normalizedX = xDiff / distance;
                normalizedY = yDiff / distance;
            }
            
            currentPlayer->loc.x += normalizedX;
            currentPlayer->loc.y += normalizedY;
        }
    }
}

