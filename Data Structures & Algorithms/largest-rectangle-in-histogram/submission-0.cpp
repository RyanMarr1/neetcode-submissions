class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> heightStack;
        heightStack.push_back({heights[0], 0});
        int result = 0;
        for (int i = 1; i < heights.size(); i++) {
            int start_index = i;
            if (heightStack.back().first > heights[i]) {
                while (!heightStack.empty() && heights[i] < heightStack.back().first) {
                    pair<int, int> top = heightStack.back();
                    int area = top.first * (i - top.second);
                    if (result < area) {
                        result = area;
                    }
                    start_index = top.second;
                    heightStack.pop_back();
                }
                heightStack.push_back({heights[i], start_index});
            }
            else {
                heightStack.push_back({heights[i], i});
            }
        }
        while (!heightStack.empty()) {
            pair<int, int> top = heightStack.back();
            int area = top.first * ((heights.size()) - top.second);
            if (result < area) {
                result = area;
            }
            heightStack.pop_back();
        }
        return result;
    }
};
