class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int count=0;
        int left=0;
        string ans="";
        for(int right=0;right<s.length();right++){
            if(s[right]=='1'){
                count++;
            }
            while(count==k){
                string current=s.substr(left,right-left+1);
                if(ans==""||
                    current.length()<ans.length()||
                    (current.length()==ans.length()&& current<ans)){
                    ans=current;
                }
                if(s[left]=='1'){
                    count--;
                }
                left++;
            }
        }
        return ans;
    }
};