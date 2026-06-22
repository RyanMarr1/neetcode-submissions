class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k;
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int hours = 0;
            for (auto pile : piles) {
                if (mid >= pile) {
                    hours += 1;
                }
                else {
                    hours += (pile + mid - 1) / mid;
                }
            }
            if (hours > h) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
                k = mid;
            }
        }
        return k;
    }
};
