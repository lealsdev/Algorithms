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
    node<T>* newTop = this->get_cloned_top();

    this->_data->remove(0);

    return newTop;
  }

  template <typename T>
  node<T>* stack<T>::checkTop() {
    node<T>* newTop = this->get_cloned_top();

    return newTop;
  }

  template <typename T>
  bool stack<T>::is_empty() {
    //std::cout << "len: " << this->_data->getLength() << std::endl;
    return this->_data->getLength() == 0;
  }

}