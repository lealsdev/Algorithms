#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"
#include "node.h"

namespace collections {

  template <typename T>
  class Queue {
    private:
      LinkedList<T>* _data;
      int _length;

    public:
      Queue();
      ~Queue();
      void enqueue(T value);
      Node<T>* dequeue();
      Node<T>* checkNext();
      bool is_empty();
  };
}

#include "../source/queue.tpp"

#endif