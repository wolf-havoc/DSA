class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n+1);
        vector<int> post(n+1);
        vector<int> result(n);
        pre[0] = 1;
        post[n] = 1;
        for(int i=1;i<=n;i++){
            pre[i] = nums[i-1] * pre[i-1];

        }
        for(int i = n-1;i>=0;i--){
            post[i] = post[i+1] * nums[i];
        }
        for(int i=0;i<n;i++){
            result[i] =  pre[i] * post[i+1];
        }
        return result;
    }
};