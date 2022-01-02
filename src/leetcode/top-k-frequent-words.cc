class Compare {
 public:
  bool operator()(const pair<string, int>& lhs, const pair<string, int>& rhs) {
    if (lhs.second == rhs.second) {
      return lhs.first <= rhs.first;
    }

    return lhs.second >= rhs.second;
  }
};

class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> map;
    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;

    for (string word : words) {
      ++map[word];
    }

    unordered_map<string, int>::iterator it;
    for (it = map.begin(); it != map.end(); ++it) {
      pq.push(make_pair(it->first, it->second));
      if (pq.size() > k) {
        pq.pop();
      }
    }

    vector<string> ans;
    while (!pq.empty()) {
      ans.push_back(pq.top().first);
      pq.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};

