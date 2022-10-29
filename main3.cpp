#include <iostream>
#include <cstdint>

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
      if (is_empty()) { return 142; }

      Node* element = last;
      int res = element->value;
      element = element->prev;
      delete last;
      last = element;
      if (last == nullptr) {
        head = nullptr;
      }
      return res;
    }

};

int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Stack sequence;
  string input;
  string answer = "YES";
  while (cin >> input) {
    if (input.size() % 2 != 0) {
      cout << "NO" << '\n';
      answer = "YES";
      sequence = {};
    } else {
      for (int i = 0; i < input.size(); i++) {
        char symbol = input[i];
        if (i == 0 && (symbol == ']' || symbol == ')')) {
          answer = "NO";
          break;
        }
        if (symbol == '(' || symbol == '[') {
          sequence.push_back(symbol);
          continue;
        } else {
          int poped = sequence.pop();
          if (symbol == ')' && (poped != '(')) {
            answer = "NO";
            break;
          } else if (symbol == ']' && (poped != '['))  {
            answer = "NO";
            break;
          }

        }
      }
      if (sequence.is_empty() && answer == "YES") {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
      answer = "YES";
      sequence = {};
    }
  }

  return 0;
}
