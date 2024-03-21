// Blank header file
#include <string>
class Student {
private:
  std::string name;
  std::string id;
  int age;
public:
  Student(std::string name, std::string id, int age);
  Student();
  std::string getName();
  void setName(std::string name);
  void print();
  ~Student();
};