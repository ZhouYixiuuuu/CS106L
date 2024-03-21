/*
Assignment 2: Marriage Pact

This assignment asks you to discover your one true love using containers and
pointers. There are two parts: implement get_applicants and find_matches.

Submit to Paperless by 11:59pm on 2/1/2024.
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

std::set<std::string> get_applicants(std::string filename) {
  // TODO: Implement this function. Feel free to change std::set to
  // std::unordered_set if you wish!
  std::set<std::string> res;
  std::ifstream ifs(filename);
  std::string name;
  while (std::getline(ifs, name)) {
    res.insert(name);
    // std::cout << name << '\n';
  }
  return res;
}

std::queue<std::string *> find_matches(std::set<std::string> &students) {
  // TODO: Implement this function.
  std::queue<std::string *> q;
  for (auto it = students.begin(); it != students.end(); it++) {
    const std::string *ptr = &*it;
    std::string name = *it;
    auto secondlo = std::find(name.begin(), name.end(), ' ') + 1;
    auto firstlo = name.begin();
    if (*firstlo == 'B' && *secondlo == 'L') {
      q.push(const_cast<std::string *>(ptr));
    }
  }

  return q;
}

int main() {
  // Your code goes here. Don't forget to print your true love!
  std::string path = "/mnt/hgfs/share_Ubuntu/CS106L/Assignment2/"
                     "marriagepact_starter/students.txt";
  std::set<std::string> s = get_applicants(path);

  auto match = find_matches(s);
  if (match.size() == 0) {
    std::cout << "NO STUDENT FOUND.\n";
  } else {
    while (match.size()) {
      std::cout << *match.front() << "\n";
      match.pop();
    }
  }

  return 0;
}
