class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int >mp;
        for(int i=0;i<nums.size();i++){
            int recquired=target-nums[i];
            if(mp.find(recquired)!=mp.end()){
                return {mp[recquired],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};