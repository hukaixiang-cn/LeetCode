//66. ��һ
//����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
//
//���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
//
//����Լ���������� 0 ֮�⣬��������������㿪ͷ��
//
//
//
//ʾ�� 1��
//
//���룺digits = [1, 2, 3]
//�����[1, 2, 4]
//���ͣ����������ʾ���� 123��
//ʾ�� 2��
//
//���룺digits = [4, 3, 2, 1]
//�����[4, 3, 2, 2]
//���ͣ����������ʾ���� 4321��
//ʾ�� 3��
//
//���룺digits = [0]
//�����[1]
//
//
//��ʾ��
//
//1 <= digits.length <= 100
//0 <= digits[i] <= 9
#include "LeetCode66.h"

vector<int> Solution::plusOne(vector<int>& digits) { 
	bool add = true; 
	for (int i = digits.size() - 1; i >= 0; i--)
	{ 
		if (digits[i] == 9)
		{
			digits[i] = 0;
		}
		else
		{
			digits[i]++;
			add = false;
			break;
		}
	}
	if (add)
	{
		digits.insert(digits.begin(), 1);
	}
	return digits;
};
//����һ���ҳ���ĺ�׺ 999
//˼·
//
//�����Ƕ����� digits\textit{ digits }digits ��һʱ������ֻ��Ҫ��ע digits\textit{ digits }digits ��ĩβ�����˶��ٸ� 999 ���ɡ����ǿ��Կ������µ����������
//
//��� digits\textit{ digits }digits ��ĩβû�� 999������[1, 2, 3][1, 2, 3][1, 2, 3]����ô����ֱ�ӽ�ĩβ������һ���õ�[1, 2, 4][1, 2, 4][1, 2, 4] �����أ�
//
//��� digits\textit{ digits }digits ��ĩβ�����ɸ� 999������[1, 2, 3, 9, 9][1, 2, 3, 9, 9][1, 2, 3, 9, 9]����ô����ֻ��Ҫ�ҳ���ĩβ��ʼ�ĵ�һ����Ϊ 999 ��Ԫ�أ��� 333������Ԫ�ؼ�һ���õ�[1, 2, 4, 9, 9][1, 2, 4, 9, 9][1, 2, 4, 9, 9]�����ĩβ�� 999 ȫ�����㣬�õ�[1, 2, 4, 0, 0][1, 2, 4, 0, 0][1, 2, 4, 0, 0] �����ء�
//
//��� digits\textit{ digits }digits ������Ԫ�ض��� 999������[9, 9, 9, 9, 9][9, 9, 9, 9, 9][9, 9, 9, 9, 9]����ô��Ϊ[1, 0, 0, 0, 0, 0][1, 0, 0, 0, 0, 0][1, 0, 0, 0, 0, 0]������ֻ��Ҫ����һ�����ȱ� digits\textit{ digits }digits �� 111 �������飬����Ԫ����Ϊ 111������Ԫ����Ϊ 000 ���ɡ�
//
//�㷨
//
//��ֻ��Ҫ������ digits\textit{ digits }digits ����һ������������ҳ���һ����Ϊ 999 ��Ԫ�أ������һ������������Ԫ�����㼴�ɡ���� digits\textit{ digits }digits �����е�Ԫ�ؾ�Ϊ 999����ô��Ӧ�š�˼·�����ֵĵ����������������Ҫ����һ���µ����顣
//class Solution {
//public:
//	vector<int> plusOne(vector<int>& digits) {
//		int n = digits.size();
//		for (int i = n - 1; i >= 0; --i) {
//			if (digits[i] != 9) {
//				++digits[i];
//				for (int j = i + 1; j < n; ++j) {
//					digits[j] = 0;
//				}
//				return digits;
//			}
//		}
//
//		// digits �����е�Ԫ�ؾ�Ϊ 9
//		vector<int> ans(n + 1);
//		ans[0] = 1;
//		return ans;
//	}
//}; 
//���Ӷȷ���
//
//ʱ�临�Ӷȣ�O(n)O(n)O(n)������ nnn ������ digits\textit{ digits }digits �ĳ��ȡ�
//
//�ռ临�Ӷȣ�O(1)O(1)O(1)������ֵ������ռ临�Ӷȡ�