#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Player.h"
#include "PlayerController.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class soccerGameApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );
    void keyDown(cinder::app::KeyEvent event);
    void keyUp(cinder::app::KeyEvent event);
	void update();
	void draw();
    void switchPlayer();
    
    Player team[5];
    int activePlayer = 0;
};

void soccerGameApp::setup()
{
    app::setWindowSize(1024, 768);
    app::setFrameRate(60.0f);
    for(int i=0;i<5;i++) {
        team[i] = Player(512,384);
    }
}

void soccerGameApp::mouseDown( MouseEvent event )
{
}

void soccerGameApp::keyDown(cinder::app::KeyEvent event) {
    //movement
    if( event.getCode() == KeyEvent::KEY_UP ) {
        team[activePlayer].moveUp = true;
    }
    if( event.getCode() == KeyEvent::KEY_DOWN ) {
        team[activePlayer].moveDown = true;
    }
    if( event.getCode() == KeyEvent::KEY_RIGHT ) {
        team[activePlayer].moveRight = true;
    }
    if( event.getCode() == KeyEvent::KEY_LEFT ) {
        team[activePlayer].moveLeft = true;
    }
    
    //switch player
    if( event.getCode() == KeyEvent::KEY_SPACE ) {
        switchPlayer();
    }
}

void soccerGameApp::switchPlayer() {
    if(activePlayer == sizeof(team)/sizeof(team[0]) -1) {
        activePlayer = 0;
    }
    else {
        activePlayer++;
    }
}

void soccerGameApp::keyUp(cinder::app::KeyEvent event) {
    if( event.getCode() == KeyEvent::KEY_UP ) {
        team[activePlayer].moveUp = false;
    }
    if( event.getCode() == KeyEvent::KEY_DOWN ) {
        team[activePlayer].moveDown = false;
    }
    if( event.getCode() == KeyEvent::KEY_RIGHT ) {
        team[activePlayer].moveRight = false;
    }
    if( event.getCode() == KeyEvent::KEY_LEFT ) {
        team[activePlayer].moveLeft = false;
    }
}

void soccerGameApp::update()
{
    team[activePlayer].update();
}

void soccerGameApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    for(int i=0;i<5;i++) {
        team[i].draw();
    }
}

CINDER_APP_NATIVE( soccerGameApp, RendererGl )
