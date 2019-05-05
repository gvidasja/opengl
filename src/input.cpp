#include <input.h>

Input::Input(): _keys(new map<KEY, bool>()) {}

Input::~Input()
{
  if (_keys != nullptr)
  {
    delete _keys;
  }
}

void Input::onCharactedDown(unsigned char key)
{
  executeIfExists(&_CHARS_MAP, key, &Input::pressKey);
}

void Input::onCharactedUp(unsigned char key)
{
  executeIfExists(&_CHARS_MAP, key, &Input::releaseKey);
}

void Input::onKeyDown(int key)
{
  executeIfExists(&_KEYBOARD_MAP, key, &Input::pressKey);
}

void Input::onKeyUp(int key)
{
  executeIfExists(&_KEYBOARD_MAP, key, &Input::releaseKey);
}

void Input::pressKey(KEY key) {
  _keys->operator[](key) = true;
}

void Input::releaseKey(KEY key) {
  _keys->operator[](key) = false;
}

bool Input::pressed(KEY key) {
  return _keys->operator[](key);
}

void Input::executeIfExists(const map<int, KEY>* map, int key, void (Input::* action)(KEY))
{
  auto mappedChar = map->find(key);

  if (mappedChar != map->end()) {
    (this->*action)(mappedChar->second);
  }
}
