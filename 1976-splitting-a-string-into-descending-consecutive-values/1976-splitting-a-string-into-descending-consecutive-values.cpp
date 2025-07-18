class Solution {
private:
    bool found = false;
    void solve(const string& s, vector<long>& soFar, int idx){
        if(found){
            return;
        }
        if(idx == s.size()){            
            found = soFar.size() > 1;
            return;
        }
        long val = 0;        
        for(int i = idx; i < s.size(); i++){            
            val = 10 * val + (s[i] - '0');            
            if (log10(val) > 10 || (!soFar.empty() && val >= soFar.back())) {
                return;
            }
            if(soFar.empty() || soFar.back() - val == 1){
                soFar.push_back(val);
                solve(s, soFar, i + 1);
                soFar.pop_back();                
            }
        }
    }
public:
    bool splitString(string s) {        
        vector<long> soFar;        
        solve(s, soFar, 0);
        
        return found;
    }
};