#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("cowsignal.in", "r", stdin);
  freopen("cowsignal.out", "w", stdout);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<char>> image(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    for (int j = 0; j < m; j++) {
      image[i][j] = temp[j];
    }
  }

  vector<vector<char>> scaled(n * k, vector<char>(m * k));
  for (int i = 0; i < n * k; i += k) {
    for (int j = 0; j < m * k; j += k) {
      for (int ik = 0; ik < k; ik++) {
        for (int jk = 0; jk < k; jk++) {
          scaled[i + ik][j + jk] = image[i / k][j / k];
        }
      }
    }
  }

  for (int i = 0; i < n * k; i++) {
    for (int j = 0; j < m * k; j++) {
      cout << scaled[i][j];
    }
    cout << '\n';
  }

  return 0;
}
