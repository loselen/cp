class Solution {
public:
  struct Point {
    int x;
    int y;

    Point operator-(Point other) { return Point{x - other.x, y - other.y}; }
  };

  int cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

  float triangle_area(Point a, Point b, Point c) {
    b = b - a;
    c = c - a;

    float res = abs(cross(b, c) / 2.0);
    return res;
  }

  double largestTriangleArea(vector<vector<int>> &points) {
    vector<Point> points_struct;
    int n = points.size();

    for (auto p : points) {
      points_struct.push_back(Point{p[0], p[1]});
    }

    float max_area = 0.0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          float cur_area = triangle_area(points_struct[i], points_struct[j],
                                         points_struct[k]);
          if (cur_area > max_area) {
            max_area = cur_area;
          }
        }
      }
    }

    return max_area;
  }
};
