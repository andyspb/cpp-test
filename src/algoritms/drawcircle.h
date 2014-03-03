#ifndef _DRAWCIRCLE_H
#define _DRAWCIRCLE_H

#include <math.h>

namespace drawcircle {
int min(int a, int b) {
  return a > b ? b : a;
}

int max(int a, int b) {
  return a > b ? a : b;
}

void draw_point(int x, int y, int x0, int y0, int r) {
  std::cout << "draw point (" << x << "," << y << " -- " << x0 << "," << y0
            << " radius=" << r << std::endl;
}

int test() {
  std::cout << "Test: Drawcircle example --->" << std::endl;
  int x = 0, y = 0, r = 50000;
  int xi, yi;
  for (xi = 0, yi = r; xi <= r && yi >= 0; ++xi, --yi) {
    if (max((xi * xi + yi * yi), r * r) - min((xi * xi + yi * yi), r * r) == 0)
      draw_point(xi, yi, x, y, r);
  }
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace drawcircle

#endif // _DRAWCIRCLE_H
