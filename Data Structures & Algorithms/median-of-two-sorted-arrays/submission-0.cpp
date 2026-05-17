class Solution {
    public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();

        // Ensure nums1 is the shorter array
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0;
        int high = m;
        int total = m + n;

        while (low <= high) {
            int mid = (low + high) / 2;
            // Using (total + 1) / 2 ensures the left side gets the extra element if total is odd
            int rem = (total + 1) / 2 - mid; 

            // Initialize boundaries with infinity/negative infinity
            int lastElementOfFirstArray = (mid == 0) ? INT_MIN : nums1[mid - 1];
            int firstElementOfFirstArray = (mid == m) ? INT_MAX : nums1[mid];

            int lastElementOfSecondArray = (rem == 0) ? INT_MIN : nums2[rem - 1];
            int firstElementOfSecondArray = (rem == n) ? INT_MAX : nums2[rem];

            // Check if we found the correct partition
            if (lastElementOfSecondArray <= firstElementOfFirstArray &&
                lastElementOfFirstArray <= firstElementOfSecondArray) {
                
                // If total length is odd, the median is the maximum of the left partition
                if (total % 2 != 0) {
                    return max(lastElementOfFirstArray, lastElementOfSecondArray);
                } 
                // If total length is even, it's the average of the middle two elements
                else {
                    int left_max = max(lastElementOfFirstArray, lastElementOfSecondArray);
                    int right_min = min(firstElementOfFirstArray, firstElementOfSecondArray);
                    return (left_max + right_min) / 2.0;
                }
            }
            else if (lastElementOfFirstArray > firstElementOfSecondArray) {
                // Too many elements from nums1 on the left side, move left
                high = mid - 1;
            } else {
                // Too few elements from nums1 on the left side, move right
                low = mid + 1;
            }
        }
        return 0.0;
    }
};