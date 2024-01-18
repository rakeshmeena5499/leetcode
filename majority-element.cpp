class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for(int num : nums){
            if(count == 0){         // Bayor Moore Algorithm
                candidate = num;    // The element which is in majority will 
            }                       // be set to candidate as its count will 
            if(candidate == num){   // never be able to get to zero once it is set.
                count+=1;
            }
            else{
                count-=1;
            }
        }
        return candidate;
    }
};