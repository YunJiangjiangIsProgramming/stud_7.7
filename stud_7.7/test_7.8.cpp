#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>


using namespace std;

//#include"vector.h"

//ֻ����һ������3�Ľⷨ
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
        // ����һ������Ϊ32�����飬���ڴ洢ÿ��λ��1���ֵĴ���
        int bitArray[32] = { 0 };

        // ���������е�ÿ������
        for (auto val : nums) {
            // �������ֵ�ÿһλ
            for (size_t i = 0; i < 32; i++) {
                // �����ǰλΪ1������bitArray�����Ӽ���
                if (val & (1 << i)) {
                    bitArray[i]++;
                }
            }
        }

        int num = 0;
        // ����bitArray�е�ÿ��λ
        for (size_t i = 0; i < 32; i++) {
            // �����ǰλ��1���ֵĴ�������3�ı�����˵�����λ�ڽ��������Ҳ��1
            if (bitArray[i] % 3 == 1) {
                num |= (1 << i); // ʹ�û��������λ���õ������
            }
        }

        // ����ֻ����һ�ε�����
        return num;
    }
};

class Solution3 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // ��ʼ�������Ϊ0
        int xorResult = 0;

        // �������飬����������
        // ��Ϊ��ͬ�����������Ϊ0���������Ľ������������ֻ����һ�ε����ֵ������
        for (int num : nums) {
            xorResult ^= num;
        }

        // �ҵ�������е�һ��Ϊ1��λ
        // ���λ��ζ����������������һλ��һ����0��һ����1
        // ���ǿ��Ը������λ�������е����ֳַ�����
        size_t i = 0;
        for (; i < 32; i++) {
            if (xorResult & (1 << i)) {
                break;
            }
        }

        // ��ʼ����������Ϊ0
        int num1 = 0, num2 = 0;

        // �������飬����������еĵ�һ��Ϊ1��λ�����ֳַ��������������
        // ��Ϊ�������ֶ��������Σ�������ͬ�����ֻᱻ�ֵ�ͬһ��
        // ���䵥�����ֻᱻ�ֵ���ͬ�飬���ÿһ�����Ľ�������Ǹ��䵥������
        for (int num : nums) {
            if (num & (1 << i)) {
                num1 ^= num;
            }
            else {
                num2 ^= num;
            }
        }

        // ��������������
        vector<int> v;
        v.push_back(num1);
        v.push_back(num2);
        return v;
    }
};
//�������(vector<vector<int>>)��ά����
class Solution4 {
public:
    // �����������������������ε�ǰnumRows��
    vector<vector<int>> generate(int numRows) {
        // ����һ����ά����vv���洢��������ε�ÿһ��
        vector<vector<int>> vv;
        // ����vv�Ĵ�С��ʹ���ܹ�����numRows��
        vv.resize(numRows);

        // ����ÿһ��
        for (size_t i = 0; i < numRows; ++i)
        {
            // ����vv�е�i�еĳߴ磬ʹ���ܹ�����i+1��Ԫ��
            vv[i].resize(i + 1);
            // ÿһ�еĿ�ʼ�ͽ�βԪ�ض���1
            vv[i][0] = 1;
            vv[i][vv[i].size() - 1] = 1;
        }

        // �ٴα���ÿһ�У���������Ǵӵ�3�п�ʼ����Ϊ��1�к͵�2���Ѿ��������ѭ���д�����
        for (size_t i = 2; i < vv.size(); ++i)
        {
            // ������ǰ���е�ÿ��Ԫ�أ���������һ�������һ��Ԫ�أ���Ϊ�����Ѿ�������Ϊ1
            for (size_t j = 1; j < vv[i].size() - 1; ++j)
            {
                // ���㵱ǰԪ�ص�ֵ��������һ�е���������Ԫ�صĺ�
                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
            }
        }
        // �������������������
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

    // �ȵ�ǰ����Сʱ��������
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