#ifndef Node_H
#define Node_H

namespace collections {

  template <typename T>
  class Node {
    private:
      T _value;
      Node<T> *_next;

    public:
      Node(T value);
      ~Node();
      Node<T>* getNext();    
      void setNext(Node<T>*);
      T getValue();
      Node<T>* clone();
  };
  
}

#include "../source/node.tpp"

#endif