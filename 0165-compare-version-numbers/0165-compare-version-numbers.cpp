class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();
        vector<int>temp1, temp2;
        for(int i = 0; i < n; i++){
             string temp = "";
             while(i < n && version1[i] != '.'){
                temp += version1[i];
                i++;
             }
             int num = stoi(temp);
             temp1.push_back(num);
        }
        for(int i = 0; i < m; i++){
             string temp = "";
             while(i < m && version2[i] != '.'){
                temp += version2[i];
                i++;
             }
             int num = stoi(temp);
             temp2.push_back(num);
        }
        int i = 0, j = 0;
        while(i < temp1.size() && j < temp2.size()){
            if(temp1[i] < temp2[j])return -1;
            else if(temp1[i] > temp2[j])return 1;
            else {
                i++;
                j++;
            }
        }
        if(i == temp1.size() && j == temp2.size())return 0;
        if(i < temp1.size()){
            while(i < temp1.size()){
                if(temp1[i] > 0)return 1;
                i++;
            }
            return 0;
        }
        else {
            while(i < temp2.size()){
                if(temp2[i] > 0)return -1;
                i++;
            }
            return 0;
        }
        return 0;
    }
};