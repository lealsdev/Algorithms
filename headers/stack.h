#ifndef STACK_H
#define STACK_H

#include "linked_list.h"
#include "node.h"

namespace collections {

  template <typename T>
  class Stack {
    private:
      LinkedList<T>* _data;
      Node<T>* getClonedTop() {
        Node<T>* top = this->_data->getBy(0);
        Node<T>* newTop = new Node<T>(top->getValue());
        
        return newTop;
      }

    public:
      Stack();
      ~Stack();
      void push(T value);
      Node<T>* pop();
      Node<T>* checkTop();
      bool isEmpty();
  };

}

#include "../source/stack.tpp"

#endif