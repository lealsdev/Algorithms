#ifndef NODE_H
#define NODE_H

namespace collections {

  template <typename T>
  class node {
    private:
      T _value;
      node<T> *_next;

    public:
      node(T value);
      ~node();
      node<T>* getNext();    
      void setNext(node<T>*);
      T getValue();
  };
  
}

#include "../source/node.tpp"

#endif