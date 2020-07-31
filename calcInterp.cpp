#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<double> linear_interp(const vector<double>& x, vector<double>& xp,
                             const vector<double>& fp) {
  // xp default increase(not same value)
  vector<double> res(x.size(), 0);
  vector<double>::iterator right_it;
  int left_idx = 0;
  int right_idx = 0;
  double x1 = 0., x2 = 0.;
  double y1 = 0., y2 = 0.;
  double a = 0., b = 0.;
  for (int i = 0; i < x.size(); ++i) {
    if (x[i] <= xp[0])
      res[i] = fp[0];
    else if (x[i] >= xp[xp.size() - 1])
      res[i] = fp[fp.size() - 1];
    // lower_bound; upper_bound; binary_search
    else {
      right_it = lower_bound(xp.begin(), xp.end(), x[i]);
      right_idx = distance(xp.begin(), right_it);
      if (xp[right_idx] == x[i])
        res[i] = fp[right_idx];
      else {
        left_idx = right_idx - 1;
        x1 = xp[left_idx];
        x2 = xp[right_idx];
        y1 = fp[left_idx];
        y2 = fp[right_idx];
        a = (y1 - y2) / (x1 - x2);
        b = y1 - x1 * (y1 - y2) / (x1 - x2);
        res[i] = a * x[i] + b;
      }
    }
  }
  return res;
}

int main() {
  vector<double> x = {2.5};
  vector<double> xp = {1, 2, 3};
  vector<double> fp = {3, 2, 0};
  vector<double> result;
  result = linear_interp(x, xp, fp);
  // print out result
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << " ";
  }
  cout << endl;
}