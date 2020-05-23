//
// Created by saubhik on 2020/05/23.
//
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  static int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    map<pair<int, int>, bool> obstacleMap;
    for (auto &obstacle : obstacles) {
      if (!obstacle.empty()) {
        obstacleMap.insert({make_pair(obstacle[0], obstacle[1]), true});
      }
    }
    string direction = "up";
    int x = 0, y = 0;
    bool flag;
    for (int command : commands) {
      if (command == -2) {
        if (direction == "up") {
          direction = "left";
        } else if (direction == "left") {
          direction = "down";
        } else if (direction == "down") {
          direction = "right";
        } else if (direction == "right") {
          direction = "up";
        }
      } else if (command == -1) {
        if (direction == "up") {
          direction = "right";
        } else if (direction == "left") {
          direction = "up";
        } else if (direction == "down") {
          direction = "left";
        } else if (direction == "right") {
          direction = "down";
        }
      } else {
        if (direction == "up") {
          flag = false;
          for (int i = 1; i <= command; ++i) {
            if (obstacleMap[make_pair(x, y + i)]) {
              y += i - 1;
              flag = true;
              break;
            }
          }
          if (!flag) {
            y += command;
          }
        } else if (direction == "left") {
          flag = false;
          for (int i = 1; i <= command; ++i) {
            if (obstacleMap[make_pair(x - i, y)]) {
              x -= i - 1;
              flag = true;
              break;
            }
          }
          if (!flag) {
            x -= command;
          }
        } else if (direction == "down") {
          flag = false;
          for (int i = 1; i <= command; ++i) {
            if (obstacleMap[make_pair(x, y - i)]) {
              y -= i - 1;
              flag = true;
              break;
            }
          }
          if (!flag) {
            y -= command;
          }
        } else if (direction == "right") {
          flag = false;
          for (int i = 1; i <= command; ++i) {
            if (obstacleMap[make_pair(x + i, y)]) {
              x += i - 1;
              flag = true;
              break;
            }
          }
          if (!flag) {
            x += command;
          }
        }
      }
    }

    return x * x + y * y;
  }
};

int main() {
  vector<int> commands;
  vector<vector<int>> obstacles;

  commands = {4, -1, 3};
  obstacles = {{}};
  assert(Solution::robotSim(commands, obstacles) == 25);

  commands = {4, -1, 4, -2, 4};
  obstacles = {{2, 4}};
  assert(Solution::robotSim(commands, obstacles) == 65);
}