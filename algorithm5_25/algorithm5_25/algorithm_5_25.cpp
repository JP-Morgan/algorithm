/*
* 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
*你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
*来源：力扣（LeetCode）
*链接：https://leetcode.cn/problems/add-strings
*著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 
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