#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"
#include "node.h"

namespace collections {

  template <typename T>
  class queue {
    private:
      LinkedList<T>* _data;
      int _length;

    public:
      queue();
      ~queue();
      void enqueue(T value);
      Node<T>* dequeue();
      Node<T>* checkNext();
      bool is_empty();
  };
}

#include "../source/queue.tpp"

#endif