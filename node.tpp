
namespace collections {

  template <typename T>
  node<T>::node(T value) {
    this->_value = value;
  }

  template <typename T>
  node<T>::~node() {
    std::cout << "cleaning node" << std::endl;
  }

  template <typename T>
  node<T>* node<T>::getNext() {
    return this->_next;
  }

  template <typename T>
  void node<T>::setNext(node<T>* next) {
    this->_next = next;
  }

  template <typename T>
  T node<T>::getValue() {
    return this->_value;
  }

}