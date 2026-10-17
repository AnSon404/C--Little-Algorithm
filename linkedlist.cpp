#include <iostream>
using namespace std;

//the following line is needed if nullptr yields an error on some compiler
//#define nullptr NULL

struct Node {
  int key;
  Node* prev;
  Node* next;
  Node(int k) {
    key=k;
    prev=nullptr;
    next=nullptr;
  }
};

// a simple linked list holding integers
class LinkedList
{
  private:
  Node* head;
  public:
  LinkedList() { // constructor
    head = nullptr;
  }
  Node* search(int k)
  {
    Node* x = head;
    while (x != nullptr and x->key != k)
      x = x->next;
    return x;
  }
  void insert(Node* x) // insert x in the front
  {
    x->prev = nullptr;
    x->next = head;
    if (head != nullptr)
      head->prev = x;
    head = x;
  }
  void insert2(Node* x, Node* y) // insert x after y
  {
    x->prev = y;
    x->next = y->next;
    if (y->next != nullptr) // when y is the tail
      y->next->prev = x;
    y->next = x;
  }
  void remove(Node* x)
  {
    if (x->prev != nullptr)
      x->prev->next = x->next;
    else
      head = x->next;
    if (x->next != nullptr)
      x->next->prev = x->prev;
  }
  void dump() { // special function for debugging
    if (head == nullptr) {
      cout << "Empty linked list" << endl;
      return;
    }
    Node* x = head;
    int ctr = 0;
    while (x != nullptr) {
      cout << x->key << " ";
      ctr++;
      x = x->next;
    }
    cout << "(" << ctr << " items)" << endl;
  }
};

int main() {
  LinkedList link;
  int req, k;
  Node *x, *y;

  while (true) {
    cout << "0 dump" << endl;
    cout << "1 search" << endl;
    cout << "2 insert" << endl;
    cout << "3 insert after" << endl;
    cout << "4 remove" << endl;
    cout << "5 quit" << endl;
    cin >> req;
    switch (req) {
    case 0: link.dump();
            break;
    case 1: cout << "Key to search: ";
            cin >> k;
	    x = link.search(k);
	    if (x == nullptr)
	      cout << "Key " << k << " not found" << endl;
	    else
	      cout << "Key " << k << " found" << endl;
	    break;
    case 2: cout << "Key to insert: ";
            cin >> k;
	    x = new Node(k);
	    link.insert(x);
            break;
    case 3: cout << "Key to insert: ";
            cin >> k;
	    x = new Node(k);
            cout << "Insert after: ";
            cin >> k;
	    y = link.search(k);
	    if (y == nullptr)
	      cout << "Key " << k << " not found" << endl;
	    else
	      link.insert2(x,y);
            break;
    case 4: cout << "Key to remove: ";
            cin >> k;
	    x = link.search(k);
	    if (x == nullptr)
	      cout << "Cannot remove Key " << k << endl;
	    else
	      link.remove(x);
            break;
    case 5: return 0;
    }
  }
}
