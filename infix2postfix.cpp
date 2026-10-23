#include <iostream>
#include <cstring>
using namespace std;

// a simple stack holding characters, actually operators and "("
class Stack
{
  private:
  static const int length=20; // max size = 20
  char S[length];
  int top;
  public:
  Stack() { // constructor
    top = -1;
  }
  void push(char e)
  {
    top++;
    S[top] = e;
  }
  char pop()
  {
    char e = S[top];
    top--;
    return e;
  }
  char peek()
  {
    return S[top];
  }
  int isEmpty()
  {
    if (top < 0) return true;
    else return false;
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

int IP(char s) {
  if (s == '+') return 1;
  if (s == '-') return 1;
  if (s == '*') return 2;
  if (s == '/') return 2;
  if (s == '(') return 10;
  cout << "Wrong IP value" << s;
  return 0;
}

int SP(char s) {
  if (s == '+') return 1;
  if (s == '-') return 1;
  if (s == '*') return 2;
  if (s == '/') return 2;
  if (s == '(') return 0;
  cout << "Wrong SP value" << s;
  return 0;
}

bool isop(char s) {
  if (s == '+') return true;
  if (s == '-') return true;
  if (s == '*') return true;
  if (s == '/') return true;
  if (s == '(') return true;
  if (s == ')') return true;
  return false; // a number
}

int main() {
  Stack st;
  string expr;
  char e;

  cout << "Please input an infix expression (items separated by space)" << endl;
  cout << "Example: 2 - 3 + ( 5 * 2 ) * 3 + 4" << endl;
  getline(cin,expr);
  cout << "Converting " << expr << " to postfix" << endl;
  char* item = strtok(strdup(expr.c_str())," "); // use tokenizer with Cstring
  // this resembles Python split() to break a string into multiple items
  while (item) {
      if (not isop(item[0])) { // number
         cout << item << " ";
      } else if (item[0] == ')') {
         e = ' ';
         while (e != '(') {
             e = st.pop();
             if (e != '(') cout << e << " ";
	 }
      } else if (isop(item[0])) {
         while (not st.isEmpty() and SP(st.peek()) >= IP(item[0])) {
             e = st.pop();
             cout << e << " ";
	 }
	 st.push(item[0]); // push symbol as char
      }
      item = strtok(nullptr, " ");
  }
  while (not st.isEmpty()) cout << st.pop() << " ";
  cout << endl;
}
