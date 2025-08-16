class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0;
        int cnt=0;
        int end=people.size()-1;

        while(i<=end){

            if(people[i]+people[end]<=limit){
                i++;
                end--;
            }
            else{
                end--;

            }
            cnt++;
        }
return cnt;
        
    }
};