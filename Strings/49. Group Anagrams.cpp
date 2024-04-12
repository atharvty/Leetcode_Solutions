class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> mp;

        for(auto s : strs){
            string hashString = "";
            vector<int> freq(26,0);
            for(auto ch:s) freq[ch-'a']++;
            for(int i = 0 ; i < 26 ; i++){
                hashString.push_back(freq[i]);
                hashString.push_back('#');
            }
            mp[hashString].push_back(s);

        }
        vector<vector<string>> anagrams;

        
        for(auto [key,vectorOfStrings]: mp){ 
            anagrams.push_back(vectorOfStrings);
        }
        

        return anagrams;      
    }
};
