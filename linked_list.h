#include "node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace collections {

  template <typename T>
  class linked_list {
    private:
      node<T> *_head;
      node<T> *_tail;
      int _length;

    public:
      linked_list();
      ~linked_list();
      void add(T value);
      void insert(T value, int index);
      node<T>* remove(int index);
      void reverse();
      T* traverse();
      node<T>* getBy(int index);      
      node<T>* getTail();
      node<T>* getHead();
      int getLength();
      void clean();
  };

}

#include "linked_list.tpp"

#endif