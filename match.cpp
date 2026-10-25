#include <iostream>
#include <cstring>
using namespace std;

// a simple stack holding characters (in the form of integers)
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
  bool isEmpty()
  {
    if (top < 0) return true;
    else return false;
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
    if (isEmpty()) {
      cout << "Empty stack" << endl;
      return;
    }
    cout << top+1 << " items: <bottom> ";
    for (int i=0; i<=top; i++)
      cout << char(S[i]) << " ";
    cout << "<top>" << endl;
  }
};

bool MatchParantheses(string s) {
  Stack st;

  for (int i=0; i < s.length(); i++) {
    if (s[i] == '(' or s[i] == '[')
      st.push(s[i]);
    if (s[i] == ')')
      if (st.isEmpty() or st.pop() != '(')
        return false;
    if (s[i] == ']')
      if (st.isEmpty() or st.pop() != '[')
        return false;
    if (s[i] != ' ') { // ignore space
      cout << "Seeing " << char(s[i]) << " => "; // output as a character
      st.dump();
    }
  }
  if (st.isEmpty())
    return true;
  else
    return false;
}

int main() {
  string s;
  
  printf("Please input a string: ");
  getline(cin,s);
  cout << "Input string: " << s << endl;
  if (MatchParantheses(s))
    cout << "Matched" << endl;
  else
    cout << "Not matched" << endl;
}
