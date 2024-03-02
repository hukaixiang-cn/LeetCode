// 2788. 按分隔符拆分字符串
// 给你一个字符串数组 words 和一个字符 separator ，请你按 separator 拆分 words 中的每个字符串。
// 返回一个由拆分后的新字符串组成的字符串数组，不包括空字符串 。
// 注意
// separator 用于决定拆分发生的位置，但它不包含在结果字符串中。
// 拆分可能形成两个以上的字符串。
// 结果字符串必须保持初始相同的先后顺序。

// 示例 1：
// 输入：words = ["one.two.three","four.five","six"], separator = "."
// 输出：["one","two","three","four","five","six"]
// 解释：在本示例中，我们进行下述拆分：
// "one.two.three" 拆分为 "one", "two", "three"
// "four.five" 拆分为 "four", "five"
// "six" 拆分为 "six"
// 因此，结果数组为 ["one","two","three","four","five","six"] 。
// 示例 2：
// 输入：words = ["$easy$","$problem$"], separator = "$"
// 输出：["easy","problem"]
// 解释：在本示例中，我们进行下述拆分：
// "$easy$" 拆分为 "easy"（不包括空字符串）
// "$problem$" 拆分为 "problem"（不包括空字符串）
// 因此，结果数组为 ["easy","problem"] 。
// 示例 3：
// 输入：words = ["|||"], separator = "|"
// 输出：[]
// 解释：在本示例中，"|||" 的拆分结果将只包含一些空字符串，所以我们返回一个空数组 [] 。

// 提示：
// 1 <= words.length <= 100
// 1 <= words[i].length <= 20
// words[i] 中的字符要么是小写英文字母，要么就是字符串 ".,|$#@" 中的字符（不包括引号）
// separator 是字符串 ".,|$#@" 中的某个字符（不包括引号）
#include "LeetCode2788.hpp"
vector<string> Solution::splitWordsBySeparator(vector<string> &words, char separator)
{
    vector<string> result;
    string temp;
    int idx = 0;
    for (auto word : words)
    {
        idx = 0;
        for (size_t i = 0; i < word.size(); i++)
        {
            if (word[i] == separator)
            {
                if (i > idx)
                {
                    temp = word.substr(idx, i - idx);
                    result.push_back(temp);
                }
                idx = i + 1;
            }
        }
        if (word.size() > idx)
        {
            temp = word.substr(idx, word.size() - idx);
            result.push_back(temp);
        }
    }
    return result;
}