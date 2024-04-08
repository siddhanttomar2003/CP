class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count1=0;
        int count0=0;
        for(int i=0;i<students.size();i++){
            if(students[i]==1)count1++;
            else count0++;
        }
        for(int i=0;i<students.size();i++){
            if(sandwiches[i]==1){
                if(count1>0)count1--;
                else return count1+count0;
            }
            else {
                if(count0>0)count0--;
                else return count1+count0;
            }
            
        }
        return 0;
        
    }
};