/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
  int guessNumber(long long n) {
    long long lo = 0, hi = n + 1;
    while (hi - lo > 1) {
      long long mid = (lo + hi) / 2;
      if (guess(mid) < 1) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    if (hi == n + 1) {
      return -1;
    }
    return hi;
  }
};
