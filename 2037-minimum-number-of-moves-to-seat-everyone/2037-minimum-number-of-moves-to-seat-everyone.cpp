class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(students.begin(),students.end());
        sort(seats.begin(),seats.end());
        int count=0;
        int n=seats.size();
        for(int i=0;i<n;i++){
            
                count+=abs(students[i]-seats[i]);
        
        }
        return count;
    }
};