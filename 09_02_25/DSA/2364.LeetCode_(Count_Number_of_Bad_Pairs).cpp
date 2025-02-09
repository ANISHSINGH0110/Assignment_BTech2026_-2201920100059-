/*
We need to count the number of "bad pairs" in the array nums. A pair (i, j) is considered bad if:
i < j and j - i != nums[j] - nums[i]


For each element nums[i]:

Compute the key key = nums[i] - i.
Check if the key exists in freq:
If yes, add freq[key] to goodPairs.
Update freq[key] by incrementing it.
Calculate total pairs:
Compute totalPairs = n * (n - 1) / 2.

Compute bad pairs:
Return totalPairs - goodPairs.
*/
class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            // long long ans = 0;
            // for(int i=0;i<nums.size();i++)
            // {
            //     for(int j=i+1;j<nums.size();j++)
            //     {
            //         if(j-i != nums[j]-nums[i])
            //           ans++;
            //     }
            // }
            // return ans;
    
            long long n = nums.size(), goodPairs = 0;
            unordered_map<int, long long> freq;
    
            for (int i = 0; i < n; i++) {
                int key = nums[i] - i;
                if (freq.find(key) != freq.end()) {
                    goodPairs += freq[key];
                }
                freq[key]++;
            }
    
            long long totalPairs = n * (n - 1) / 2;
            return totalPairs - goodPairs;
        }
    };