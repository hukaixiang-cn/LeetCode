// 26. 删除有序数组中的重复项
// 给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
// 考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
// 更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
// 返回 k 。
// 判题标准:
// 系统会用下面的代码来测试你的题解:
// int[] nums = [...]; // 输入数组
// int[] expectedNums = [...]; // 长度正确的期望答案
// int k = removeDuplicates(nums); // 调用
// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
// 如果所有断言都通过，那么您的题解将被 通过。

// 示例 1：
// 输入：nums = [1,1,2]
// 输出：2, nums = [1,2,_]
// 解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
// 示例 2：
// 输入：nums = [0,0,1,1,1,2,2,3,3,4]
// 输出：5, nums = [0,1,2,3,4]
// 解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。

// 提示：
// 1 <= nums.length <= 3 * 10^4
// -10^4 <= nums[i] <= 10^4
// nums 已按 非严格递增 排列
#include "LeetCode26.hpp"

int Solution::removeDuplicates(vector<int> &nums)
{  
    int idx = 0, temp = nums[idx] - 1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] > temp)
        {
            swap(nums[i], nums[idx]);
            temp = nums[idx];
            idx++;
        }
    }
    return idx;
}
// int Solution::removeDuplicates(vector<int> &nums)
// {
//     int result = 1, tmp = nums[0];
//     for (size_t i = 1; i < nums.size(); i++)
//     {
//         if (nums[i] == tmp)
//         {
//             nums.erase(nums.begin() + i, nums.begin() + i + 1);
//             i--;
//         }
//         else
//         {
//             result++;
//             tmp = nums[i];
//         }
//     }
//     return result;
// };
// 方法一：双指针
// 这道题目的要求是：对给定的有序数组 nums 删除重复元素，在删除重复元素之后，每个元素只出现一次，并返回新的长度，上述操作必须通过原地修改数组的方法，使用 O(1) 的空间复杂度完成。
// 由于给定的数组 nums 是有序的，因此对于任意 i<j，如果 nums[i]=nums[j]，则对任意 i≤k≤j，必有 nums[i]=nums[k]=nums[j]，即相等的元素在数组中的下标一定是连续的。利用数组有序的特点，可以通过双指针的方法删除重复元素。
// 如果数组 nums 的长度为 0，则数组不包含任何元素，因此返回 0。
// 当数组 nums 的长度大于 0 时，数组中至少包含一个元素，在删除重复元素之后也至少剩下一个元素，因此 nums[0] 保持原状即可，从下标 1 开始删除重复元素。
// 定义两个指针 fast 和 slow 分别为快指针和慢指针，快指针表示遍历数组到达的下标位置，慢指针表示下一个不同元素要填入的下标位置，初始时两个指针都指向下标 1。
// 假设数组 nums 的长度为 n。将快指针 fast 依次遍历从 1 到 n−1 的每个位置，对于每个位置，如果 nums[fast]≠nums[fast−1]，说明 nums[fast] 和之前的元素都不同，因此将 nums[fast] 的值复制到 nums[slow]，然后将 slow 的值加 1，即指向下一个位置。
// 遍历结束之后，从 nums[0] 到 nums[slow−1] 的每个元素都不相同且包含原数组中的每个不同的元素，因此新的长度即为 slow，返回 slow 即可。
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) {
//             return 0;
//         }
//         int fast = 1, slow = 1;
//         while (fast < n) {
//             if (nums[fast] != nums[fast - 1]) {
//                 nums[slow] = nums[fast];
//                 ++slow;
//             }
//             ++fast;
//         }
//         return slow;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n)，其中 n 是数组的长度。快指针和慢指针最多各移动 n 次。
// 空间复杂度：O(1)。只需要使用常数的额外空间。