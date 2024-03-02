//73. 矩阵置零
//给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
//
//示例 1：
//输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
//输出：[[1,0,1],[0,0,0],[1,0,1]]
//示例 2：
//输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
//输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
//
//提示：
//m == matrix.length
//n == matrix[0].length
//1 <= m, n <= 200
//-2^31 <= matrix[i][j] <= 2^31 - 1
//
//进阶：
//一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
//一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
//你能想出一个仅使用常量空间的解决方案吗？
#include "LeetCode73.hpp"
void Solution::setZeroes(vector<vector<int>>& matrix){
    vector<vector<int>> mark(matrix.size(), vector<int>(matrix[0].size()));
    for (size_t i = 0; i < matrix.size(); i++){
        for (size_t j = 0; j < matrix[0].size(); j++){
            if (matrix[i][j] == 0){
                mark[i][j] = 0;
            }
            else{
                mark[i][j] = 1;
            }
        }
    }
    for (size_t i = 0; i < matrix.size(); i++){
        for (size_t j = 0; j < matrix[0].size(); j++){
            if (mark[i][j] == 0){
                for (size_t k = 0; k < matrix.size(); k++){
                    matrix[k][j] = 0;
                }
                for (size_t l = 0; l < matrix[0].size(); l++){
                    matrix[i][l] = 0;
                }
            }
        }
    }
} 
//方法一：使用标记数组
//思路和算法
//我们可以用两个标记数组分别记录每一行和每一列是否有零出现。
//具体地，我们首先遍历该数组一次，如果某个元素为 0，那么就将该元素所在的行和列所对应标记数组的位置置为 true。最后我们再次遍历该数组，用标记数组更新原数组即可。
//代码
//class Solution {
//public:
//    void setZeroes(vector<vector<int>>& matrix) {
//        int m = matrix.size();
//        int n = matrix[0].size();
//        vector<int> row(m), col(n);
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (!matrix[i][j]) {
//                    row[i] = col[j] = true;
//                }
//            }
//        }
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (row[i] || col[j]) {
//                    matrix[i][j] = 0;
//                }
//            }
//        }
//    }
//};
//复杂度分析
//时间复杂度：O(mn)，其中 m 是矩阵的行数，n 是矩阵的列数。我们至多只需要遍历该矩阵两次。
//空间复杂度：O(m+n)，其中 m 是矩阵的行数，n 是矩阵的列数。我们需要分别记录每一行或每一列是否有零出现。
//
//方法二：使用两个标记变量
//思路和算法
//我们可以用矩阵的第一行和第一列代替方法一中的两个标记数组，以达到 O(1) 的额外空间。但这样会导致原数组的第一行和第一列被修改，无法记录它们是否原本包含 0。因此我们需要额外使用两个标记变量分别记录第一行和第一列是否原本包含 0。
//在实际代码中，我们首先预处理出两个标记变量，接着使用其他行与列去处理第一行与第一列，然后反过来使用第一行与第一列去更新其他行与列，最后使用两个标记变量更新第一行与第一列即可。
//代码
//class Solution {
//public:
//    void setZeroes(vector<vector<int>>& matrix) {
//        int m = matrix.size();
//        int n = matrix[0].size();
//        int flag_col0 = false, flag_row0 = false;
//        for (int i = 0; i < m; i++) {
//            if (!matrix[i][0]) {
//                flag_col0 = true;
//            }
//        }
//        for (int j = 0; j < n; j++) {
//            if (!matrix[0][j]) {
//                flag_row0 = true;
//            }
//        }
//        for (int i = 1; i < m; i++) {
//            for (int j = 1; j < n; j++) {
//                if (!matrix[i][j]) {
//                    matrix[i][0] = matrix[0][j] = 0;
//                }
//            }
//        }
//        for (int i = 1; i < m; i++) {
//            for (int j = 1; j < n; j++) {
//                if (!matrix[i][0] || !matrix[0][j]) {
//                    matrix[i][j] = 0;
//                }
//            }
//        }
//        if (flag_col0) {
//            for (int i = 0; i < m; i++) {
//                matrix[i][0] = 0;
//            }
//        }
//        if (flag_row0) {
//            for (int j = 0; j < n; j++) {
//                matrix[0][j] = 0;
//            }
//        }
//    }
//};
//复杂度分析
//时间复杂度：O(mn)，其中 m 是矩阵的行数，n 是矩阵的列数。我们至多只需要遍历该矩阵两次。
//空间复杂度：O(1)。我们只需要常数空间存储若干变量。
//
//方法三：使用一个标记变量
//思路和算法
//我们可以对方法二进一步优化，只使用一个标记变量记录第一列是否原本存在 0。这样，第一列的第一个元素即可以标记第一行是否出现 0。但为了防止每一列的第一个元素被提前更新，我们需要从最后一行开始，倒序地处理矩阵元素。
//代码
//class Solution {
//public:
//    void setZeroes(vector<vector<int>>& matrix) {
//        int m = matrix.size();
//        int n = matrix[0].size();
//        int flag_col0 = false;
//        for (int i = 0; i < m; i++) {
//            if (!matrix[i][0]) {
//                flag_col0 = true;
//            }
//            for (int j = 1; j < n; j++) {
//                if (!matrix[i][j]) {
//                    matrix[i][0] = matrix[0][j] = 0;
//                }
//            }
//        }
//        for (int i = m - 1; i >= 0; i--) {
//            for (int j = 1; j < n; j++) {
//                if (!matrix[i][0] || !matrix[0][j]) {
//                    matrix[i][j] = 0;
//                }
//            }
//            if (flag_col0) {
//                matrix[i][0] = 0;
//            }
//        }
//    }
//};
//复杂度分析
//时间复杂度：O(mn)，其中 m 是矩阵的行数，n 是矩阵的列数。我们至多只需要遍历该矩阵两次。
//空间复杂度：O(1)。我们只需要常数空间存储若干变量。
