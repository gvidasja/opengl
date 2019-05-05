#include <game.h>

Game::Game(InputReader* input): _input(input) {}

Game::~Game() {
  if (_input != nullptr)
  {
    delete _input;
  }
}

void Game::update()
{
  if (_input->pressed(ARROW_RIGHT)) _rotationY -= ROTATION_SPEED;
  if (_input->pressed(ARROW_LEFT)) _rotationY += ROTATION_SPEED;
  if (_input->pressed(ARROW_DOWN)) _rotationX -= ROTATION_SPEED;
  if (_input->pressed(ARROW_UP)) _rotationX += ROTATION_SPEED;
}

void Game::draw()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, (double) glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT), 1, 1024);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glClearColor(0.05, 0.05, 0.1, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  auto cubePosition = point(0, 0, -5);

  glPushMatrix();
  glTranslatef(cubePosition.x, cubePosition.y, cubePosition.z);
  glRotatef(_rotationX, 1.0, 0.0, 0.0);
  glRotatef(_rotationY, 0.0, 1.0, 0.0);

  auto cube1 = point(-CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE);
  auto cube2 = point(CUBE_SIZE, CUBE_SIZE, CUBE_SIZE);
  drawCube(cube1, cube2, color(200, 80, 20), color(80, 20, 200), color(20, 200, 80));

  glTranslatef(-cubePosition.x, -cubePosition.y, -cubePosition.z);
  glPopMatrix();

  auto floor_size = 0.8;
  auto floor_height = -0.5;
  drawRectangle(
    point(-floor_size, floor_height, -floor_size),
    point(-floor_size, floor_height, floor_size),
    point(floor_size, floor_height, floor_size),
    point(floor_size, floor_height, -floor_size),
    color(240, 180, 50)
  );

  glutSwapBuffers();
}
