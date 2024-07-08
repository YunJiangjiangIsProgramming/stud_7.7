#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>


using namespace std;

//#include"vector.h"

//只出现一次数字3的解法
class Solution1 {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        if (nums.size() == 2)
        {
            return nums;
        }
        int num = 0;
        for (auto n : nums)
        {
            num ^= n;
        }
        int mask = 1;
        while (!(num & mask))
        {
            mask <<= 1;

        }
        vector<int> res(2, 0);
        for (auto n : nums)
        {
            if ((n & mask) == 0)
            {
                res[0] ^= n;

            }
            else
            {
                res[1] ^= n;
            }
        }
        return res;
    }
    

};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        // 创建一个长度为32的数组，用于存储每个位上1出现的次数
        int bitArray[32] = { 0 };

        // 遍历数组中的每个数字
        for (auto val : nums) {
            // 遍历数字的每一位
            for (size_t i = 0; i < 32; i++) {
                // 如果当前位为1，则在bitArray中增加计数
                if (val & (1 << i)) {
                    bitArray[i]++;
                }
            }
        }

        int num = 0;
        // 遍历bitArray中的每个位
        for (size_t i = 0; i < 32; i++) {
            // 如果当前位上1出现的次数不是3的倍数，说明这个位在结果数字中也是1
            if (bitArray[i] % 3 == 1) {
                num |= (1 << i); // 使用或操作将该位设置到结果中
            }
        }

        // 返回只出现一次的数字
        return num;
    }
};

class Solution3 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 初始化异或结果为0
        int xorResult = 0;

        // 遍历数组，进行异或操作
        // 因为相同的数字异或结果为0，所以最后的结果就是那两个只出现一次的数字的异或结果
        for (int num : nums) {
            xorResult ^= num;
        }

        // 找到异或结果中第一个为1的位
        // 这个位意味着这两个数字在这一位上一个是0，一个是1
        // 我们可以根据这个位将数组中的数字分成两组
        size_t i = 0;
        for (; i < 32; i++) {
            if (xorResult & (1 << i)) {
                break;
            }
        }

        // 初始化两个数字为0
        int num1 = 0, num2 = 0;

        // 遍历数组，根据异或结果中的第一个为1的位将数字分成两组进行异或操作
        // 因为其他数字都出现两次，所以相同的数字会被分到同一组
        // 而落单的数字会被分到不同组，因此每一组异或的结果就是那个落单的数字
        for (int num : nums) {
            if (num & (1 << i)) {
                num1 ^= num;
            }
            else {
                num2 ^= num;
            }
        }

        // 返回这两个数字
        vector<int> v;
        v.push_back(num1);
        v.push_back(num2);
        return v;
    }
};
//杨辉三角(vector<vector<int>>)二维数组
class Solution4 {
public:
    // 这个函数用于生成杨辉三角形的前numRows行
    vector<vector<int>> generate(int numRows) {
        // 创建一个二维向量vv来存储杨辉三角形的每一行
        vector<vector<int>> vv;
        // 调整vv的大小，使其能够容纳numRows行
        vv.resize(numRows);

        // 遍历每一行
        for (size_t i = 0; i < numRows; ++i)
        {
            // 调整vv中第i行的尺寸，使其能够容纳i+1个元素
            vv[i].resize(i + 1);
            // 每一行的开始和结尾元素都是1
            vv[i][0] = 1;
            vv[i][vv[i].size() - 1] = 1;
        }

        // 再次遍历每一行，但这次我们从第3行开始，因为第1行和第2行已经在上面的循环中处理了
        for (size_t i = 2; i < vv.size(); ++i)
        {
            // 遍历当前行中的每个元素，不包括第一个和最后一个元素，因为它们已经被设置为1
            for (size_t j = 1; j < vv[i].size() - 1; ++j)
            {
                // 计算当前元素的值，它是上一行的相邻两个元素的和
                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
            }
        }
        // 返回完整的杨辉三角形
        return vv;
    }
};

void test_vector1()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    cout << v.max_size() << endl;

    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();

    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}

void test_vector2()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout << v.capacity() << endl;

    v.reserve(10);
    cout << v.capacity() << endl;

    // 比当前容量小时，不缩容
    v.reserve(4);
    cout << v.capacity() << endl;

    v.resize(8);
    v.resize(15, 1);
    v.resize(3);
}

int main()
{
    test_vector1();
    test_vector2();

	return 0;
}