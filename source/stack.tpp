namespace collections {
  
  template <typename T>
  Stack<T>::Stack() {
    this->_data = new LinkedList<T>();
  }

  template <typename T>
  Stack<T>::~Stack() {
    delete(this->_data);
  }

  template <typename T>
  void Stack<T>::push(T value) {
    this->_data->insert(value, 0);
  }

  template <typename T>
  Node<T>* Stack<T>::pop() {
    Node<T>* top = this->_data->getBy(0);

    if(top == nullptr) {
      return nullptr;
    }

    Node<T>* clonedTop = top->clone();

    this->_data->remove(0);

    return clonedTop;
  }

  template <typename T>
  Node<T>* Stack<T>::checkTop() {
    Node<T>* top = this->_data->getBy(0);

    return top;
  }

  template <typename T>
  bool Stack<T>::isEmpty() {
    //std::cout << "len: " << this->_data->getLength() << std::endl;
    return this->_data->getLength() == 0;
  }

}