#pragma once

#include <graphics.h>

void drawTriangle(point p1, point p2, point p3, color c) {
  glColor3f((float) c.r / 255, (float) c.g / 255, (float) c.b / 255);

  glBegin(GL_TRIANGLES);
    glVertex3f(p1.x, p1.y, p1.z);
    glVertex3f(p2.x, p2.y, p2.z);
    glVertex3f(p3.x, p3.y, p3.z);
  glEnd();
}

void drawRectangle(point bl, point tl, point tr, point br, color c) {
  drawTriangle(bl, tl, br, c);
  drawTriangle(tl, tr, br, c);
}

void drawCube(point p1, point p2, color c1, color c2, color c3) {
  point blf(p1.x, p1.y, p1.z);
  point blb(p1.x, p1.y, p2.z);
  point brf(p2.x, p1.y, p1.z);
  point brb(p2.x, p1.y, p2.z);
  point tlf(p1.x, p2.y, p1.z);
  point tlb(p1.x, p2.y, p2.z);
  point trf(p2.x, p2.y, p1.z);
  point trb(p2.x, p2.y, p2.z);


  drawRectangle(blb, tlb, trb, brb, c1); // back
  drawRectangle(blf, tlf, trf, brf, c1); // front
  drawRectangle(blf, tlf, tlb, blb, c2); // left
  drawRectangle(brf, trf, trb, brb, c2); // right
  drawRectangle(tlf, tlb, trb, trf, c3); // top
  drawRectangle(blf, blb, brb, brf, c3); // botom
}
