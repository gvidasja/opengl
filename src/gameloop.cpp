#include <gameloop.h>

GameLoop::GameLoop(double frameRate, Game* game):
  _game(game),
  _frameLength(1 / frameRate * CLOCKS_PER_SEC),
  _timePassed(0),
  _framesPassed(0),
  _lastFrameTime(clock())
{}

GameLoop::~GameLoop()
{
  if (_game != nullptr)
  {
    delete _game;
  }
}

void GameLoop::idle() {
  auto currentTime = clock();
  _timePassed += (double)(currentTime - _lastFrameTime);
  _lastFrameTime = currentTime;

  if (_timePassed > (double) _frameLength) {
    _timePassed -= _frameLength;
    _framesPassed++;
    _game->update();
    glutPostRedisplay();
  }
};
