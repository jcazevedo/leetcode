// 1912. Design Movie Rental System
// https://leetcode.com/problems/design-movie-rental-system/

#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class MovieRentingSystem {
 private:
  unordered_map<int, priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>>> shopsByMovie;
  map<tuple<int, int>, int> prices;
  map<tuple<int, int>, int> rented;
  unordered_map<int, unordered_set<int>> dropped;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> rentedPQ;
  set<tuple<int, int, int>> inPQ;

 public:
  MovieRentingSystem(int n, vector<vector<int>>& entries) {
    for (const vector<int>& entry : entries) {
      shopsByMovie[entry[1]].push({entry[2], entry[0]});
      prices[{entry[0], entry[1]}] = entry[2];
    }
  }

  vector<int> search(int movie) {
    vector<int> ans;
    vector<tuple<int, int>> removed;
    while (!shopsByMovie[movie].empty() && ans.size() < 5) {
      tuple<int, int> shop = shopsByMovie[movie].top();
      shopsByMovie[movie].pop();
      if (rented.count({get<1>(shop), movie})) {
        dropped[movie].insert(get<1>(shop));
        continue;
      }
      removed.push_back(shop);
      ans.push_back(get<1>(shop));
    }
    for (tuple<int, int> entry : removed) { shopsByMovie[movie].push(entry); }
    return ans;
  }

  void rent(int shop, int movie) {
    int price = prices[{shop, movie}];
    rented[{shop, movie}] = price;
    if (!inPQ.count({price, shop, movie})) {
      inPQ.insert({price, shop, movie});
      rentedPQ.push({price, shop, movie});
    }
  }

  void drop(int shop, int movie) {
    if (dropped[movie].count(shop)) {
      shopsByMovie[movie].push({prices[{shop, movie}], shop});
      dropped[movie].erase(shop);
    }
    rented.erase(rented.find({shop, movie}));
  }

  vector<vector<int>> report() {
    vector<vector<int>> ans;
    vector<tuple<int, int, int>> removed;
    while (!rentedPQ.empty() && ans.size() < 5) {
      tuple<int, int, int> rent = rentedPQ.top();
      rentedPQ.pop();
      if (!rented.count({get<1>(rent), get<2>(rent)})) {
        inPQ.erase(rent);
        continue;
      }
      removed.push_back(rent);
      vector<int> obj = {get<1>(rent), get<2>(rent)};
      ans.push_back({get<1>(rent), get<2>(rent)});
    }
    for (tuple<int, int, int> entry : removed) { rentedPQ.push(entry); }
    return ans;
  }
};
