class Solution {
public:
    long long numberOfPairs(vector<int>& A, vector<int>& B, int k) {
        unordered_map<long long int, long long int> mpp;
        unordered_map<long long int, long long int> freqMap;

        for (int b : B) {
            freqMap[1ll*b*k]++;
        }

        long long int count = 0;
        for (int a : A)
        {
            long long int sum = 0;
            if(mpp.find(a)!=mpp.end())
            {
                count += mpp[a];
                continue;
            }
            for (int factor = 1; factor * factor <= a; ++factor) 
            {
                if (a % factor == 0)
                {
                    if (freqMap.find(factor) != freqMap.end()) 
                    {
                        count += 1ll*freqMap[factor];
                        sum +=  1ll*freqMap[factor];
                    }
                    
                    int complementaryFactor = a / factor;
                    if (complementaryFactor != factor && freqMap.find(complementaryFactor) != freqMap.end()) 
                    {
                        count += 1ll*freqMap[complementaryFactor];
                        sum +=  1ll*freqMap[complementaryFactor];
                    }
                }
            }
            mpp[a] = sum;
        }

        return count;
    }
};