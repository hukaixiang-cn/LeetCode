﻿//326. 3 的幂
//给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。
//
//整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x
//
//
//
//示例 1：
//
//输入：n = 27
//输出：true
//示例 2：
//
//输入：n = 0
//输出：false
//示例 3：
//
//输入：n = 9
//输出：true
//示例 4：
//
//输入：n = 45
//输出：false
//
//
//提示：
//
//- 231 <= n <= 231 - 1
//
//
//进阶：你能不使用循环或者递归来完成本题吗？
#include"LeetCode326.h"
bool Solution::isPowerOfThree(int n) {
	if (n == 0)
	{
		return false;
	}
	while (n % 3 == 0)
	{
		n /= 3;
	}
	if (n == 1)
	{
		return true;
	}
	return false;
};
//方法一：试除法
//思路与算法
//
//我们不断地将 nnn 除以 333，直到 n = 1n = 1n = 1。如果此过程中 nnn 无法被 333 整除，就说明 nnn 不是 333 的幂。
//
//本题中的 nnn 可以为负数或 000，可以直接提前判断该情况并返回 False\text{ False }False，也可以进行试除，因为负数或 000 也无法通过多次除以 333 得到 111。
//class Solution {
//public:
//	bool isPowerOfThree(int n) {
//		while (n && n % 3 == 0) {
//			n /= 3;
//		}
//		return n == 1;
//	}
//};
//复杂度分析
//
//时间复杂度：O(log⁡n)O(\log n)O(logn)。当 nnn 是 333 的幂时，需要除以 333 的次数为 log⁡3n = O(log⁡n)\log_3 n = O(\log n)log
//3
//​
//n = O(logn)；当 nnn 不是 333 的幂时，需要除以 333 的次数小于该值。
//
//空间复杂度：O(1)O(1)O(1)。
//
//方法二：判断是否为最大 333 的幂的约数
//思路与算法
//
//我们还可以使用一种较为取巧的做法。
//
//在题目给定的 323232 位有符号整数的范围内，最大的 333 的幂为 319 = 11622614673 ^ {19} = 11622614673
//19
//= 1162261467。我们只需要判断 nnn 是否是 3193 ^ {19}3
//19
//的约数即可。
//
//与方法一不同的是，这里需要特殊判断 nnn 是负数或 000 的情况。
//class Solution {
//public:
//	bool isPowerOfThree(int n) {
//		return n > 0 && 1162261467 % n == 0;
//	}
//};
//复杂度分析
//
//时间复杂度：O(1)O(1)O(1)。
//
//空间复杂度：O(1)O(1)O(1)。