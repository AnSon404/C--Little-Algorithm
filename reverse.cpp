#include <iostream>
#include <cstring>
using namespace std;

// a simple stack holding integers
// keep only some key operations
class Stack
{
  private:
  static const int length=20; // max size = 20
  int S[length];
  int top;
  public:
  Stack() { // constructor
    top = -1;
  }
  void push(int e)
  {
    top++;
    S[top] = e;
  }
  int pop()
  {
    int e = S[top];
    top--;
    return e;
  }
  void dump() { // special function for debugging
    if (top < 0) {
      cout << "Empty stack" << endl;
      return;
    }
    cout << "Stack: <bottom> ";
    for (int i=0; i<=top; i++)
      cout << S[i] << " ";
    cout << "<top>" << endl;
  }
};

void reverse(int A[], int size) {
  Stack st;

  // to reverse, push all to the stack
  for (int i=0; i<size; i++)
    st.push(A[i]);
  // pop all from the stack
  for (int i=0; i<size; i++)
    A[i] = st.pop();
}

int main() {
  int i, length;

  cout << "Input number of items" << endl;
  cin >> length;
  int *myarray = new int[length]; // create the array
  cout << "Please input your data" << endl;
  for (i = 0; i < length; i++)
    cin >> myarray[i];
  cout << "Input array" << endl;
  for (i = 0; i < length; i++)
    cout << myarray[i] << " ";
  cout << endl;
  reverse(myarray,length);
  cout << "Reversed array" << endl;
  for (i = 0; i < length; i++)
    cout << myarray[i] << " ";
  cout << endl;
}
