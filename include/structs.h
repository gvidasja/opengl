#pragma once

struct point {
  double x, y, z;
  point(double x, double y, double z): x(x), y(y), z(z) {}
  point(): point(0, 0, 0) {}

  point add(point &p);
  point multiply(double k);
};

struct color {
  int r,g,b;
  color(int r, int g, int b): r(r), g(g), b(b) {}
  color(): color(0,0,0) {}
};
