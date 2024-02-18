#define pll pair<long long, long long>

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> rooms;
        for(int i=0;i<n;i++){
            rooms.push(i);
        }  
        vector<int> freq(n, 0);
        priority_queue<pll, vector<pll>, greater<pll>> intervals;
        for(int i=0;i<meetings.size();i++){
            long long start = meetings[i][0];
            long long end   = meetings[i][1];
            while(!intervals.empty() && intervals.top().first <= start){    // Freeing up the rooms as meetings ended before starting current meeting
                pll temp = intervals.top();
                intervals.pop();
                int room = temp.second;
                rooms.push(room);
            }
            if(!rooms.empty()){                 // After doing that, if we've free rooms we use it
                int room = rooms.top();
                rooms.pop();
                freq[room]++;
                intervals.push({end, room});
            }
            else{                               // Else we use the room which frees up the earliest, delaying our meeting thereby
                pll temp = intervals.top();
                intervals.pop();
                long long delay = temp.first - start;
                int room = temp.second;
                freq[room]++;
                intervals.push({end+delay, room});
            }
        }

        int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        for (int i = 0; i < n; i++) {
            if (freq[i] > maxMeetingCount) {
                maxMeetingCount = freq[i];
                maxMeetingCountRoom = i;
            }
        }
        return maxMeetingCountRoom;
    }
};