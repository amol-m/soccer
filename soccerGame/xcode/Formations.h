//
//  Formations.h
//  soccerGame
//
//  Created by Amol Mane on 10/30/15.
//
//

#ifndef __soccerGame__Formations__
#define __soccerGame__Formations__

#include <stdio.h>
#include <map>
#include <vector>
#include <utility>
#include <string>

using namespace std;

class Formations {
public:
    Formations();
    int* getFormation(int formationCode);
    //edit formation
    //custom formation
private:
    void createCatalogue();
//    map< string, vector< pair<int, int> > > formationsCatalogue = {
//        { "4-3-3",
//        make_pair(1,5)
//            
//        }
//    };
    
};

#endif /* defined(__soccerGame__Formations__) */
