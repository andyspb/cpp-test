/*
 * serialization.h
 *
 *  Created on: Apr 19, 2016
 *      Author: andy
 */

#ifndef SRC_SERIALIZATION_SERIALIZATION_H_
#define SRC_SERIALIZATION_SERIALIZATION_H_

#include <functional>

namespace serialization {

//template<class Container>
class Serializable {
  typedef std::function<void(const string&)> Func;
 public:
  virtual ~Serializable() {
  }
  virtual void Serialize() {
    for (auto& lv_Ser : m_Serializers)
      lv_Ser.second.Serializer(lv_Ser.first);
  }

  virtual void Deserialize() {
    for (auto& lv_Ser : m_Serializers)
      lv_Ser.second.Deserializer(lv_Ser.first);
  }

 protected:
  struct SerializerPair {
    Func Serializer;
    Func Deserializer;
  };

  char Add(string _key, Func _serializer, Func _deserializer) {
    auto& lv_Pair = m_Serializers[_key];
    lv_Pair.Serializer = _serializer;
    lv_Pair.Deserializer = _deserializer;
    return 0;
  }

 private:
  map<string, SerializerPair> m_Serializers;
};

#define UNNAMED_IMPL(x, y) UNNAMED_##x##_##y
#define UNNAMED_DECL(x, y) UNNAMED_IMPL(x, y)
#define UNNAMED UNNAMED_DECL(__LINE__ , __COUNTER__)

#define serialize(x) char UNNAMED = Add   \
(                     \
  #x,                      \
  [this](const string& _key)          \
  {                      \
    Serialize(_key, x);     \
  },                      \
  [this](const string& _key)  \
  {                   \
    Deserialize(_key, x);     \
  }                   \
)

class TestClass : public Serializable {
 public:
  int SomeInt = 666;

 private:
  serialize(SomeInt);
};

TEST_RESULT test() {
   RETURN_OK();
}

}  // namespace serialization

#endif /* SRC_SERIALIZATION_SERIALIZATION_H_ */
