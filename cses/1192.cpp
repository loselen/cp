#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define int long long

struct Point {
  int x;
  int y;

  Point operator+(Point other) { return {x + other.x, y + other.y}; }
};

bool is_valid(Point p, int r, int c) {
  if (1 <= p.x && p.x <= r && 1 <= p.y && p.y <= c) {
    return true;
  }

  return false;
}

const vector<Point> DIR = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int count_rooms(vector<vector<bool>> map) {
  int r = map.size() - 1; // map is 1 based
  int c = map[0].size() - 1;

  vector<vector<bool>> visited(r + 1, vector<bool>(c + 1, false));
  queue<Point> q;
  int num_of_rooms = 0;

  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      if (map[i][j] == true && visited[i][j] == false) {
        visited[i][j] = true;
        q.push({i, j});
        num_of_rooms += 1;

        while (!q.empty()) {
          Point cur = q.front();
          q.pop();

          for (auto d : DIR) {
            Point dest = cur + d;

            if (is_valid(dest, r, c) && map[dest.x][dest.y] == true &&
                visited[dest.x][dest.y] == false) {
              visited[dest.x][dest.y] = true;
              q.push({dest.x, dest.y});
            }
          }
        }
      }
    }
  }

  return num_of_rooms;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r, c;
  cin >> r >> c;

  vector<vector<bool>> is_floor(r + 1, vector<bool>(c + 1));
  for (int i = 1; i <= r; i++) {
    string cur_str;
    cin >> cur_str;
    cur_str.insert(cur_str.begin(), '0');

    for (int j = 1; j <= c; j++) {
      if (cur_str[j] == '.') {
        is_floor[i][j] = true;
      } else {
        is_floor[i][j] = false;
      }
    }
  }

  cout << count_rooms(is_floor) << '\n';

  return 0;
}
