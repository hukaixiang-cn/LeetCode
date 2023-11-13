﻿//459. 重复的子字符串
//给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
//
//
//
//示例 1:
//
//输入: s = "abab"
//输出 : true
//解释 : 可由子串 "ab" 重复两次构成。
//示例 2 :
//
//	输入 : s = "aba"
//	输出 : false
//	示例 3 :
//
//	输入 : s = "abcabcabcabc"
//	输出 : true
//	解释 : 可由子串 "abc" 重复四次构成。(或子串 "abcabc" 重复两次构成。)
//
//
//	提示：
//
//	1 <= s.length <= 104
//	s 由小写英文字母组成

#include "LeetCode459.h"

bool Solution::repeatedSubstringPattern(string s) {
	//给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
	//长度为1的字符串无法由子串重复多次构成，返回false。
	if (s.size() == 1)
	{
		return false;
	}
	//计算可以整除的次数
	int times = 0;
	//返回结果false
	bool result = false;
	//字符串长度计算可以整除的子串长度
	for (size_t i = 1; i < s.size(); i++)
	{
		//不能整除跳过此循环
		times = s.size() / i;
		if (times * i != s.size())
		{
			continue;
		}
		//计算是否可以由子串重复构成
		result = true;
		for (size_t j = 0; j < times - 1; j++)
		{
			for (size_t k = 0; k < i; k++)
			{
				if (s[j * i + k] != s[(j + 1) * i + k])
				{
					result = false;
					break;
				}
			}
			if (!result)
			{
				break;
			}
		}
		if (result)
		{
			return true;
		}
	}
	return false;
};
//方法一：枚举
//思路与算法
//
//如果一个长度为 nnn 的字符串 sss 可以由它的一个长度为 n′n'n 
//′
//的子串 s′s's 
//′
//重复多次构成，那么：
//
//nnn 一定是 n′n'n 
//′
//的倍数；
//
//s′s's 
//′
//一定是 sss 的前缀；
//
//对于任意的 i∈[n′, n)i \in[n', n)i∈[n 
//′
//, n)，有 s[i] = s[i−n′]s[i] = s[i - n']s[i]=s[i−n 
//′
//]。
//
//也就是说，sss 中长度为 n′n'n 
//′
//的前缀就是 s′s's 
//′
//，并且在这之后的每一个位置上的字符 s[i]s[i]s[i]，都需要与它之前的第 n′n'n 
//′
//个字符 s[i−n′]s[i - n']s[i−n 
//′
//] 相同。
//
//因此，我们可以从小到大枚举 n′n'n 
//′
//，并对字符串 sss 进行遍历，进行上述的判断。注意到一个小优化是，因为子串至少需要重复一次，所以 n′n'n 
//′
//不会大于 nnn 的一半，我们只需要在[1, n2][1, \frac{ n }{2}][1,
//2
//n
//​
//] 的范围内枚举 n′n'n 
//′
//即可。
//class Solution {
//public:
//	bool repeatedSubstringPattern(string s) {
//		int n = s.size();
//		for (int i = 1; i * 2 <= n; ++i) {
//			if (n % i == 0) {
//				bool match = true;
//				for (int j = i; j < n; ++j) {
//					if (s[j] != s[j - i]) {
//						match = false;
//						break;
//					}
//				}
//				if (match) {
//					return true;
//				}
//			}
//		}
//		return false;
//	}
//};
//复杂度分析
//
//时间复杂度：O(n2)O(n ^ 2)O(n
//	2
//)，其中 nnn 是字符串 sss 的长度。枚举 iii 的时间复杂度为 O(n)O(n)O(n)，遍历 sss 的时间复杂度为 O(n)O(n)O(n)，相乘即为总时间复杂度。
//
//空间复杂度：O(1)O(1)O(1)。
//方法二：字符串匹配
//思路与算法
//
//我们可以把字符串 sss 写成
//
//s′s′⋯s′s′s's' \cdots s's'
//s
//′
//s
//′
//⋯s
//′
//s
//′
//
//的形式，总计 nn′\frac{ n }{n'} 
//n
//′
//
//n
//​
//个 s′s's 
//′
//。但我们如何在不枚举 n′n'n 
//′
//的情况下，判断 sss 是否能写成上述的形式呢？
//
//如果我们移除字符串 sss 的前 n′n'n 
//′
//个字符（即一个完整的 s′s's 
//′
//），再将这些字符保持顺序添加到剩余字符串的末尾，那么得到的字符串仍然是 sss。由于 1≤n′ < n1 \leq n' < n1≤n 
//	′
//	< n，那么如果将两个 sss 连在一起，并移除第一个和最后一个字符，那么得到的字符串一定包含 sss，即 sss 是它的一个子串。
//
//	因此我们可以考虑这种方法：我们将两个 sss 连在一起，并移除第一个和最后一个字符。如果 sss 是该字符串的子串，那么 sss 就满足题目要求。
//
//	注意到我们证明的是如果 sss 满足题目要求，那么 sss 有这样的性质，而我们使用的方法却是如果 sss 有这样的性质，那么 sss 满足题目要求。因此，只证明了充分性是远远不够的，我们还需要证明必要性。
//
//	题解区的很多题解都忽略了这一点，但它是非常重要的。
//
//	证明需要使用一些同余运算的小技巧，可以见方法三之后的「正确性证明」部分。这里先假设我们已经完成了证明，这样就可以使用非常简短的代码完成本题。在下面的代码中，我们可以从位置 111 开始查询，并希望查询结果不为位置 nnn，这与移除字符串的第一个和最后一个字符是等价的。
//	class Solution {
//	public:
//		bool repeatedSubstringPattern(string s) {
//			return (s + s).find(s, 1) != s.size();
//		}
//};
//复杂度分析
//
//由于我们使用了语言自带的字符串查找函数，因此这里不深入分析其时空复杂度。
//
//方法三：KMP 算法
//思路与算法
//
//在方法二中，我们使用了语言自带的字符串查找函数。同样我们也可以自己实现这个函数，例如使用比较经典的 KMP 算法。
//
//读者需要注意以下几点：
//
//KMP 算法虽然有着良好的理论时间复杂度上限，但大部分语言自带的字符串查找函数并不是用 KMP 算法实现的。这是因为在实现 API 时，我们需要在平均时间复杂度和最坏时间复杂度二者之间权衡。普通的暴力匹配算法以及优化的 BM 算法拥有比 KMP 算法更为优秀的平均时间复杂度；
//
//学习 KMP 算法时，一定要理解其本质。如果放弃阅读晦涩难懂的材料（即使大部分讲解 KMP 算法的材料都包含大量的图，但图毕竟只能描述特殊而非一般情况）而是直接去阅读代码，是永远无法学会 KMP 算法的。读者甚至无法理解 KMP 算法关键代码中的任意一行。
//
//由于本题就是在一个字符串中查询另一个字符串是否出现，可以直接套用 KMP 算法。因此这里对 KMP 算法本身不再赘述。读者可以自行查阅资料进行学习。这里留了三个思考题，读者可以在学习完毕后尝试回答这三个问题，检验自己的学习成果：
//
//设查询串的的长度为 nnn，模式串的长度为 mmm，我们需要判断模式串是否为查询串的子串。那么使用 KMP 算法处理该问题时的时间复杂度是多少？在分析时间复杂度时使用了哪一种分析方法？
//
//如果有多个查询串，平均长度为 nnn，数量为 kkk，那么总时间复杂度是多少？
//
//在 KMP 算法中，对于模式串，我们需要预处理出一个 fail\textit{ fail }fail 数组（有时也称为 next\textit{ next }next 数组、π\piπ 数组等）。这个数组到底表示了什么？
//class Solution {
//public:
//	bool kmp(const string& query, const string& pattern) {
//		int n = query.size();
//		int m = pattern.size();
//		vector<int> fail(m, -1);
//		for (int i = 1; i < m; ++i) {
//			int j = fail[i - 1];
//			while (j != -1 && pattern[j + 1] != pattern[i]) {
//				j = fail[j];
//			}
//			if (pattern[j + 1] == pattern[i]) {
//				fail[i] = j + 1;
//			}
//		}
//		int match = -1;
//		for (int i = 1; i < n - 1; ++i) {
//			while (match != -1 && pattern[match + 1] != query[i]) {
//				match = fail[match];
//			}
//			if (pattern[match + 1] == query[i]) {
//				++match;
//				if (match == m - 1) {
//					return true;
//				}
//			}
//		}
//		return false;
//	}
//
//	bool repeatedSubstringPattern(string s) {
//		return kmp(s + s, s);
//	}
//};
//复杂度分析
//
//时间复杂度：O(n)O(n)O(n)，其中 nnn 是字符串 sss 的长度。
//
//空间复杂度：O(n)O(n)O(n)。
//
//正确性证明
//一方面，如果长度为 nnn 的字符串 sss 是字符串 t = s + st = s + st = s + s 的子串，并且 sss 在 ttt 中的起始位置不为 000 或 nnn，那么 sss 就满足题目的要求。证明过程如下：
//
//我们设 sss 在 ttt 中的起始位置为 iii，i∈(0, n)i \in(0, n)i∈(0, n)。也就是说，ttt 中从位置 iii 开始的 nnn 个连续的字符，恰好就是字符串 sss。那么我们有：
//
//s[0:n−1] = t[i:n + i−1]s[0:n - 1] = t[i:n + i - 1]
//s[0:n−1] = t[i:n + i−1]
//由于 ttt 是由两个 sss 拼接而成的，我们可以将 t[i:n + i−1]t[i:n + i - 1]t[i:n + i−1] 分成位置 n−1n - 1n−1 左侧和右侧两部分：
//
//{ s[0:n−i−1] = t[i:n−1]s[n−i:n−1] = t[n:n + i−1] = t[0:i−1]\left \{ \begin{aligned} s[0:n - i - 1] &= t[i:n - 1] \\ s[n - i:n - 1] &= t[n:n + i - 1] = t[0:i - 1] \end{aligned} \right.
//{
//s[0:n−i−1]
//s[n−i:n−1]
//​
//
//= t[i:n−1]
//= t[n:n + i−1] = t[0:i−1]
//​
//
//每一部分都可以对应回 sss：
//
//{s[0:n−i−1] = s[i:n−1]s[n−i:n−1] = s[0:i−1]\left \{ \begin{aligned} s[0:n - i - 1] &= s[i:n - 1] \\ s[n - i:n - 1] &= s[0:i - 1] \end{aligned} \right.
//{
//s[0:n−i−1]
//s[n−i:n−1]
//​
//
//= s[i:n−1]
//= s[0:i−1]
//​
//
//这说明，sss 是一个「可旋转」的字符串：将 sss 的前 iii 个字符保持顺序，移动到 sss 的末尾，得到的新字符串与 sss 相同。也就是说，在模 nnn 的意义下，
//
//s[j] = s[j + i]s[j] = s[j + i]
//s[j] = s[j + i]
//对于任意的 jjj 恒成立。
//
//「在模 nnn 的意义下」可以理解为，所有的加法运算的结果都需要对 nnn 取模，使得结果保持在[0,n)[0, n)[0,n) 中，这样加法就自带了「旋转」的效果。
//
//如果我们不断地连写这个等式：
//
//s[j] = s[j + i] = s[j + 2i] = s[j + 3i] = ⋯s[j] = s[j + i] = s[j + 2i] = s[j + 3i] = \cdots
//s[j] = s[j + i] = s[j + 2i] = s[j + 3i] = ⋯
//那么所有满足 j0 = j + k⋅ij_0 = j + k \cdot ij
//0
//​
// = j + k⋅i 的位置 j0j_0j
//0
//​
//  都有 s[j] = s[j0]s[j] = s[j_0]s[j] = s[j
//0
//​
// ]，jjj 和 j0j_0j
//0
//​
//  在模 iii 的意义下等价。由于我们已经在模 nnn 的意义下讨论这个问题，因此 jjj 和 j0j_0j
//0
//​
//  在模 gcd(n,i)\mathrm{gcd}(n, i)gcd(n,i) 的意义下等价，其中 gcd\mathrm{gcd}gcd 表示最大公约数。也就是说，字符串 sss 中的两个位置如果在模 gcd(n,i)\mathrm{gcd}(n, i)gcd(n,i) 的意义下等价，那么它们对应的字符必然是相同的。
//
//由于 gcd(n,i)\mathrm{gcd}(n, i)gcd(n,i) 一定是 nnn 的约数，那么字符串 sss 一定可以由其长度为 gcd(n,i)\mathrm{gcd}(n, i)gcd(n,i) 的前缀重复 ngcd(n,i)\frac{n}{\mathrm{gcd}(n, i)}
//gcd(n,i)
//n
//​
//  次构成。
//
//另一方面，如果 sss 满足题目的要求，那么 sss 包含若干个「部分」，t = s + st = s + st = s + s 包含两倍数量的「部分」，因此 sss 显然是 ttt 的子串，并且起始位置可以不为 000 或 nnn：我们只需要选择 ttt 中第一个「部分」的起始位置即可。
//
//综上所述，我们证明了：长度为 nnn 的字符串 sss 是字符串 t = s + st = s + st = s + s 的子串，并且 sss 在 ttt 中的起始位置不为 000 或 nnn，当且仅当 sss 满足题目的要求。因此，
//
//思考题答案
//设查询串的的长度为 nnn，模式串的长度为 mmm，我们需要判断模式串是否为查询串的子串。那么使用 KMP 算法处理该问题时的时间复杂度是多少？在分析时间复杂度时使用了哪一种分析方法？
//
//时间复杂度为 O(n + m)O(n + m)O(n + m)，用到了均摊分析（摊还分析）的方法。
//
//具体地，无论在预处理过程还是查询过程中，虽然匹配失败时，指针会不断地根据 fail\textit{fail}fail 数组向左回退，看似时间复杂度会很高。但考虑匹配成功时，指针会向右移动一个位置，这一部分对应的时间复杂度为 O(n + m)O(n + m)O(n + m)。又因为向左移动的次数不会超过向右移动的次数，因此总时间复杂度仍然为 O(n + m)O(n + m)O(n + m)。
//
//如果有多个查询串，平均长度为 nnn，数量为 kkk，那么总时间复杂度是多少？
//
//时间复杂度为 O(nk + m)O(nk + m)O(nk + m)。模式串只需要预处理一次。
//在 KMP 算法中，对于模式串，我们需要预处理出一个 fail\textit{fail}fail 数组（有时也称为 next\textit{next}next 数组、π\piπ 数组等）。这个数组到底表示了什么？
//
//fail[i]\textit{fail}[i]fail[i] 等于满足下述要求的 xxx 的最大值：s[0:i]s[0:i]s[0:i] 具有长度为 x + 1x + 1x + 1 的完全相同的前缀和后缀。这也是 KMP 算法最重要的一部分。
//方法四：优化的 KMP 算法
//思路与算法
//
//如果读者能够看懂「正确性证明」和「思考题答案」这两部分，那么一定已经发现了方法三中的 KMP 算法有可以优化的地方。即：
//
//在「正确性证明」部分，如果我们设 iii 为最小的起始位置，那么一定有 gcd(n,i) = i\mathrm{gcd}(n, i) = igcd(n,i) = i，即 nnn 是 iii 的倍数。这说明字符串 sss 是由长度为 iii 的前缀重复 ni\frac{n}{i}
//i
//n
//​
//  次构成；
//
//由于 fail[n−1]\textit{fail}[n - 1]fail[n−1] 表示 sss 具有长度为 fail[n−1] + 1\textit{fail}[n - 1] + 1fail[n−1] + 1 的完全相同的（且最长的）前缀和后缀。那么对于满足题目要求的字符串，一定有 fail[n−1] = n−i−1\textit{fail}[n - 1] = n - i - 1fail[n−1] = n−i−1，即 i = n−fail[n−1]−1i = n - \textit{fail}[n - 1] - 1i = n−fail[n−1]−1；
//
//对于不满足题目要求的字符串，nnn 一定不是 n−fail[n−1]−1n - \textit{fail}[n - 1] - 1n−fail[n−1]−1 的倍数。
//
//上述所有的结论都可以很容易地使用反证法证出。
//
//因此，我们在预处理出 fail\textit{fail}fail 数组后，只需要判断 nnn 是否为 n−fail[n−1]−1n - \textit{fail}[n - 1] - 1n−fail[n−1]−1 的倍数即可。
//class Solution {
//public:
//	bool kmp(const string& pattern) {
//		int n = pattern.size();
//		vector<int> fail(n, -1);
//		for (int i = 1; i < n; ++i) {
//			int j = fail[i - 1];
//			while (j != -1 && pattern[j + 1] != pattern[i]) {
//				j = fail[j];
//			}
//			if (pattern[j + 1] == pattern[i]) {
//				fail[i] = j + 1;
//			}
//		}
//		return fail[n - 1] != -1 && n % (n - fail[n - 1] - 1) == 0;
//	}
//
//	bool repeatedSubstringPattern(string s) {
//		return kmp(s);
//	}
//};
//复杂度分析
//
//时间复杂度：O(n)O(n)O(n)，其中 nnn 是字符串 sss 的长度。
//
//空间复杂度：O(n)O(n)O(n)。