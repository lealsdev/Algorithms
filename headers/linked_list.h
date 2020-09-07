#include "node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace collections {

  template <typename T>
  class LinkedList {
    private:
      Node<T> *_head;
      Node<T> *_tail;
      int _length;

    public:
      LinkedList();
      ~LinkedList();
      void add(T value);
      void insert(T value, int index);
      void remove(int index);
      void reverse();
      T* traverse();
      Node<T>* getBy(int index);      
      Node<T>* getTail();
      Node<T>* getHead();
      int getLength();
      void clean();
  };

}

#include "../source/linked_list.tpp"

#endif