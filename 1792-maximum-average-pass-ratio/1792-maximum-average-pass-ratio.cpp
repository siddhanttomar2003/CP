class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int e) {
        priority_queue<vector<double>>pq;
        double n=classes.size();
        // vector will be [0]will denote delta [1],[2] denote curr num,den;
        // to store the next delta they will give 
        for(int i=0;i<classes.size();i++){
            double a=classes[i][0];
            double b=classes[i][1];
            double curr=a/b;
            double next=(a+1)/(b+1);
            double del=next-curr;
            pq.push({del,a,b});
        }
        while(e--){
            vector<double>temp=pq.top();pq.pop();
            double a=temp[1]+1;
            double b=temp[2]+1;
            double curr=a/b;
            double next=(a+1)/(b+1);
            double del=next-curr;
            pq.push({del,a,b});
        }
        double ans=0;
        while(pq.size()>0){
            vector<double>temp=pq.top();
             ans+=(temp[1]/temp[2]);
             pq.pop();
        }
        return ans/n;
        
    }
};