#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"
#include "node.h"

namespace collections {

  template <typename T>
  class queue {
    private:
      linked_list<T>* _data;

    public:
      queue();
      ~queue();
      void enqueue(T value);
      Node<T>* dequeue();
      Node<T>* checkNext();
      bool isEmpty();
  }

}

#include "../source/queue.tpp"

#endif