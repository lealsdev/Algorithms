 
#include <iostream>
#include "headers/linked_list.h"
#include "headers/stack.h"

using namespace std;
using namespace collections;

void traverse(linked_list<int>* list) {
  cout << "TRAVERSE" << endl;
  int* data = list->traverse();
  
  for(int i = 0; i < list->getLength(); ++i) {    
    cout << data[i] << endl;
  }
  cout << "END TRAVERSE" << endl << endl;

  free(data);
}

void test_linked_list()
{
  cout << "****************************************" << endl;
  cout << "LINKED LIST" << endl;
  cout << "****************************************" << endl;

  linked_list<int> *list = new linked_list<int>();

  cout << "ADDING ITEMS IN THE LINKED LIST" << endl;
  list->add(2);
  list->add(4);
  list->add(6);
  cout << "" << endl;

  traverse(list);
  
  cout << "REMOVE THE THIRD ITEM" << endl;
  list->remove(2);
  cout << "";

  cout << "INSERTING ITEMS IN THE LINKED LIST" << endl;
  list->insert(3, 1);
  list->insert(5, 3);
  list->insert(1, 0);
  list->insert(6, list->getLength()+10);
  cout << "" << endl;

  traverse(list);

  cout << "REVERSING THE LINKED LIST" << endl;
  list->reverse();
  cout << "";

  traverse(list);

  list->clean();

  traverse(list);

  delete(list);

  cout << "****************************************" << endl;
  cout << "END LINKED LIST" << endl;
  cout << "****************************************" << endl;
  cout << endl;

}

void test_stack() {

  stack<int>* stk = new stack<int>();

  cout << "****************************************" << endl;
  cout << "STACK" << endl;
  cout << "****************************************" << endl;

  cout << "PUSH DATA" << endl;
  for(int i = 1; i <= 5; ++i) {
    stk->push(i);
    cout << "push: " << i << endl;
  }

  cout << endl;

  cout << "POP DATA" << endl;
  while(!stk->is_empty()) {
    node<int>* popped = stk->pop();
    cout << "pop: " << popped->getValue() << endl;
    delete(popped);
  }  

  cout << "****************************************" << endl;
  cout << "END STACK" << endl;
  cout << "****************************************" << endl;
  cout << endl;

  return;

}

int main() {
  test_linked_list();
  test_stack();

  return 0;
}