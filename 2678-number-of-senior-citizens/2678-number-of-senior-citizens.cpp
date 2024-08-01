class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(int i=0;i<details.size();i++){
            string temp=details[i];
           int a=temp[11]-48;int b=temp[12]-48;
            
            int age=a*10+b;
            if(age>60)count++;
        }
        return count;
    }
};