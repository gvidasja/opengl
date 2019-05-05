#include <structs.h>

point point::add(point &p) {
  return point(x + p.x, y + p.y, z + p.z);
}

point point::multiply(double k) {
  return point(x * k, y * k, z * k);
}
