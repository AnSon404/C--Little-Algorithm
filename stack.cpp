#include <iostream>
#include <cassert>
using namespace std;

// a simple stack holding integers
class Stack
{
  private:
  static const int length=10; // max size = 10
  int S[length];
  int top;
  public:
  Stack() { // constructor
    top = -1;
  }
  int size()
  {
    return top+1;
  }
  bool isEmpty()
  {
    if (top < 0) return true;
    else return false;
  }
  int peek()
  {
    assert(!isEmpty());
    return S[top];
  }
  void push(int e)
  {
    assert(size() < length);
    top++;
    S[top] = e;
  }
  int pop()
  {
    assert(!isEmpty());
    int e = S[top];
    top--;
    return e;
  }
  void dump() { // special function for debugging
    if (isEmpty()) {
      cout << "Empty stack: <top=" << top << ">" << endl;
      return;
    }
    cout << top+1 << " items: ";
    for (int i=0; i<=top; i++)
      cout << S[i] << " ";
    cout << "<top=" << top << ">" << endl;
  }
};

int main() {
  Stack st;
  int req, e, len;

  while (true) {
    cout << "0 dump" << endl;
    cout << "1 push" << endl;
    cout << "2 pop" << endl;
    cout << "3 size" << endl;
    cout << "4 isEmpty" << endl;
    cout << "5 peek" << endl;
    cout << "6 quit" << endl;
    cin >> req;
    switch (req) {
    case 0: st.dump();
            break;
    case 1: cout << "Item to push: ";
            cin >> e;
	    st.push(e);
            break;
    case 2: e = st.pop();
            cout << "Item popped: " << e << endl;
            break;
    case 3: len = st.size();
            cout << "Size of stack: " << len << endl;
            break;
    case 4: e = st.isEmpty(); // you can also use size for this purpose
            if (e) cout << "Empty stack" << endl;
	    else cout << "Non-empty stack" << endl;
            break;
    case 5: e = st.peek(); // you should make sure that stack is not empty here
            cout << "Top item: " << e << endl;
            break;
    case 6: return 0;
    }
  }
}
