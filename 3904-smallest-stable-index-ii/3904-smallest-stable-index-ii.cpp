class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
       vector<int>prefixmax(n);
       vector<int>sufixmin(n);
       prefixmax[0]=nums[0];
       for(int i=1;i<n;i++){
        prefixmax[i]=max(prefixmax[i-1],nums[i]);
       }
       sufixmin[n-1]=nums[n-1];
       for(int i=n-2;i>=0;i--){
        sufixmin[i]=min(sufixmin[i+1],nums[i]);
       }
       for(int i=0;i<n;i++){
        if(prefixmax[i]-sufixmin[i] <=k){
            return i;
        }
       }
       return -1;
    }
};