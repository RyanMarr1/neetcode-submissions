class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> storage;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        storage[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>& key_array = storage[key];
        int high = key_array.size() - 1;
        int low = 0;
        int best = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (key_array[mid].second == timestamp) {
                best = mid;
                break;
            }
            else if (key_array[mid].second < timestamp) {
                best = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        if (best != -1) {
            return key_array[best].first;
        }
        else {
            return "";
        }
    }
};
