#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  int of_length(int n_digits, int length) {
    int ans = 1;
    for (int i = 0; i < length; ++i)
      ans *= n_digits;
    return ans;
  }

  int num_length(int n) {
    if (n == 0)
      return 1;
    int ans = 0;
    while (n) {
      ans++;
      n /= 10;
    }
    return ans;
  }

  string int_to_string(int n) {
    if (n == 0)
      return "0";
    string ans = "";
    while (n) {
      ans += (n % 10) + '0';
      n /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }

  int aux(int idx, string num, vector<string>& digits) {
    int L = num.size();
    if (idx >= L)
      return 1;
    int ans = 0;
    int num_digits = digits.size();
    for (int i = 0; i < num_digits && digits[i][0] <= num[idx]; ++i) {
      if (digits[i][0] < num[idx])
        ans += of_length(num_digits, L - idx - 1);
      if (digits[i][0] == num[idx])
        ans += aux(idx + 1, num, digits);
    }
    return ans;
  }

public:
  int atMostNGivenDigitSet(vector<string>& digits, int n) {
    int len = num_length(n);
    int n_digits = digits.size();
    int ans = 0;
    for (int i = 1; i < len; ++i)
      ans += of_length(n_digits, i);
    string num = int_to_string(n);
    sort(digits.begin(), digits.end());
    ans += aux(0, num, digits);
    return ans;
  }
};
