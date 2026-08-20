class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        long long ans=2LL*n;
        unordered_map<int ,set<int>> mp;
        for(auto seat:reservedSeats){
            mp[seat[0]].insert(seat[1]);
        }
        for(auto row: mp){
            set<int>s=row.second;
            bool left=true;
            bool middle=true;
            bool right=true;
            for(int i=2;i<=5;i++){
                if(s.count(i)){
                    left=false;
                    break;
                }
            }
            for(int i=4;i<=7;i++){
                if(s.count(i)){
                    middle=false;
                    break;
                }
            }
            for(int i=6;i<=9;i++){
                if(s.count(i)){
                    right=false;
                    break;
                }
            }
            int groups=0;
            if(left && right){
                groups=2;
            }
            else if(left||middle||right){
                groups=1;
            }
            ans-=(2-groups);
        }
        return ans;
    }
};