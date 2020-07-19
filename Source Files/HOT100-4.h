#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int len1 = nums1.size();
        int len2 = nums2.size();

        if (len2 == 0)
        {
            if (len1 % 2 == 0)
                return (nums1[len1/2] + nums1[len1/2-1]) / 2;
            else
                return nums1[len1/2];
        }
        else if (len1 == 0)
        {
            if (len2 % 2 == 0)
                return (nums2[len2/2] + nums1[len2/2-1]) / 2;
            else
                return nums1[len2/2];
        }

        int index1 = 0;
        int index2 = 0;

        while (index1 < len1 && index2 < len2)
        {
            if ((index1 + index2) >= (len1 + len2)/2)  break;

            if (nums1[index1] <= nums2[index2])
                index1++;
            else if (nums1[index1] > nums2[index2])
                index2++;
        }

        cout << nums1[index1] << " " << nums2[index2] << endl;

        /*while (index1 == len1-1 && index2 < len2)
        {

        }

        while (index2 == len2-1 && index1 < len1)
        {

        } */

    }
};