#include <iostream>

#include "MutantStack.hpp"

int main() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << "Stack top : " << mstack.top() << std::endl;
  mstack.pop();
  std::cout << "Stack size : " << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  std::cout << "Stack size : " << mstack.size() << std::endl;
  while (it != ite) {
    std::cout << "Iterator : " << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  std::cout << "====== STRING STACK =====" << std::endl;

  MutantStack<std::string> sstack;

  sstack.push("Hello");
  sstack.push("Hello-");
  sstack.push("Hello--");
  sstack.push("Hello---");
  sstack.push("Hello----");
  sstack.push("Hello-----");
  MutantStack<std::string>::iterator sit = sstack.begin();
  MutantStack<std::string>::iterator site = sstack.end();
  std::cout << "String Stack size : " << sstack.size() << std::endl;
  while (sit != site) {
    std::cout << "Iterator : " << *sit << std::endl;
    ++sit;
  }
}
