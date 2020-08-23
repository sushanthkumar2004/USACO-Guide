// https://leetcode.com/problems/find-pivot-index/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> sums = {0};
        for (int i=0; i<nums.size(); i++){
            sums.push_back(sums.back()+nums[i]);
        }
        for (int i=0; i<nums.size(); i++){
            if (2*sums[i] == sums.back() - nums[i]){
                return i;
            }
        }
        return -1; 
    }
};
