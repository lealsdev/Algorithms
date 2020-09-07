namespace collections {

  template <typename T>
  LinkedList<T>::LinkedList() {
    this->_length = 0;
  }

  template <typename T>
  LinkedList<T>::~LinkedList() {
    this->clean();
  }

  template <typename T>
  void LinkedList<T>::add(T value) {

    if(this->_length == 0) {
      this->_head = new Node(value);
      this->_tail = this->_head;
      this->_length++;

      return;
    }

    Node<T>* newNode = new Node<T>(value);
    this->_tail->setNext(newNode);
    this->_tail = newNode;
    this->_length++;

    return;
  }

  template <typename T>
  void LinkedList<T>::insert(T value, int index) {

    if(index < 0)
      return;

    if(index == 0) {
      if(this->_length == 0) {
        this->add(value);
      }
      else {
        Node<T>* oldHead = this->_head;
        Node<T>* newHead = new Node(value);
        this->_head = newHead;
        this->_head->setNext(oldHead);
        this->_length++;
      }

      return;
    }

    if(index >= this->_length) {
      Node<T>* oldTail = this->_tail;
      Node<T>* newNode = new Node(value);

      oldTail->setNext(newNode);
      this->_tail = newNode;
      this->_length++;

      return;
    }

    Node<T>* prevNode = this->getBy(index-1);
    Node<T>* nextNode = prevNode->getNext();
    Node<T>* newNode = new Node<T>(value);

    prevNode->setNext(newNode);
    newNode->setNext(nextNode);
    
    this->_length++;
    
    return;
  }

  template <typename T>
  void LinkedList<T>::remove(int index) {
    
    if(index < 0 || index > this->_length-1) {
      return;
    }

    if(index == 0) {
      Node<T>* dataToRemove = this->_head;

      this->_head = this->_head->getNext();

      delete(dataToRemove);
      
      this->_length--;

      return;
    }

    Node<T>* prevNode = this->getBy(index-1);

    if(index == this->_length-1) {
      Node<T>* dataToRemove = this->_tail;

      this->_tail = prevNode;

      delete(dataToRemove);

      this->_length--;

      return;
    }

    Node<T>* dataToRemove = prevNode->getNext();
    prevNode->setNext(prevNode->getNext()->getNext());

    delete(dataToRemove);

    this->_length--;

    return;
  }

  template <typename T>
  void LinkedList<T>::reverse() {
    if(this->_length <= 1)
      return;
    
    Node<T>* newHead = this->_tail;
    Node<T>* newTail = this->_head;

    Node<T>* current = this->_head;
    Node<T>* first = current->getNext();
    Node<T>* second;

    int count = 0;
    while(first != nullptr) {      
      second = first->getNext();

      first->setNext(current);

      current = first;
      first = second;      
    }

    this->_head = newHead;
    this->_tail = newTail;
    this->_tail->setNext(nullptr);

    return;
  }

  template <typename T>
  T* LinkedList<T>::traverse() {

    if(this->_length == 0)
      return nullptr;

    T* buffer = (T*)malloc(this->getLength()*sizeof(T));

    int count = 0;

    Node<T>* current = this->_head;

    while(current != nullptr) {      
      buffer[count] = current->getValue();      
      current = current->getNext();
      count++;
    }

    return buffer;
  }

  template <typename T>
  Node<T>* LinkedList<T>::getBy(int index) {

    if(index < 0 || index > this->_length-1) {
      return nullptr;
    }

    Node<T>* current = this->_head;
    int count = 0;

    while(count < index) {
      current = current->getNext();
      count++;
    }

    return current;

  }

  template <typename T>
  Node<T>* LinkedList<T>::getHead() {
    return this->_head;
  }

  template <typename T>
  Node<T>* LinkedList<T>::getTail() {
    return this->_tail;
  }

  template <typename T>
  int LinkedList<T>::getLength() {
    return this->_length;
  }

  template <typename T>
  void LinkedList<T>::clean() {
    Node<T>* current = this->_head;
    Node<T>* nextCurrent;

    while(this->_length != 0) {

      nextCurrent = current->getNext();
      delete(current);

      this->_length--;

      current = nextCurrent;
    }

    return;

  }

}