class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size()-1;
        int m = b.size()-1;
        int carry = 0;
        string ans = "";
        while(n>=0 || m>=0 || carry){
            int sum = 0;
            if(n>=0)
                sum += (a[n--]-'0');
            if(m>=0)
                sum += (b[m--]-'0');
            sum += carry;
            carry = sum/2;
            ans = to_string(sum%2) + ans;
        }
        return ans;
    }
};