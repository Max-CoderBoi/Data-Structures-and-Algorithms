class Solution {
public:
    /*
    int f(int ind,vector<int>&nums,vector<int>&dp){
        if(ind == 0){
            return nums[0];
        }
        if(ind < 0){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int peek = INT_MIN;
        
        if(ind >= 1){
            peek = nums[ind] + f(ind-2,nums,dp);
        }
        int npeek = 0 + f(ind-1,nums,dp);
        
        return dp[ind] = max(peek,npeek);
        
        
    }
    */
    // int rob(vector<int>& nums) {
        
    //     int ind = nums.size();
       
    //     vector<int>dp(ind,0);
        
    //     dp[0] = nums[0];
        
    //     int i;
    //     if(i == 0){
    //         return nums[0];
    //     }
        
    //     if(i < 0){
    //         return 0;
    //     }
        
    //     for(i = 1; i < ind; i++){
    //         int peek = nums[i];
            
    //         if(i > 1)peek += dp[i-2];
    //         int npeek = 0 + dp[i-1];
    //         dp[i] = max(peek,npeek);
    //     }
    //     return dp[ind-1];

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Handle edge cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Initialize dp array
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // Fill dp array using bottom-up approach
        for (int i = 2; i < n; i++) {
            int robCurrent = nums[i] + dp[i - 2];  // Rob this house and add the amount from two houses back
            int skipCurrent = dp[i - 1];           // Skip this house and take the max from the previous house
            dp[i] = max(robCurrent, skipCurrent);  // Choose the maximum of robbing or skipping
        }
        
        return dp[n - 1];  // The last element contains the maximum loot
    }
};

        /*
        //return f(n - 1, nums,dp);
         int prev2 = nums[0];
         int prev1 = 0;
         int i;
          if(i == 0){
              return prev2;
          }
          if(i < 0){
             return prev1;
          }
        for( i = 0; i < nums.size(); i++){
            int peek = nums[i];
            if(i > 1)peek+=prev2;
            int npeek = 0 + prev1;
            
            int cur =  max(npeek,peek);
            prev2 = prev1;
            prev1 = cur;
            
            
        }
        return prev1;
        */
        
    }
};
