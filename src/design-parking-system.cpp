#include <vector>

using namespace std;

class ParkingSystem {
private:
  vector<int> spaces;

public:
  ParkingSystem(int big, int medium, int small) { spaces = {0, big, medium, small}; }

  bool addCar(int carType) {
    if (spaces[carType]) {
      spaces[carType]--;
      return true;
    }
    return false;
  }
};
