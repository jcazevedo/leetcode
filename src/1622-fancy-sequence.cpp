// 1622. Fancy Sequence
// https://leetcode.com/problems/fancy-sequence/

#include <vector>

using namespace std;

#define MOD 1000000007L

class Fancy {
 private:
  vector<long long> seq;
  long long mul, add;
  vector<pair<long long, long long>> invs;

  long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
      if (exp & 1) { result = result * base % mod; }
      base = base * base % mod;
      exp >>= 1;
    }
    return result;
  }

  long long modInverse(long long a, long long mod) { return modPow(a, mod - 2, mod); }

 public:
  Fancy() : mul(1L), add(0L) {}

  void append(int val) {
    seq.push_back(val);
    long long invMul = modInverse(mul, MOD);
    long long invAdd = (MOD - add % MOD) % MOD * invMul % MOD;
    invs.push_back({invMul, invAdd});
  }

  void addAll(int inc) { add = (add + inc) % MOD; }

  void multAll(int m) {
    mul = (mul * m) % MOD;
    add = (add * m) % MOD;
  }

  int getIndex(int idx) {
    if (idx >= (int)seq.size()) { return -1; }
    pair<long long, long long> ansInvs = invs[idx];
    long long ansMul = (mul * ansInvs.first) % MOD;
    long long ansAdd = ((mul * ansInvs.second) % MOD + add) % MOD;
    return (ansMul * seq[idx] % MOD + ansAdd) % MOD;
  }
};
