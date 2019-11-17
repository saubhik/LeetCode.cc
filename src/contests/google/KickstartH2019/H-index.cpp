#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t, n, ai, maxAi = 0;

  cin >> t;

  for (int i = 1; i <= t; ++i) {
    int counter[100001] = {};
    maxAi = 0;

    cin >> n;
    cout << "Case #" << i << ":";

    while (n--) {
      cin >> ai;
      maxAi = max(maxAi, ai);

      for (int j = ai; j > 0; --j)
        ++counter[j];

      for (auto j = maxAi; j > 0; --j)
        if (counter[j] >= j) {
          cout << " " << j;
          break;
        }
    }

    cout << endl;
  }
}
