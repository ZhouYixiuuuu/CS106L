// Blank cpp file
#include "class.h"
#include <iostream>

Student::Student(std::string name, std::string id, int age){
  this->name = name;
  this->id = id;
  this->age = age;
}

Student::Student(){
  this->name = "Alice";
  this->id = "2024";
  this->age = 15;
}

std::string Student::getName() {
  return this->name;
}

void Student::setName(std::string name){
  this->name = name;
}

void Student::print() {
  std::cout << "name:" << this->name << '\n';
  std::cout << "id:" << this->id << '\n';
  std::cout << "age:" << this->age << '\n';
}

Student::~Student() {
  
}