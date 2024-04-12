// The question which was asked by Salesforce in their test about Grouping Anagrams and returning 
// the anagram with the highest count. You will have to create a new freq map which runs 
// through main for loop and keep track of the frequencies of the anagrams.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> mp;
        unordered_map <string, int> freqmp;
        int max_count = 0;
        string goat = "";
        for(auto s : strs){
            string hashString = "";
            vector<int> freq(26,0);
            for(auto ch:s) freq[ch-'a']++;
            for(int i = 0 ; i < 26 ; i++){
                hashString.push_back(freq[i]);
                hashString.push_back('#');
            }
            mp[hashString].push_back(s);
            freqmp[hashString]++;
        }
        vector<vector<string>> anagrams;
        vector<vector<string>> goatedanagram;
        
        for(auto [key,vectorOfStrings]: mp){ 
            anagrams.push_back(vectorOfStrings);
        }
        for(auto [key,count]: freqmp){ 
            if(count>max_count){
                max_count = count;
                goat = key;     
            }      
        }  
        for(auto [key,vectorOfStrings]: mp){ 
            if(key==goat)
            goatedanagram.push_back(vectorOfStrings);
        } 
        cout<<goat<<max_count<<endl;
        

        return goatedanagram;      
    }
};
