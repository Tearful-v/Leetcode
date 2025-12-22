class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int>mp;
        int lenght = s.size();
        int start = 0;
        int count = 0;
        int max = 0;
        for(int i = 0; i < lenght; i++){
            if(mp.find(s[i]) != mp.end()){
                if(mp[s[i]] < start){
                mp[s[i]] = i;
                count++;
                }
                else{
                    start = mp[s[i]] + 1;
                    count = i - start + 1;
                    mp[s[i]] = i;
                }
            }
            else{
                mp.insert({ s[i], i });
                count++;
            }
            max = std::max(max, count);
        }
        max = std::max(max, count);
        return max;
    }
};