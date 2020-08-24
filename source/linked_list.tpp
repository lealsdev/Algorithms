namespace collections {

  template <typename T>
  linked_list<T>::linked_list() {
    this->_length = 0;
  }

  template <typename T>
  linked_list<T>::~linked_list() {
    this->clean();
  }

  template <typename T>
  void linked_list<T>::add(T value) {

    if(this->_length == 0) {
      this->_head = new node(value);
      this->_tail = this->_head;
      this->_length++;

      return;
    }

    node<T>* newNode = new node<T>(value);
    this->_tail->setNext(newNode);
    this->_tail = newNode;
    this->_length++;

    return;
  }

  template <typename T>
  void linked_list<T>::insert(T value, int index) {

    if(index < 0)
      return;

    if(index == 0) {
      if(this->_length == 0) {
        this->add(value);
      }
      else {
        node<T>* oldHead = this->_head;
        node<T>* newHead = new node(value);
        this->_head = newHead;
        this->_head->setNext(oldHead);
        this->_length++;
      }

      return;
    }

    if(index >= this->_length) {
      node<T>* oldTail = this->_tail;
      node<T>* newNode = new node(value);

      oldTail->setNext(newNode);
      this->_tail = newNode;
      this->_length++;

      return;
    }

    node<T>* prevNode = this->getBy(index-1);
    node<T>* nextNode = prevNode->getNext();
    node<T>* newNode = new node<T>(value);

    prevNode->setNext(newNode);
    newNode->setNext(nextNode);
    
    this->_length++;
    
    return;
  }

  template <typename T>
  void linked_list<T>::remove(int index) {
    
    if(index < 0 || index > this->_length-1) {
      return;
    }

    if(index == 0) {
      node<T>* dataToRemove = this->_head;

      this->_head = this->_head->getNext();

      delete(dataToRemove);
      
      this->_length--;

      return;
    }

    node<T>* prevNode = this->getBy(index-1);

    if(index == this->_length-1) {
      node<T>* dataToRemove = this->_tail;

      this->_tail = prevNode;

      delete(dataToRemove);

      this->_length--;

      return;
    }

    node<T>* dataToRemove = prevNode->getNext();
    prevNode->setNext(prevNode->getNext()->getNext());

    delete(dataToRemove);

    this->_length--;

    return;
  }

  template <typename T>
  void linked_list<T>::reverse() {
    if(this->_length <= 1)
      return;
    
    node<T>* newHead = this->_tail;
    node<T>* newTail = this->_head;

    node<T>* current = this->_head;
    node<T>* first = current->getNext();
    node<T>* second;

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
  T* linked_list<T>::traverse() {

    if(this->_length == 0)
      return nullptr;

    T* buffer = (T*)malloc(this->getLength()*sizeof(T));

    int count = 0;

    node<T>* current = this->_head;

    while(current != nullptr) {      
      buffer[count] = current->getValue();      
      current = current->getNext();
      count++;
    }

    return buffer;
  }

  template <typename T>
  node<T>* linked_list<T>::getBy(int index) {

    if(index < 0 || index > this->_length-1) {
      return nullptr;
    }

    node<T>* current = this->_head;
    int count = 0;

    while(count < index) {
      current = current->getNext();
      count++;
    }

    return current;

  }

  template <typename T>
  node<T>* linked_list<T>::getHead() {
    return this->_head;
  }

  template <typename T>
  node<T>* linked_list<T>::getTail() {
    return this->_tail;
  }

  template <typename T>
  int linked_list<T>::getLength() {
    return this->_length;
  }

  template <typename T>
  void linked_list<T>::clean() {
    node<T>* current = this->_head;
    node<T>* nextCurrent;

    while(this->_length != 0) {

      nextCurrent = current->getNext();
      delete(current);

      this->_length--;

      current = nextCurrent;
    }

    return;

  }

}