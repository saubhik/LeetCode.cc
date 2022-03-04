class Solution {
 public:
  // Whenever a function call starts, pause the executing one.
  // This is due to single-threaded CPU.
  // 0:start:0, 1:start:2, 1:end:5, 0:end:6
  // Track times for each function ID.
  // 0:start:0 -> 0:0,      executing: 0, time:0
  // 1:start:2 -> 0:2, 1:0, executing: 1, time:2
  // 1:end:5   -> 0:2, 1:4, executing: 0, time:5
  // 0:end:6   -> 0:3, 1:3, executing: ~, time:6
  // Important notes:
  // Function executes at end time.
  // Function executes at start time. Old one doesn't!
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> exTimes(n, 0);
    vector<int> lastStarts(n, 0);
    stack<int> currIDs;
    string items[3];
    for (string s : logs) {
      split(s, items);
      int fID = stoi(items[0]);
      int time = stoi(items[2]);
      if (items[1] == "start") {
        if (!currIDs.empty()) {
          // If there were someone else?
          // It was running till time-1.
          int currID = currIDs.top();
          exTimes[currID] += time - lastStarts[currID];
        }

        // New one took over the CPU.
        currIDs.push(fID);
        lastStarts[fID] = time;
      } else if (items[1] == "end") {
        // This must be currID ending.
        // assert(currIDs.top() == fID);
        exTimes[fID] += time - lastStarts[fID] + 1;
        currIDs.pop();

        // We must start any remaining executions.
        if (!currIDs.empty()) {
          int currID = currIDs.top();
          lastStarts[currID] = time + 1;
        }
      }
    }
    // assert(currIDs.empty());
    return exTimes;
  }

 private:
  void split(const string& s, string (&items)[3]) {
    stringstream ss(s);
    string item;
    int i = 0;
    while (getline(ss, item, ':')) items[i++] = item;
  }
};
