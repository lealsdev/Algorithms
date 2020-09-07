
namespace collections {

  template <typename T>
  Node<T>::Node(T value) {
    this->_value = value;
  }

  template <typename T>
  Node<T>::~Node() {
    
  }

  template <typename T>
  Node<T>* Node<T>::getNext() {
    return this->_next;
  }

  template <typename T>
  void Node<T>::setNext(Node<T>* next) {
    this->_next = next;
  }

  template <typename T>
  T Node<T>::getValue() {
    return this->_value;
  }

  template <typename T>
  Node<T>* Node<T>::clone() {
    return new Node(this->_value);
  }  

}