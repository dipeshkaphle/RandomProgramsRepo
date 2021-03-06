#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = size_t;
using ll = long long;
template <typename T> using Vec = std::vector<T>;
template <typename T> using o_set = std::set<T>;
template <typename T> using u_set = std::unordered_set<T>;
template <typename K, typename V> using u_map = std::unordered_map<K, V>;
template <typename K, typename V> using o_map = std::map<K, V>;
using namespace std;
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    auto &arr = intervals;
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (auto &x : arr) {
      if (ans.empty())
        ans.push_back(x);
      else {
        auto &back = ans.back();
        if (x[0] <= back[1]) {
          back[0] = min(x[0], back[0]);
          back[1] = max(x[1], back[1]);
        } else {
          ans.push_back(x);
        }
      }
    }
    return ans;
  }
};

int main() {}
