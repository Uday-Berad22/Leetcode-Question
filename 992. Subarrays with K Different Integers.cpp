/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length

*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int count_subarrays_having_atmost_k_distinct_elements(vector<int> &nums,int k){
        unordered_map<int,int> m;
        int count=0;
        int i=0,j=0;
        int n=nums.size();
        for(i=0;i<n;i++){
            m[nums[i]]++;
            if(m.size()>k){
                while(m.size()>k){
                    if(m[nums[j]]<=1){
                        m.erase(nums[j++]);
                    }
                    else{
                        m[nums[j++]]--;
                    }
                }
            }
            count+=(i-j+1);
        }
        return count;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
         return count_subarrays_having_atmost_k_distinct_elements(nums,k)-count_subarrays_having_atmost_k_distinct_elements(nums,k-1);
    }
};
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        Solution obj;
        cout<<obj.subarraysWithKDistinct(nums,k)<<endl;
    }
    return 0;
}
