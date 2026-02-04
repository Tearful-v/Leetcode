class Solution {
public:
  std::pair<int, int> findlenght(string s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      left--;
      right++;
    }
    return {right - left - 1, left + 1};
  }

  string longestPalindrome(string s) {
    if (s.size() == 1 || (s.size() == 2 && s[0] != s[1]))
      return string(1, s[0]);
    int globalmax = 0;
    int startofmax;
    for (int i = 0; i < s.size(); i++) {
      auto even = findlenght(s, i, i + 1);
      auto odd = findlenght(s, i, i);
      auto maxl = std::max(even, odd);
      if (maxl.first > globalmax) {
        globalmax = maxl.first;
        startofmax = maxl.second;
      }
    }
    return s.substr(startofmax, globalmax);
  }
};
