class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minodd =INT_MAX;
        int mineven=INT_MAX;
        for(int x:nums1){
            if(x%2!=0){
                minodd=min(minodd,x);
            }
            else{
                mineven=min(mineven,x);
            }
        }
        if(minodd==INT_MAX){
            return true;
        }
        if(mineven==INT_MAX){
            return true;
        }
        if(minodd<mineven){
            return true;
        }
        return false;
    }
};