namespace collections {

  template <typename T>
  Queue<T>::Queue() {
    this->_data = new LinkedList<T>();
    this->_length = 0;
  }

  template <typename T>
  Queue<T>::~Queue() {
    delete(this->_data);
  }

  template <typename T>
  void Queue<T>::enqueue(T value) {
    this->_data->add(value);

    return;
  }

  template <typename T>
  Node<T>* Queue<T>::dequeue() {
    Node<T>* next = this->_data->getBy(0);
    Node<T>* nextInLine = new Node(next->getValue());

    if(nextInLine == nullptr) {
      return nullptr;
    }

    this->_data->remove(0);

    return nextInLine;
  }

  template <typename T>
  Node<T>* Queue<T>::checkNext() {
    Node<T>* next = this->_data->getBy(0);

    return next;
  }

  template <typename T>
  bool Queue<T>::is_empty() {
    return this->_data->getLength() == 0;
  }
}