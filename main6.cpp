#include <iostream>
#include <vector>

using namespace std;

int binarySearchFirst(int arr[], int right, int x /* Element of searching*/) {
  int left = -1;                      // l, r — левая и правая границы
  while (left + 1 < right) {
    int middle = (left + right) / 2;
    if (arr[middle] < x) {
      left = middle;
    } else {
      right = middle;
    }
  }

  if (arr[right] == x) {
    return right + 1;
  }
  return -1;  return right;
}

int binarySearchLast(int arr[], int right, int x /* Element of searching*/) {
  int left = 0;
  while (right > left + 1){
    int middle = (right+left) / 2;

    if ( arr[middle] < x || arr[middle] == x) {
      left = middle;
    } else if (arr[middle] > x || arr[middle] == x) {
      right = middle;
    }
  }
  if (arr[left] == x && left >= 0) {
    return left + 1;
  }
  return -1;
}



int main() {
  //

  int n;
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int m;
  cin >> m;
  int requests[m];

  for (int i = 0; i < m; i++) {
    cin >> requests[i];
  }

  //

  for (int i = 0; i < m; i++) {
    cout << binarySearchFirst(arr,n,requests[i]) << " " << binarySearchLast(arr,n,requests[i]) << '\n';
  }


  return 0;
}
