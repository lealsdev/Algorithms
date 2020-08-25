namespace collections {
  
  template <typename T>
  stack<T>::stack() {
    this->_data = new linked_list<T>();
  }

  template <typename T>
  stack<T>::~stack() {
    delete(this->_data);
  }

  template <typename T>
  void stack<T>::push(T value) {
    this->_data->insert(value, 0);
  }

  template <typename T>
  node<T>* stack<T>::pop() {
    node<T>* top = this->_data->getBy(0);

    if(top == nullptr) {
      return nullptr;
    }

    node<T>* clonedTop = top->clone();

    this->_data->remove(0);

    return clonedTop;
  }

  template <typename T>
  node<T>* stack<T>::checkTop() {
    node<T>* top = this->_data->getBy(0);

    return top;
  }

  template <typename T>
  bool stack<T>::is_empty() {
    //std::cout << "len: " << this->_data->getLength() << std::endl;
    return this->_data->getLength() == 0;
  }

}