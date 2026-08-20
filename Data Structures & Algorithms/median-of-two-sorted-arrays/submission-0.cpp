class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> resultant = mergeArray(nums1, nums2);
        int resSize = resultant.size();
        if(resSize % 2 == 1){
            int mid = resSize / 2;
            double result = (double)resultant[mid];
            return result;
        } else {
            int r = resSize / 2;
            int l = r - 1;
            double result = (double)(resultant[r] + resultant[l]) / 2;
            return result;
        }
    }

    vector<int> mergeArray(vector<int>& nums1, vector<int>& nums2){
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res;
        int i = 0, j = 0;
        while(i < m && j < n){
            if(nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                res.push_back(nums2[j]);
                i++;
                j++;
            } else if(nums1[i] < nums2[j]){
                res.push_back(nums1[i]);
                i++;
            } else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m){
            res.push_back(nums1[i]);
            i++;
        }
        while(j < n){
            res.push_back(nums2[j]);
            j++;
        }
        return res;
    }
};
