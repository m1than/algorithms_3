#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;

    Node(int _val): value(_val), prev(nullptr), next(nullptr) {}
};

struct Queue {
    Node* head;
    Node* last;

    Queue() : head(nullptr), last(nullptr) {}

    bool is_empty() {
      return head == nullptr;
    }

    void push_back(int value) {
      Node* temp = new Node(value);

      if (!is_empty()) {
        last->next = temp;
        last = temp;
      } else {
        head = last = temp;
      }
    }

    int pop() {
      int res = head->value;
      Node *temp = head;
      head = head->next;
      if (head == nullptr)
        last = nullptr;
      delete temp;
      return res;
    }
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Queue sequence;
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

  return 0;
}
