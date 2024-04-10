#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArraySum(const std::vector<int>& nums) {
    int maxSum = 0;
    int currentSum = 0;

    for (int i = 0; i < nums.size(); ++i) {
        currentSum = std::max(0, currentSum + nums[i]);
        maxSum = std::max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    std::vector<int> nums = { -2, 11, -4, 13, -5, -2 };
    int maxSum = maxSubArraySum(nums);
    std::cout << "最大子段和为: " << maxSum << std::endl;
    return 0;
}
