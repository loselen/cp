class Solution {
public:
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

  int numIslands(vector<vector<char>> &grid) {
    int r = grid.size(); // og grid is 0 based
    int c = grid[0].size();

    vector<vector<char>> grid_new(r + 1, vector<char>(c + 1));
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        grid_new[i][j] = grid[i - 1][j - 1];
      }
    }

    grid = grid_new; // ditimpa jadi 1 based

    vector<vector<bool>> visited(r + 1, vector<bool>(c + 1, false));
    queue<Point> q;
    int num_of_islands = 0;

    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        if (grid[i][j] == '1' && visited[i][j] == false) {
          visited[i][j] = true;
          q.push({i, j});
          num_of_islands += 1;

          while (!q.empty()) {
            Point cur = q.front();
            q.pop();

            for (auto d : DIR) {
              Point dest = cur + d;

              if (is_valid(dest, r, c) && grid[dest.x][dest.y] == '1' &&
                  visited[dest.x][dest.y] == false) {
                visited[dest.x][dest.y] = true;
                q.push({dest.x, dest.y});
              }
            }
          }
        }
      }
    }

    return num_of_islands;
  }
};
