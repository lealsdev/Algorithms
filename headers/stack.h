#ifndef STACK_H
#define STACK_H

#include "linked_list.h"
#include "node.h"

namespace collections {

  template <typename T>
  class stack {
    private:
      linked_list<T>* _data;
      node<T>* get_cloned_top() {
        node<T>* top = this->_data->getBy(0);
        node<T>* newTop = new node<T>(top->getValue());
        
        return newTop;
      }

    public:
      stack();
      ~stack();
      void push(T value);
      node<T>* pop();
      node<T>* checkTop();
      bool is_empty();
  };

}

#include "../source/stack.tpp"

#endif