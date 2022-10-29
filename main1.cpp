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

};



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Stack sequence;
  int n;

  cin >> n;

  for(int i = 0; i < n; i++) {
    char command;
    cin >> command;

    if (command == '+') {
      int input;
      cin >> input;

      sequence.push_back(input);
    } else {
      cout << sequence.pop() << '\n';
    }
  }
}