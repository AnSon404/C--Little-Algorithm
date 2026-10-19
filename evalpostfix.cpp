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

int main() {
  Stack st;
  string expr;
  int val1, val2;

  cout << "Please input your postfix expression" << endl;
  getline(cin,expr);
  cout << "Evaluating " << expr << endl;
  char* item = strtok(strdup(expr.c_str())," "); // use tokenizer with Cstring
  // this resembles Python split() to break a string into multiple items
  while (item) { // process next input item
      cout << "Input item: " << item << endl;
      switch (item[0]) { // check first character of item
      case '+': val2 = st.pop();
	        val1 = st.pop();
		st.push(val1+val2);
		break;
      case '-': val2 = st.pop();
	        val1 = st.pop();
		st.push(val1-val2);
		break;
      case '*': val2 = st.pop();
	        val1 = st.pop();
		st.push(val1*val2);
		break;
      case '/': val2 = st.pop();
	        val1 = st.pop();
		st.push(val1/val2);
		break;
      default: st.push(atoi(item)); // convert into integer and push
      }
      st.dump();
      item = strtok(nullptr, " ");
  }
  cout << "Answer is " << st.pop() << endl;
}
