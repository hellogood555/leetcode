#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Fill nums1 from BACK to FRONT, no extra array needed
    // 从前往后O（m*n）
    //void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    //    int i = 0;
    //    int j = 0;
    //    //加上j<n,避免第二个数组为空导致访问第二个数组崩溃
    //    while (i < m&&j<n)
    //    {
    //       
    //        if (nums1[i] >= nums2[j])
    //        {
    //            //尝试从后往前挪，先让后面的把位置让出来
    //            int tmp = m - 1;
    //            while (tmp >= i)
    //            {
    //                nums1[tmp + 1] = nums1[tmp];
    //                tmp--;
    //            }
    //            nums1[i] = nums2[j];
    //    
    //            j++;
    //            m++;//每次数组内容增加后，数组长度m要加加，有效数字加一
    //        }
    //        i++;
    //    }
    //    int k = i;
    //    while (j < n)
    //    {
    //        nums1[k++] = nums2[j++];
    //    }

    //}
    //从后往前O(M+N)
    //对比二者的最后一个数字(从后往前遍历)，拼到返回数组的最后一个
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        //第一个数组和第二个数组均不为空
        //第一个不为空，第二个为空
        //均为空
        while (j >= 0&&i>=0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
        //第一个为空，第二个不为空
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};



void runTestCase(const string& name, vector<int> nums1, int m,
    vector<int> nums2, int n, const vector<int>& expected) {
    Solution sol;
    sol.merge(nums1, m, nums2, n);
    bool ok = (nums1 == expected);
    cout << (ok ? "[PASS] " : "[FAIL] ") << name << "  ->  result: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;
}

int main() {
    runTestCase("Example 1", { 1, 2, 3, 0, 0, 0 }, 3, { 2, 5, 6 }, 3, { 1, 2, 2, 3, 5, 6 });
    runTestCase("Example 2", { 1 }, 1, {}, 0, { 1 });
    runTestCase("Example 3", { 0 }, 0, { 1 }, 1, { 1 });
    runTestCase("All nums1 < nums2", {1, 2, 3, 0, 0, 0}, 3, {4, 5, 6}, 3, {1, 2, 3, 4, 5, 6});
    runTestCase("All nums1 > nums2", { 4, 5, 6, 0, 0, 0 }, 3, { 1, 2, 3 }, 3, { 1, 2, 3, 4, 5, 6 });
    runTestCase("Duplicates", { 2, 2, 3, 0, 0, 0 }, 3, { 1, 2, 4 }, 3, { 1, 2, 2, 2, 3, 4 });
    runTestCase("nums2 empty", { 5, 6, 7 }, 3, {}, 0, { 5, 6, 7 });
    runTestCase("nums1 empty", { 0, 0, 0 }, 0, { 1, 2, 3 }, 3, { 1, 2, 3 });
    return 0;
}