class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<pair<int, int>> temp_queue;
        for (int i = 0; i < temperatures.size(); i++) {
            if (temp_queue.empty()) {
                temp_queue.push({temperatures[i], i});
                continue;
            }
            int temp = temperatures[i];
            while (!temp_queue.empty()) {
                if (temp > temp_queue.top().first) {
                    result[temp_queue.top().second] = i - temp_queue.top().second;
                    temp_queue.pop();
                }
                else {
                    break;
                }
            }
            temp_queue.push({temp, i});
        }
        return result;
    }
};
