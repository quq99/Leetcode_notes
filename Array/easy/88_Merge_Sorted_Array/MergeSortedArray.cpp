// MergeSortedArray.cpp

#include<vector>

using std::vector;

class MergeSortedArray {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            // inplace sort in nums1. from end to start.
            // tar means the new position in nums1.
            int i = m-1;
            int j = n-1;
            int tar = m+n-1;
            while (j>=0) {
                if (i>=0 && nums1[i] > nums2[j]) {
                    nums1[tar] = nums1[i];
                    --i;
                }
                else {
                    nums1[tar] = nums2[j];
                    --j;
                }
                --tar;
            }
        }
};
