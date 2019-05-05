#pragma once

#include <map>
#include <GL/gl.h>
#include <GL/glut.h>
#include <graphics.h>
#include <input.h>

class Game {
private:
  static constexpr double CUBE_SIZE = 0.5;
  static const int ROTATION_SPEED = 4;

  int _rotationX = 0, _rotationY = 0;

  InputReader* _input;

public:
  Game(InputReader* input);
  ~Game();

  void update();
  void draw();
};
