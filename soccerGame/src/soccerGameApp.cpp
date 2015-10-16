#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Player.h"
#include "GameController.h"
#include "cinder/gl/Texture.h"
#include "Ball.h"

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
    
    GameController game;
    gl::Texture background;
};

void soccerGameApp::setup() {
    app::setWindowSize(1024, 768);
    app::setFrameRate(60.0f);
    
    background = gl::Texture(loadImage(loadResource("footballField.jpg")));
}

void soccerGameApp::mouseDown( MouseEvent event ) {
}

void soccerGameApp::keyDown(cinder::app::KeyEvent event) {
    game.keyDown(event);
}

void soccerGameApp::keyUp(cinder::app::KeyEvent event) {
    game.keyUp(event);
}

void soccerGameApp::update() {
    game.update();
}

void soccerGameApp::draw() {
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    gl::draw(background);
    game.draw();
}

CINDER_APP_NATIVE( soccerGameApp, RendererGl )
