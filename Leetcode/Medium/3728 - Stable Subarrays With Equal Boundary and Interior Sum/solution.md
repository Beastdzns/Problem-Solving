## Solution
### Approach

We will start by building a prefix sum array. 
In general if stable subarray's starting element(l) is k and ending element(r) is also k
Then
prefix[r] = prefix[l] + 2*capacity[l]           
                OR
prefix[l] = prefix[r] - 2*capacity[r]

Here capacity[l] = capacity[r] = k

We use map to store the pair of {capacity[i], pref[i]}
Then we iterate through the array from start and check if the desired element which will be {capacity[i], pref[i] - 2*capacity[i]} is present in the map, if it is then we add its frequency.

To counter the issue of the subarray's length to be minimum three we use
- Condition 1 (When iterating from start)
i-1>=0
This way we ensure that we push element only after the second element is done checking thus ensuring gap of 2

- Condition 2 (When iterating from the end)

i+1<n
This way we ensure that we push element only after the second last element is done checking thus ensuring gap of 2

``` cpp
class Solution {
    using ll = long long;
public:
    long long countStableSubarrays(vector<int>& capacity) {
        ll count = 0;
        int n = capacity.size();
        vector<ll> pref(n);
        map<pair<int, ll>, int> freq;
        // Prefix Sum
        for(int i=0;i<n;i++){
            pref[i] = capacity[i];
            if(i)
                pref[i] += pref[i-1];
        }

        for(int i=0;i<n;i++){
            count += freq[{capacity[i], pref[i] - 2*capacity[i]}];
            if(i-1>=0)
                freq[{capacity[i-1], pref[i-1]}]++;
        }        
        return count;
    }
};
```