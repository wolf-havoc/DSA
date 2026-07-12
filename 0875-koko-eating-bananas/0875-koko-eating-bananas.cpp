class Solution {
public:
    bool check(vector<int>& piles, int h, int current){
        long long hours = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i] % current == 0){
                hours += piles[i]/current;
            }
            else hours += piles[i]/current + 1;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,piles[i]);
        }
        int low = 1;
        int high = maxi;
        int ans = 0;
        while(low <= high){

            int mid = low + (high-low)/2;

            if(check(piles,h,mid)){

                ans = mid;
                high = mid-1;

            }
            else{

                low = mid+1;

            }

        }
        return ans;
    }
};