#include <iostream>
#include <cassert>
using namespace std;

// a simple queue holding integers
class Queue
{
  private:
  static const int length=4; // max size = 4
  int Q[length];
  int front, sz;
  public:
  Queue() { // constructor
    sz = 0;
    front = 0;
  }
  int size()
  {
    return sz;
  }
  bool isEmpty()
  {
    if (sz == 0) return true;
    else return false;
  }
  int peek()
  {
    assert(!isEmpty());
    return Q[front];
  }
  void enqueue(int e)
  {
    assert(size() < length);
    int rear = (front+sz) % length;
    Q[rear] = e;
    sz++;
  }
  int dequeue()
  {
    assert(!isEmpty());
    int e = Q[front];
    front = (front+1) % length;
    sz--;
    return e;
  }
  void dump() { // special function for debugging
    if (isEmpty()) {
      cout << "Empty queue: ";
      cout << "<front=" << front << "> ";
      cout << "<rear=" << (front+length-1)%length << ">" << endl;
      // sz = 0 -> rear = front-1 (while avoiding -1)
      return;
    }
    cout << sz << " items (| for array boundary): <front=" << front << "> ";
    int j = front;
    for (int i=0; i<sz; i++) {
      if ((i+j)%length == 0 and front > 0) cout << "| "; // array warp around
      cout << Q[(i+j)%length] << " ";
    }
    cout << "<rear=" << (front+sz-1)%length << ">" << endl;
  }
};

int main() {
  Queue q;
  int req, e, len;

  while (true) {
    cout << "0 dump" << endl;
    cout << "1 enqueue" << endl;
    cout << "2 dequeue" << endl;
    cout << "3 size" << endl;
    cout << "4 isEmpty" << endl;
    cout << "5 peek" << endl;
    cout << "6 quit" << endl;
    cin >> req;
    switch (req) {
    case 0: q.dump();
            break;
    case 1: cout << "Item to enqueue: ";
            cin >> e;
	    q.enqueue(e);
            break;
    case 2: e = q.dequeue();
            cout << "Item dequeued: " << e << endl;
            break;
    case 3: len = q.size();
            cout << "Size of queue: " << len << endl;
            break;
    case 4: e = q.isEmpty(); // you can also use size for this purpose
            if (e) cout << "Empty queue" << endl;
	    else cout << "Non-empty queue" << endl;
            break;
    case 5: e = q.peek(); // you should make sure that queue is not empty here
            cout << "Front item: " << e << endl;
            break;
    case 6: return 0;
    }
  }
}
