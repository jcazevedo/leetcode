// 299. Bulls and Cows
// https://leetcode.com/problems/bulls-and-cows/

#include <map>
#include <sstream>
#include <string>

using namespace std;

class Solution {
 public:
  string getHint(string secret, string guess) {
    int N = secret.size();
    int bulls = 0, cows = 0;
    map<char, int> in_secret, in_guess;
    for (int i = 0; i < N; ++i) {
      if (secret[i] == guess[i])
        bulls++;
      else {
        in_secret[secret[i]]++;
        in_guess[guess[i]]++;
      }
    }
    for (auto itr = in_guess.begin(); itr != in_guess.end(); ++itr) {
      char ch = itr->first;
      int cnt = itr->second;
      cows += min(cnt, in_secret[ch]);
    }
    ostringstream ss;
    ss << bulls << "A" << cows << "B";
    return ss.str();
  }
};
