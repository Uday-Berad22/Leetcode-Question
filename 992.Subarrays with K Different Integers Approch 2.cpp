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
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        int ans=0;
        int prefix=0;
        int j=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(m[nums[i]]==0){
                cnt++;
            }
            m[nums[i]]++;
            if(cnt>k){
                prefix=0;
                cnt--;
                m[nums[j]]--;
                j++;
            }
            while(m[nums[j]]>1){
                prefix++;
                m[nums[j]]--;
                j++;

            }
            if(cnt==k){
                ans=ans+(prefix)+1;
            }
        }
        return ans;
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
