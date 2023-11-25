// 468. Validate IP Address
// https://leetcode.com/problems/validate-ip-address/

#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  vector<string> split(string str, string sep) {
    vector<string> res;
    size_t pos;
    while ((pos = str.find(sep)) != string::npos) {
      string curr = str.substr(0, pos);
      res.push_back(curr);
      str.erase(0, pos + sep.length());
    }
    res.push_back(str);
    return res;
  }

  int string_to_int(string str) {
    int res = 0;
    for (char ch : str) {
      res = res * 10 + (ch - '0');
    }
    return res;
  }

  bool is_valid_ipv4_octet(string octet) {
    if (octet.size() > 3 || octet.size() == 0)
      return false;
    if ((octet[0] == '0' && octet.size() > 1) || octet[0] == '-')
      return false;
    for (char ch : octet)
      if (!isdigit(ch))
        return false;
    return string_to_int(octet) <= 255;
  }

  bool is_ipv4(string ip) {
    vector<string> octets = split(ip, ".");
    if (octets.size() != 4)
      return false;
    for (string octet : octets)
      if (!is_valid_ipv4_octet(octet))
        return false;
    return true;
  }

  bool is_valid_ipv8_group(string group) {
    if (group.size() > 4 || group.size() < 1)
      return false;
    for (char ch : group) {
      if (!(isdigit(ch) || (ch >= 'a' && ch <= 'f') ||
            (ch >= 'A' && ch <= 'F')))
        return false;
    }
    return true;
  }

  bool is_ipv6(string ip) {
    vector<string> groups = split(ip, ":");
    if (groups.size() != 8)
      return false;
    for (string group : groups)
      if (!is_valid_ipv8_group(group))
        return false;
    return true;
  }

public:
  string validIPAddress(string IP) {
    if (is_ipv4(IP))
      return "IPv4";
    if (is_ipv6(IP))
      return "IPv6";
    return "Neither";
  }
};
