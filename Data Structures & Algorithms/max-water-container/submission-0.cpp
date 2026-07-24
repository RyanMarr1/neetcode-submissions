class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int width = right - left;
            int area = width * min(heights[left], heights[right]);
            if (area > maxArea) {
                maxArea = area;
            }
            if (heights[left] > heights[right]) {
                right--;
            }
            else if (heights[left] < heights[right]) {
                left++;
            }
            else {
                left++;
            }
        }
        return maxArea;
    }
};
