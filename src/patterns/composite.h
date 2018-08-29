#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_

#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>

namespace composite {
class Graphic {
 public:
  virtual void print() const = 0;
  virtual ~Graphic() {
  }
};

class _Ellipse : public Graphic {
 public:
  void print() const {
    std::cout << "Ellipse" << std::endl;
  }
};

class CompositeGraphic : public Graphic {
 public:
  void print() const {
    // for each element in graphicList_, call the print member function
    std::for_each(graphicList_.begin(), graphicList_.end(),
                  std::mem_fun(&Graphic::print));
  }
  void add(Graphic *aGraphic) {
    graphicList_.push_back(aGraphic);
  }
 private:
  std::vector<Graphic*> graphicList_;
};

int test() {
  std::cout << "Test: Composite pattern example --->" << std::endl;

  // Initialize four ellipses
  const std::shared_ptr<_Ellipse> ellipse1(new _Ellipse());
  const std::shared_ptr<_Ellipse> ellipse2(new _Ellipse());
  const std::shared_ptr<_Ellipse> ellipse3(new _Ellipse());
  const std::shared_ptr<_Ellipse> ellipse4(new _Ellipse());

  // Initialize three composite graphics
  const std::shared_ptr<CompositeGraphic> graphic(new CompositeGraphic());
  const std::shared_ptr<CompositeGraphic> graphic1(new CompositeGraphic());
  const std::shared_ptr<CompositeGraphic> graphic2(new CompositeGraphic());

  // Composes the graphics
  graphic1->add(ellipse1.get());
  graphic1->add(ellipse2.get());
  graphic1->add(ellipse3.get());

  graphic2->add(ellipse4.get());

  graphic->add(graphic1.get());
  graphic->add(graphic2.get());

  // Prints the complete graphic (four times the string "Ellipse")
  graphic->print();

  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace composite

#endif // _COMPOSITE_H_
