class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int a,b =0;
        while (b<n){
            if (nums[a] == nums[b]){
                b++;
            }
            else if (nums[a] != nums[b]){
                a++;
                nums[a] = nums[b];
            }
        }
    return a+1;    
    }
};