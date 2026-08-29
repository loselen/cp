#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define int long long

struct Point {
  int x;
  int y;

  Point operator+(Point other) { return {x + other.x, y + other.y}; }
};

const vector<Point> DIR = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool is_valid(Point p, int r, int c) {
  if (1 <= p.x && p.x <= r && 1 <= p.y && p.y <= c) {
    return true;
  }

  return false;
}

const int INF = 1e18;

int shortest_path(vector<vector<bool>> maze, Point start, Point finish) {
  int r = maze.size() - 1;    // the maze is 1 based
  int c = maze[0].size() - 1; // start and finish also 1 based

  vector<vector<bool>> visited(r + 1, vector<bool>(c + 1, false));
  // actually we don't need visited if we already track it
  // using -INF on shortest grid
  vector<vector<int>> shortest(r + 1, vector<int>(c + 1, INF));
  queue<Point> q;

  visited[start.x][start.y] = true;
  shortest[start.x][start.y] = 0;
  q.push(start);

  while (!q.empty()) {
    Point cur = q.front();
    q.pop();

    for (auto d : DIR) {
      Point dest = cur + d;
      if (is_valid(dest, r, c) && maze[dest.x][dest.y] != false &&
          visited[dest.x][dest.y] == false && shortest[dest.x][dest.y] == INF) {
        visited[dest.x][dest.y] = true;
        shortest[dest.x][dest.y] = shortest[cur.x][cur.y] + 1;
        q.push(dest);
      }
    }
  }

  return shortest[finish.x][finish.y];
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r, c;
  cin >> r >> c;

  Point start, finish;
  cin >> start.x >> start.y;
  cin >> finish.x >> finish.y;

  vector<vector<bool>> visitable(r + 1, vector<bool>(c + 1));
  for (int i = 1; i <= r; i++) {
    string cur_str;
    cin >> cur_str;
    cur_str.insert(cur_str.begin(), '0');

    for (int j = 1; j <= c; j++) {
      if (cur_str[j] == '.') {
        visitable[i][j] = true;
      } else {
        visitable[i][j] = false;
      }
    }
  }

  cout << shortest_path(visitable, start, finish) << '\n';

  return 0;
}
