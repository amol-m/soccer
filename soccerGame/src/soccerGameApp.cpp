#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Player.h"

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
    
//    PlayerController _playerController;
    Player player;
    
};

void soccerGameApp::setup()
{
    app::setWindowSize(1024, 768);
    app::setFrameRate(60.0f);
    }

void soccerGameApp::mouseDown( MouseEvent event )
{
}

void soccerGameApp::keyDown(cinder::app::KeyEvent event) {
    if( event.getCode() == KeyEvent::KEY_UP ) {
        player.moveUp = true;
    }
    if( event.getCode() == KeyEvent::KEY_DOWN ) {
        player.moveDown = true;
    }
    if( event.getCode() == KeyEvent::KEY_RIGHT ) {
        player.moveRight = true;
    }
    if( event.getCode() == KeyEvent::KEY_LEFT ) {
        player.moveLeft = true;
    }
}

void soccerGameApp::keyUp(cinder::app::KeyEvent event) {
    if( event.getCode() == KeyEvent::KEY_UP ) {
        player.moveUp = false;
    }
    if( event.getCode() == KeyEvent::KEY_DOWN ) {
        player.moveDown = false;
    }
    if( event.getCode() == KeyEvent::KEY_RIGHT ) {
        player.moveRight = false;
    }
    if( event.getCode() == KeyEvent::KEY_LEFT ) {
        player.moveLeft = false;
    }
}

void soccerGameApp::update()
{
    player.update();
}

void soccerGameApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    player.draw();
}

CINDER_APP_NATIVE( soccerGameApp, RendererGl )
