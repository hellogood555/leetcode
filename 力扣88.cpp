#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Fill nums1 from BACK to FRONT, no extra array needed
    // 从前往后
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = 0;
        int j = 0;
        while (i < m)
        {

            if (nums1[i] >= nums2[j])
            {
                //这么挪会让i+1的值被i覆盖，应该是后面的数先把位置让出来
                //nums1[i + 1] = nums1[i];
                //尝试从后往前挪，先让后面的把位置让出来
                nums1[i] = nums2[j];
                j++;
            }
            i++;
        }
        int k = i;
        while (j < n)
        {
            nums1[k++] = nums2[j++];
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
    runTestCase("All nums1 < nums2", { 1, 2, 3, 0, 0, 0 }, 3, { 4, 5, 6 }, 3, { 1, 2, 3, 4, 5, 6 });
    runTestCase("All nums1 > nums2", { 4, 5, 6, 0, 0, 0 }, 3, { 1, 2, 3 }, 3, { 1, 2, 3, 4, 5, 6 });
    runTestCase("Duplicates", { 2, 2, 3, 0, 0, 0 }, 3, { 1, 2, 4 }, 3, { 1, 2, 2, 2, 3, 4 });
    runTestCase("nums2 empty", { 5, 6, 7 }, 3, {}, 0, { 5, 6, 7 });
    runTestCase("nums1 empty", { 0, 0, 0 }, 0, { 1, 2, 3 }, 3, { 1, 2, 3 });
    return 0;
}