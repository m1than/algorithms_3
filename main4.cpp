#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;

    Node(int _value) : value(_value), next(nullptr), prev(nullptr) {}
};

struct Stack {
    Node* head;
    Node* last;

    Stack() : head(nullptr), last(nullptr) {}

    bool is_empty() {
      return head == nullptr;
    }

    void push_back(int value) {
      Node* temp = new Node(value);

      if (!is_empty()) {
        temp->prev = last;
        temp->next = nullptr;
        last = temp;
      } else {
        temp->prev = nullptr;
        head = last = temp;
      }
    }

    int pop() {
      Node* element = last;
      int res = element->value;
      element = element->prev;
      delete last;
      last = element;

      return res;
    }

    void plus () {
      push_back(pop() + pop());
    }

    void minus() {
      push_back(-pop() + pop());
    }

    void multiplication() {
      push_back(pop() * pop());
    }

};




vector<string> split(string str, char del){
  string temp;
  vector<string> arr;

  for (int i = 0; i < str.size(); i++) {
    char element = str[i];
    if (element == del) {
      arr.push_back(temp);
      temp = "";
    } else {
      temp += element;
    }
  }
  arr.push_back(temp);
  return arr;
}

int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Stack sequence;
  string input;

  getline(cin, input);

  vector <string> presentation = split(input,' ');

  for (int i = 0; i < presentation.size(); i++) {
    string element = presentation[i];

    if (element == "+") {
      sequence.plus();
    } else if (element == "-") {
      sequence.minus();
    } else if (element == "*") {
      sequence.multiplication();
    } else {
      sequence.push_back(atoi(element.c_str()));
    }

  }
  cout << sequence.last->value;
  return 0;
}
