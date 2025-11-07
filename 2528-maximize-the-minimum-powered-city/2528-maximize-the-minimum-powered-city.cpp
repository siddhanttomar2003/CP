typedef long long ll;
class Solution {
public:
    vector<double>l_s;
    bool check(double mini, double lim , double r){
        double count = 0;
        double curr_extra = 0;
        queue<pair<double,double>>q;
        for(double i = 0 ; i < l_s.size() - 1 ; i++){
            if(!q.empty()  && q.front().first < i){
                double num = q.front().second;
                curr_extra -= num;
                q.pop();
            }
            double curr = l_s[i] + curr_extra;
            // if(mini == 5){
            //     cout<< i << "->" << curr <<endl;
            // }
            if(curr >= mini)continue;
            double req = mini - curr;
            count += req;
            curr_extra += req;
            q.push({i + 2 * 1ll * r, req});
        }
        // if(mini == 5) cout << count <<endl;
        return count <= lim;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        double n = stations.size();
        l_s.assign(n + 1, 0);
        for(double i = 0; i < n; i++){
            double left = max((double)0, i - r);
            double right = min(n - (double)1 , i + r);
            // cout << left << " " << right << endl;
            l_s[left]+=(double)stations[i];
            l_s[right + 1]-=(double)stations[i];
        }
        double low = l_s[0];
        // cout << l_s[0] << " ";
        for(double i = 1; i < n; i++){
            l_s[i] += l_s[i - 1];
            low = min(low, l_s[i]);

            // cout << l_s[i] << " ";
        }
 
     
        double ans = low;
        double high = 1e15;
        // cout << low << " " << high << endl;
        while(low <= high){
            double mid = ceil((low + high) / 2);
            if(check(mid, k, (double)r)){
                // make every value greater than mid 
                ans = mid;
                low = mid + (double)1;
            }
            else high = mid - (double)1;
        }
        return ans;
    }
};