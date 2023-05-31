// 1396. Design Underground System
// https://leetcode.com/problems/design-underground-system/

#include <map>
#include <string>
#include <tuple>

using namespace std;

class UndergroundSystem {
private:
  map<tuple<string, string>, tuple<long long, int>> trips;
  map<int, tuple<string, int>> passenger;

public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) { passenger[id] = {stationName, t}; }

  void checkOut(int id, string stationName, int t) {
    string startStation;
    int startTime;
    tie(startStation, startTime) = passenger[id];
    passenger.erase(id);
    if (trips.find({startStation, stationName}) == trips.end()) {
      trips[{startStation, stationName}] = {0L, 0};
    }
    long long length;
    int nTrips;
    tie(length, nTrips) = trips[{startStation, stationName}];
    trips[{startStation, stationName}] = {length + (t - startTime), nTrips + 1};
  }

  double getAverageTime(string startStation, string endStation) {
    long long length;
    int nTrips;
    tie(length, nTrips) = trips[{startStation, endStation}];
    return length / (double)nTrips;
  }
};
