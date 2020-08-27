namespace collections {

  template <typename T>
  queue<T>::queue() {
    this->_data = new linked_list<T>();
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
  node<T>* queue<T>::dequeue() {
    node<T>* next = this->_data->getBy(0)->getValue();
    node<T>* nextInLine = new node();

    if(nextInLine == nullptr) {
      return nullptr;
    }

    this->_data->remove(0);

    return nextInLine;
  }

  template <typename T>
  node<T>* queue<T>::checkNext() {
    node<T>* next = this->_data->getBy(0);

    return next;
  }

  template <typename T>
  bool queue<T>::is_empty() {
    return this->_data->getLength() == 0;
  }
}