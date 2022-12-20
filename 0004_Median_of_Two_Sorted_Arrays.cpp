/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000


Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/


//Method #1:

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        for(int i=0; i<nums2.size(); i++)
        {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        double median;
        int len = nums1.size();
        if(len%2==0)
        {
            median=(double)(nums1[len/2-1]+nums1[len/2+1-1])/2,0;
        }
        else
        {
            median=nums1[len/2];
        }
        return median;
    }
};


//Method 2:

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> tmp;
        int i=0, j=0;
        double ans;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<=nums2[j])
            {
                tmp.push_back(nums1[i]);
                i++;
            }
            else
            {
                tmp.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size())
        {
            tmp.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size())
        {
            tmp.push_back(nums2[j]);
            j++;
        }
        if(tmp.size()%2==0)
        {
            ans = (double)(tmp[tmp.size()/2-1]+tmp[tmp.size()/2+1-1])/2.0;
        }
        else
        {
            ans = tmp[tmp.size()/2];
        }
        return ans;
    }
};
