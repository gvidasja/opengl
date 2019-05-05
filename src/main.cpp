#define GL_GLEXT_PROTOTYPES
#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <game.h>
#include <input.h>
#include <gameloop.h>

const int FRAME_RATE = 60;

using namespace std;

Input* input;
Game* game;
GameLoop* gameLoop;

void reshapeFunc(int width, int height) {
  glViewport(0, 0, width, height);
}

void drawFunc() {
  game->draw();
}

void specialFunc(int key, int x, int y) {
  input->onKeyDown(key);
}

void specialUpFunc(int key, int x, int y) {
  input->onKeyUp(key);
}

void keyboardFunc(unsigned char key, int x, int y) {
  input->onCharactedDown(key);
}

void keyboardUpFunc(unsigned char key, int x, int y) {
  input->onCharactedUp(key);
}

void idleFunc() {
  gameLoop->idle();
}

void registerGlutFunctions()
{
  glutDisplayFunc(drawFunc);
  glutSpecialFunc(specialFunc);
  glutSpecialUpFunc(specialUpFunc);
  glutKeyboardFunc(keyboardFunc);
  glutKeyboardUpFunc(keyboardUpFunc);
  glutReshapeFunc(reshapeFunc);
  glutIdleFunc(idleFunc);
}

int main(int argc, char** argv)
{
  input = new Input();
  game = new Game(input);
  gameLoop = new GameLoop(60, game);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

  glutCreateWindow("Cube");

  glEnable(GL_DEPTH_TEST);

  registerGlutFunctions();

  glutReshapeWindow(640, 360);

  glutMainLoop();

  delete game;
  delete input;
  delete gameLoop;

  return 0;
}
