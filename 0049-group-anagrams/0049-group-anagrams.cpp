class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create an unordered_map to store groups of anagrams.
        // The key is the sorted string, and the value is a vector of strings that are anagrams.
        unordered_map<string, vector<string>> mp;

        // Loop through each string in the input vector 'strs'.
        for (string s : strs) {
            string t = s;            // Create a copy of the original string.
            sort(t.begin(), t.end()); // Sort the copy to get the anagram signature.
            mp[t].push_back(s);      // Add the original string to the vector of anagrams in the map.
        }

        // Prepare the result vector which will contain groups of anagrams.
        vector<vector<string>> anagrams;
        
        // Iterate through the map and add each vector of anagrams to the result.
        for (auto it : mp) {
            anagrams.push_back(it.second); // 'it.second' is the vector of strings (group of anagrams).
        }

        // Return the grouped anagrams.
        return anagrams;
    }
};
