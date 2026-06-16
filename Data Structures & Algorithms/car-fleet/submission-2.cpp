class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int result = 0;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());
        float prev_car_time;
        for (int j = 0; j < cars.size(); j++) {
            int distance_left = target - cars[j].first;
            float time_left = static_cast<float>(distance_left) / cars[j].second;
            if (j == 0) {
                prev_car_time = time_left;
                result++;
                continue;
            }
            if (time_left > prev_car_time) {
                result++;
                prev_car_time = time_left;
            }
        }
        return result;
    }
};
