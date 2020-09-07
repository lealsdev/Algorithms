 
#include <iostream>
#include "headers/linked_list.h"
#include "headers/stack.h"
#include "headers/queue.h"

using namespace std;
using namespace collections;

void traverse(LinkedList<int>* list) {
  cout << "TRAVERSE" << endl;
  int* data = list->traverse();
  
  for(int i = 0; i < list->getLength(); ++i) {    
    cout << data[i] << endl;
  }
  cout << "END TRAVERSE" << endl << endl;

  free(data);
}

void test_LinkedList()
{
  cout << "****************************************" << endl;
  cout << "LINKED LIST" << endl;
  cout << "****************************************" << endl;

  LinkedList<int> *list = new LinkedList<int>();

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

  Stack<int>* stk = new Stack<int>();

  cout << "****************************************" << endl;
  cout << "Stack" << endl;
  cout << "****************************************" << endl;

  cout << "PUSH DATA" << endl;
  for(int i = 1; i <= 5; ++i) {
    stk->push(i);
    cout << "push: " << i << endl;
  }

  cout << endl << endl;

  cout << "CHECK TOP: " << stk->checkTop()->getValue() << endl;

  cout << endl << endl;

  cout << "POP DATA" << endl;
  while(!stk->is_empty()) {
    Node<int>* popped = stk->pop();
    cout << "pop: " << popped->getValue() << endl;
    delete(popped);
  }

  delete(stk);

  cout << "****************************************" << endl;
  cout << "END Stack" << endl;
  cout << "****************************************" << endl;
  cout << endl;

  return;

}

void test_queue() {

  Queue<int>* que = new Queue<int>();

  cout << "****************************************" << endl;
  cout << "Queue" << endl;
  cout << "****************************************" << endl;

  cout << "ENQueue DATA" << endl;
  for(int i = 1; i <= 5; ++i) {
    que->enqueue(i);
    cout << "push: " << i << endl;
  }

  cout << endl << endl;

  cout << "CHECK NEXT: " << que->checkNext()->getValue() << endl;

  cout << endl << endl;

  cout << "DEQueue DATA" << endl;
  while(!que->is_empty()) {
    Node<int>* popped = que->dequeue();
    cout << "pop: " << popped->getValue() << endl;
    delete(popped);
  }

  delete(que);

  cout << "****************************************" << endl;
  cout << "END Queue" << endl;
  cout << "****************************************" << endl;
  cout << endl;

  return;

}

int main() {
  test_LinkedList();
  test_stack();
  test_queue();

  return 0;
}