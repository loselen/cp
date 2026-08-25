class Solution {
public:
  struct Point {
    int x;
    int y;

    Point operator-(Point other) { return Point{x - other.x, y - other.y}; }
  };

  int cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

  bool checkStraightLine(vector<vector<int>> &coordinates) {
    if (coordinates.size() == 2) {
      return true;
    }

    vector<Point> points;
    for (auto p : coordinates) {
      points.push_back(Point{p[0], p[1]});
    }

    Point first_p = points[0];
    for (auto &p : points) {
      p = p - first_p;
    }

    for (int i = 2; i < coordinates.size(); i++) {
      int parall_area = cross(points[i], points[1]);
      if (parall_area != 0) {
        return false;
      }
    }

    return true;
  }
};
