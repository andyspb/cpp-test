template<typename T>
class MyDeque {
  public:
    MyDeque();
    MyDeque(MyDeque &degue);
    MyDeque operator=(MyDeque &degue);

  public:
    T * pop_front();
    void push_pront(T);
    T * pop_back();
    void push_back(T);
    T * back();
    T * front();
    void Erase();
    void IsEmpty();
  private:
    T * begin;
    T * end;

};

//MyDeque::MyDeque()
//{
//    begin == NULL;
//    end = NULL;
//}
