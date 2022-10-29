#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

void resolve(double left, double right, vector<double>& h, int n) {
  while (right - left > (0.000001 / (n-1))) {
    h[1] = (left+right) / 2;
    bool higher = true;

    for (int i = 2; i < n; i++) {
      h[i] = 2 * h[i-1] - h[i-2] + 2;
      if (h[i] < 0) {
        higher = false;
        break;
      }

    }
    if (higher) {
      right = h[1];
    }
    else {
      left = h[1];
    }
  }
}


int main() {
  int n;
  cin >> n;
  vector <double> h;
  h.resize(n);
  cin >> h[0];
  resolve(0,h[0],h,n);
  printf("%.2f\n", h[n-1]);
  return 0;
}
