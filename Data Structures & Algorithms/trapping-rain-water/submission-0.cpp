class Solution {
public:
    int trap(vector<int>& height) {
        int area_result = 0;
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = 0;
        int maxRight = 0;
        while (left < right) {
            if (height[left] > maxLeft) {
                maxLeft = height[left];
            }
            if (height[right] > maxRight) {
                maxRight = height[right];
            }
            if (maxLeft < maxRight) {
                area_result += maxLeft - height[left];
                left++;
            }
            else {
                area_result += maxRight - height[right];
                right--;
            }
        }
        return area_result;
    }
};
