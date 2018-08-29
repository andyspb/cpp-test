// Visitor classes (step 1)
struct IVisitor {
  virtual ~IVisitor() {
  }
  virtual void visit(Foo*) = 0;
  virtual void visit(Bar*) = 0;
  virtual void visit(Baz*) = 0;
};

template<class T>
class VisitorT : public IVisitor {
 public:
  typedef T value_type;
  virtual ~VisitorT() {
  }
  virtual void accept(T* t) const = 0;

  explicit VisitorT(int id) {
    VisitorTable < T > ::insert(id, this);
  }
};

class Element {
 public:
  virtual ~Element() {
  }
  virtual void visit(int id) = 0;  // or string or whatever id type you are using
};

template<class T>
class ElementT : public Element {
 private:
  T* concrete_this;

 protected:
  explicit ElementT(T* ptr)
      : concrete_this(ptr) {
  }

 public:
  void visit(int id) {
    const Visitor<T>* visitor = VisitorTable < T > ::lookup(id);  // to be implemented for each T
    if (visitor)
      visitor->accept(concrete_this);
  }
};
