namespace collections {

  template <typename T>
  queue<T>::queue() {
    this->_data = new LinkedList<T>();
    this->_length = 0;
  }

  template <typename T>
  queue<T>::~queue() {
    delete(this->_data);
  }

  template <typename T>
  void queue<T>::enqueue(T value) {
    this->_data->add(value);

    return;
  }

  template <typename T>
  Node<T>* queue<T>::dequeue() {
    Node<T>* next = this->_data->getBy(0);
    Node<T>* nextInLine = new Node(next->getValue());

    if(nextInLine == nullptr) {
      return nullptr;
    }

    this->_data->remove(0);

    return nextInLine;
  }

  template <typename T>
  Node<T>* queue<T>::checkNext() {
    Node<T>* next = this->_data->getBy(0);

    return next;
  }

  template <typename T>
  bool queue<T>::is_empty() {
    return this->_data->getLength() == 0;
  }
}