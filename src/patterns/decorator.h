#ifndef _DECORATOR_H_
#define _DECORATOR_H_

#include <iostream>
#include <string>

namespace decorator {
class Window {
  public:
    virtual ~Window() {}
    virtual void draw() = 0; // draws the Window
    virtual  std::string getDescription() = 0; // returns a description of the Window
};

// implementation of a simple Window without any scrollbars
class SimpleWindow: public Window {
  public:
    virtual ~SimpleWindow() {}
    void draw() {
      // draw window
    }
    std::string getDescription() {
      std::string str = "simple window";
      return str;
    }
};

//The following classes contain the decorators for all Window classes, including the decorator classes themselves..
// abstract decorator class - note that it implements Window
class WindowDecorator: public Window {
  public:
    virtual ~WindowDecorator() {}
    WindowDecorator(Window * decoratedWindow) {
      this->decoratedWindow = decoratedWindow;
    }
    void draw() {
      decoratedWindow->draw();
    }
  protected:
    Window * decoratedWindow; // the Window being decorated
};

// the first concrete decorator which adds vertical scrollbar functionality
class VerticalScrollBarDecorator: public WindowDecorator {
  public:
    virtual ~VerticalScrollBarDecorator() {}
    VerticalScrollBarDecorator(Window * decoratedWindow)
        : WindowDecorator(decoratedWindow) {
    }
    void draw() {
      drawVerticalScrollBar();
      WindowDecorator::draw();
    }
    std::string getDescription() {
      std::string str = decoratedWindow->getDescription()
          + ", including vertical scrollbars";
      return str;
    }
  private:
    void drawVerticalScrollBar() {
      // draw the vertical scrollbar
    }
};

// the second concrete decorator which adds horizontal scrollbar functionality
class HorizontalScrollBarDecorator: public WindowDecorator {
  public:
    HorizontalScrollBarDecorator(Window *decoratedWindow)
        : WindowDecorator(decoratedWindow) {
    }
    void draw() {
      drawHorizontalScrollBar();
      WindowDecorator::draw();
    }
    std::string getDescription() {
      std::string str = decoratedWindow->getDescription()
          + ", including horizontal scrollbars";
      return str;
    }

  private:
    void drawHorizontalScrollBar() {
      // draw the horizontal scrollbar
    }
};

//Here's a test program that creates a Window instance which is fully decorated (i.e., with vertical and horizontal scrollbars), and prints its description:
int test() {
  std::cout << "Test: Decorator pattern example --->" << std::endl;
  // create a decorated Window with horizontal and vertical scrollbars
  Window * decoratedWindow = new HorizontalScrollBarDecorator(
      new VerticalScrollBarDecorator(new SimpleWindow()));
  // print the Window's description
  std::cout <<  decoratedWindow->getDescription() << std::endl;
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
} // namspace decorator

#endif // _DECORATOR_H_
