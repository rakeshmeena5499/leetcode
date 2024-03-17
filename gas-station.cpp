class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int total = 0;
        int gasSum = 0;
        int costSum = 0;
        for(int i=0;i<n;i++){
            gasSum += gas[i];
            costSum += cost[i];
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                start = i+1;
            }
        }
        if(gasSum < costSum)
            return -1;
        else
            return start;
    }
};