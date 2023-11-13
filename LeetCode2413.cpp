﻿//2413. 最小偶倍数
//给你一个正整数 n ，返回 2 和 n 的最小公倍数（正整数）。
//
//
//示例 1：
//
//输入：n = 5
//输出：10
//解释：5 和 2 的最小公倍数是 10 。
//示例 2：
//
//输入：n = 6
//输出：6
//解释：6 和 2 的最小公倍数是 6 。注意数字会是它自身的倍数。
//
//
//提示：
//
//1 <= n <= 150
#include "LeetCode2413.h"
int Solution::smallestEvenMultiple(int n) {
	int result = n / 2;
	if (result * 2 == n)
	{
		return n;
	}
	else
	{
		return n * 2;
	}
};
//方法一：数学
//思路与算法
//
//对于任意两个正整数 nnn，mmm 的最小公倍数为 n×mgcd⁡(n, m)\frac{ n \times m }{\gcd(n, m)}
//gcd(n, m)
//n×m
//​
//，其中 gcd⁡(n, m)\gcd(n, m)gcd(n, m) 为 nnn 和 mmm 的最大公约数。
//
//现在题目给出一个正数 nnn，需要返回 222 和 nnn 的最小公倍数，又因为任意正偶数与 222 的最大公约数为 222，任意正奇数与 222 的最大公约数为 111。所以当 nnn 为偶数时直接返回 nnn，否则返回 2×n2 \times n2×n 即可。
//class Solution {
//public:
//	int smallestEvenMultiple(int n) {
//		return n % 2 == 0 ? n : 2 * n;
//	}
//};
//复杂度分析
//
//时间复杂度：O(1)O(1)O(1)。仅需要判断一次 nnn 的奇偶性。
//空间复杂度：O(1)O(1)O(1)。