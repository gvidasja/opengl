#pragma once

#include <map>
#include <GL/glut.h>

using namespace std;

enum KEY {
  ARROW_UP,
  ARROW_DOWN,
  ARROW_LEFT,
  ARROW_RIGHT,
  W,
  A,
  S,
  D
};

class InputReader {
public:
  virtual bool pressed(KEY key) = 0;
};

class Input : public InputReader {
private:
  const map<int, KEY> _KEYBOARD_MAP {
    {GLUT_KEY_UP, KEY::ARROW_UP},
    {GLUT_KEY_DOWN, KEY::ARROW_DOWN},
    {GLUT_KEY_LEFT, KEY::ARROW_LEFT},
    {GLUT_KEY_RIGHT, KEY::ARROW_RIGHT}
  };

  const map<int, KEY> _CHARS_MAP {
    {'w', KEY::W},
    {'a', KEY::A},
    {'s', KEY::S},
    {'d', KEY::D}
  };

  map<KEY, bool>* _keys;

  void executeIfExists(const map<int, KEY>* map, int key, void (Input::* action)(KEY));
  void pressKey(KEY key);
  void releaseKey(KEY key);

public:
  Input();
  ~Input();
  void onCharactedDown(unsigned char key);
  void onCharactedUp(unsigned char key);
  void onKeyDown(int key);
  void onKeyUp(int key);
  bool pressed(KEY key);
};
