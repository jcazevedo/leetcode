// 1813. Sentence Similarity III
// https://leetcode.com/problems/sentence-similarity-iii/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<string> words(const string& sentence) {
    vector<string> ans;
    int N = sentence.size();
    string curr = "";
    for (int i = 0; i < N; ++i) {
      if (sentence[i] == ' ') {
        if (!curr.empty()) { ans.push_back(curr); }
        curr = "";
      } else {
        curr += sentence[i];
      }
    }
    if (!curr.empty()) { ans.push_back(curr); }
    return ans;
  }

 public:
  bool areSentencesSimilar(string sentence1, string sentence2) {
    vector<string> words1 = words(sentence1);
    vector<string> words2 = words(sentence2);
    int N1 = words1.size(), N2 = words2.size();
    int s1 = 0, e1 = N1 - 1, s2 = 0, e2 = N2 - 1;
    while (s1 <= e1 && s2 <= e2 && words1[s1] == words2[s2]) {
      ++s1;
      ++s2;
    }
    while (s1 <= e1 && s2 <= e2 && words1[e1] == words2[e2]) {
      --e1;
      --e2;
    }
    return s1 > e1 || s2 > e2;
  }
};
