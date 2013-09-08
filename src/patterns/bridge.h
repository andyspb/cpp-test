#ifndef _BRIDGE_H_
#define _BRIDGE_H_

#include <iostream>

namespace bridge {
/** "Implementor" */
class DrawingAPI {
  public:
    virtual ~DrawingAPI() {
    }
    virtual void drawCircle(double x, double y, double radius) = 0;
};

/** "ConcreteImplementor" 1/2 */
class DrawingAPI1: public DrawingAPI {
  public:
    DrawingAPI1() {
    }

    virtual ~DrawingAPI1() {
    }

    void drawCircle(double x, double y, double radius) {
      std::cout << "API1.circle at " << x << ":" << y <<" radius " << radius << std::endl;
    }
};

/** "ConcreteImplementor" 2/2 */
class DrawingAPI2: public DrawingAPI {
  public:
    DrawingAPI2() {
    }

    virtual ~DrawingAPI2() {
    }

    void drawCircle(double x, double y, double radius) {
      std::cout << "API2.circle at "<< x << ":" << ":" << y << " radius " << radius << std::endl;
    }
};

// Note: this example does not follow the "structure" specified above.
// In particular, that this class "maintains the Implementor reference"
/** "Abstraction" */
class Shape {
  public:
    virtual void draw()= 0; // low-level
    virtual void resizeByPercentage(double pct) = 0; // high-level
    virtual ~Shape() {
    }
};

/** "Refined Abstraction" */
class CircleShape: public Shape {
  public:
    CircleShape(double x, double y, double radius, DrawingAPI& drawingAPI)
        : x(x), y(y), radius(radius), drawingAPI(drawingAPI) {
    }

    virtual ~CircleShape() {
    }

    // low-level i.e. Implementation specific
    void draw() {
      drawingAPI.drawCircle(x, y, radius);
    }
    // high-level i.e. Abstraction specific
    void resizeByPercentage(double pct) {
      radius *= pct;
    }
  private:
    double x, y, radius;
    DrawingAPI& drawingAPI;
};

int test(int argc = 0, char* argv[] = 0) {
  std::cout << "Test: Bridge pattern example --->" << std::endl;
  DrawingAPI1 api1;
  DrawingAPI2 api2;

  CircleShape c1(1, 2, 3, api1);
  CircleShape c2(5, 7, 11, api2);

  Shape* shapes[2];
  shapes[0] = &c1;
  shapes[1] = &c2;

  shapes[0]->resizeByPercentage(2.5);
  shapes[0]->draw();
  shapes[1]->resizeByPercentage(2.5);
  shapes[1]->draw();

  std::cout << "<--- test passed " << std::endl;
  return 1;
}
} // namespace bridge

#endif // _BRIDGE_H_
