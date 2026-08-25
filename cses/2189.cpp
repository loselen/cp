#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Point {
  int x;
  int y;

  Point operator-(Point other) { return Point{x - other.x, y - other.y}; }
};

int cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    Point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    b = b - a;
    c = c - a;

    int parall_area = cross(b, c);
    if (parall_area < 0) {
      cout << "RIGHT";
    } else if (parall_area > 0) {
      cout << "LEFT";
    } else {
      cout << "TOUCH";
    }
    cout << '\n';
  }

  return 0;
}
