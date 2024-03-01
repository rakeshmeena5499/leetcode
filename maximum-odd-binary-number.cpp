class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int count = 0;
        for(char ch : s){
            if(ch=='1')
                count++;
        }
        string ans = "";
        for(int i=0;i<n-count;i++){
            ans+='0';
        }
        for(int i=1;i<count;i++){
            ans = '1'+ans;
        }
        ans += '1';
        return ans;
    }
};