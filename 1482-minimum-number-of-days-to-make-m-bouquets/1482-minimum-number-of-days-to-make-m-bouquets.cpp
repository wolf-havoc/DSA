class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k, int current){
        int bloom = 0;
        int count = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= current){
                count++;
                if(count == k){
                    bloom++;
                    count = 0;
                }
                
            }
            else count = 0;
        }
        return bloom >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        int low = mini;
        int high = maxi;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(bloomDay,m,k,mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};