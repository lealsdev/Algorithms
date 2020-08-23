 
#include <iostream>
#include "linked_list.h"

using namespace std;
using namespace collections;

void traverse(linked_list<int>* list) {
  cout << "traverse" << endl;
  int* data = list->traverse();
  
  for(int i = 0; i < list->getLength(); ++i) {    
    cout << data[i] << endl;
  }
  cout << "end traverse" << endl << endl;

  free(data);
}

int main() {
  cout << "Hello World!\n";

  linked_list<int> *list = new linked_list<int>();

  list->add(2);
  list->add(4);
  list->add(6);

  traverse(list);
  
  list->remove(2);
  list->insert(3, 1);
  list->insert(5, 3);

  list->insert(1, 0);

  list->insert(6, list->getLength()+10);

  traverse(list);

  list->reverse();

  traverse(list);

  list->clean();

  traverse(list);

  delete(list);

  return 0;
}