#ifndef STACK_H
#define STACK_H

#include "linked_list.h"
#include "node.h"

namespace collections {

  template <typename T>
  class stack {
    private:
      LinkedList<T>* _data;
      Node<T>* get_cloned_top() {
        Node<T>* top = this->_data->getBy(0);
        Node<T>* newTop = new Node<T>(top->getValue());
        
        return newTop;
      }

    public:
      stack();
      ~stack();
      void push(T value);
      Node<T>* pop();
      Node<T>* checkTop();
      bool is_empty();
  };

}

#include "../source/stack.tpp"

#endif