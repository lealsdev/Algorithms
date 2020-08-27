#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"
#include "node.h"

namespace collections {

  template <typename T>
  class queue {
    private:
      linked_list<T>* _data;
      int _length;

    public:
      queue();
      ~queue();
      void enqueue(T value);
      node<T>* dequeue();
      node<T>* checkNext();
      bool is_empty();
  };
}

#include "../source/queue.tpp"

#endif