#pragma once

#include <game.h>

class GameLoop {
private:
  Game* _game;
  int _frameLength, _framesPassed;
  double _timePassed;
  clock_t _lastFrameTime;

public:
  GameLoop(double frameRate, Game* game);
  ~GameLoop();
  void idle();
};
