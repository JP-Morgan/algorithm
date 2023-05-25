/*
* ���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺͲ�ͬ�����ַ�����ʽ���ء�
*�㲻��ʹ���κ΃Ƚ������ڴ���������Ŀ⣨���� BigInteger���� Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��
*��Դ�����ۣ�LeetCode��
*���ӣ�https://leetcode.cn/problems/add-strings
*����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע�������� 
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        string strRet;
        int carry = 0;
        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
            int val2 = end2 >= 0 ? num2[end2] - '0' : 0;

            int ret = val1 + val2 + carry;
            carry = ret / 10;
            ret = ret % 10;

            strRet += ('0' + ret);
            --end1;
            --end2;
        }
        if (carry == 1)
        {
            strRet = strRet + '1';
        }
        reverse(strRet.begin(), strRet.end());
        return strRet;
    }
};