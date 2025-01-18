class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>dq;
        int i=0;
        int j=0;
        while(j<nums.size()){

            //calculation
            while(!dq.empty() && nums[dq.back()]<nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);

            if((j-i+1)<k){
                j++;//expanding the window
            }

            else if((j-i+1)==k){
                //ans=calculation
                res.push_back(nums[dq.front()]);
            

            //sliding the window and removing if any elemtis out of windo bound

            if(!dq.empty() && dq.front()==i){
                dq.pop_front();
            }
            i++;
            j++;}




        }

        return res;


        
    }
};