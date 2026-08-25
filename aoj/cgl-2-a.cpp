#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Point {
  int x;
  int y;
};

Point operator-(Point a, Point b) { return Point{a.x - b.x, a.y - b.y}; }

int cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

int dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    Point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

    Point vec_1 = b - a;
    Point vec_2 = d - c;

    int parall_area = cross(vec_1, vec_2);
    int dot_prod = dot(vec_1, vec_2);

    if (parall_area == 0) {
      cout << 2;
    } else if (dot_prod == 0) {
      cout << 1;
    } else {
      cout << 0;
    }
    cout << '\n';
  }

  return 0;
}
