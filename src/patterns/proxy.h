#ifndef _PROXY_H_
#define _PROXY_H_

#include <iostream>

namespace proxy {
class Image {
  public:
    virtual ~Image() {
    }
    virtual void displayImage() = 0;
};

//on System A
class RealImage: public Image {
  public:
    RealImage(std::string fn) {
      filename = fn;
      loadImageFromDisk();
    }
    void displayImage() {
      std::cout << "Displaying " << filename << std::endl;
    }
  private:
    void loadImageFromDisk() {
      std::cout << "Loading %s  " << filename << std::endl;
    }

  private:
    std::string filename;
};

//on System B
class ProxyImage: public Image {
  public:
    ProxyImage(std::string fn)
        : filename(fn), image(0) {
    }
    ~ProxyImage() {
      if (image)
        delete (image);
    }
    void displayImage() {
      if (image == 0) {
        image = new RealImage(filename);
      }
      image->displayImage();
    }

  private:
    std::string filename;
    RealImage * image;

};

int test() {
  std::cout << "Test: Proxy pattern example --->" << std::endl;
  Image * image1 = new ProxyImage("HiRes_10MB_Photo1");
  Image * image2 = new ProxyImage("HiRes_10MB_Photo2");

  image1->displayImage(); // loading necessary
  image2->displayImage(); // loading necessary
  image1->displayImage(); // loading unnecessary

  delete (image1);
  delete (image2);
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
} // namespace proxy

#endif // _PROXY_H_
