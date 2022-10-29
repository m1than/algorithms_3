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
    vector <int> maxi{};

    Stack() : head(nullptr), last(nullptr) {}

    bool is_empty() {
      return head == nullptr;
    }

    void push_back(int value) {
      Node* temp = new Node(value);
      if (!is_empty()) {
        maxi.push_back(max(maxi[maxi.size()-1], value));
        temp->prev = last;
        temp->next = nullptr;
        last = temp;
      } else {
        temp->prev = nullptr;
        head = last = temp;
        maxi.push_back(value);
      }
    }

    int pop() {
      if (is_empty()) { return 142; }
      maxi.pop_back();
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

  Stack max_sequence;
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    string command;
    cin >> command;


    if (command == "+") {
      int input;
      cin >> input;

      max_sequence.push_back(input);
    } else if (command == "-") {
      max_sequence.pop();
    } else if (command == "max") {
      int maximal = max_sequence.maxi[max_sequence.maxi.size() - 1];

      cout << maximal << '\n';
    }
  }


  return 0;
}
