class Solution {
public:

    bool isPossible(vector<int>& nums, vector<int>& changeIndices,int mid,int n){
        //Storing the Indices corresponding to their first occurrence in changeIndices
        vector<int> firstIndex(n,-1);
        for(int i=0;i<=mid;i++){
            if(firstIndex[changeIndices[i]-1]==-1)
                firstIndex[changeIndices[i]-1]=i;
        }

        //Storing the max possible ans in worst case i.e sum(nums)+n;
        long long totalOpr=0; //Total Operations
        for(long long val:nums) totalOpr+=val+1; //+1 as for nums=[2,1] we need 3+2 opr's
        // one opr to mark and nums[i] oprs to reduce it to 0 by subtraction

        long long extraOpr=0;//Extra denotes the times we didn't to anything but could have

        //Storing priority queue (min heap) as we should only consider 
        //using opr 3 (in ques) for the largest/worst elements 
        //Ex: nums=[100,90,1,2,0,3], here we should use 3rd operation i.e making 0 only if
        //    its possible(i.e we have some time s later where we can mark it as well) 
        //    and for larger elements like prefer using it for 100 and 90 instead of lower
        //    If not possible we can try using extraOpr we have and decrease those
        priority_queue<int, vector<int>, greater<int> >pq;
        //why min heap so we can remove the ones with lower priority first in case we have
        //no operations

        for(int s=mid;s>=0;s--){//Iterating from back
            int currIdx=changeIndices[s]-1;
            int val=nums[currIdx];
            // If I am not at first index or val==0 I can consider doing nothing 
            if(firstIndex[currIdx]!=s or val==0){
                extraOpr++;//As did nothing, so can come back to use this opr so 1 extraOpr
                continue;
            }

            pq.push(val); //pushed the current val if I am at first occurrence of curr idx
                          //in changeIndices and val is not 0 i.e can mark directly so 
                          //why consider putting it in queue
            
            if(extraOpr) extraOpr--; //If I have extraOpr reduce it, means considered 
                                     // using opr 3 i.e making it 0 as we 
                                     //have extra opr to mark it later on 
            else{
                extraOpr++;   //if can't mark it later on, try to reduce it by          
                              //decrement and mark it later on so revert extraOpr++
                pq.pop();     //And pop the minimum val from queue
            }
        }
        
        //Counting the sum of all the values in pq
        //i.e elements considered for opr3
        long long pqSum=0;
        while(!pq.empty()){
            long long it=pq.top();
            pq.pop();
            pqSum+=it+1;
        }
        //Now, total  = Worst case oprs/seconds required
        //     pq_sum = oprs/seconds used for making 0 and also marking
        //     req    = oprs/seconds required for decrementing to 0 and marking
        long long req=totalOpr-pqSum;
        //If required oprs are less than extraOprs we have so possible to solve
        return req<=extraOpr;
    }

    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int ans=-1,n=nums.size(),m=changeIndices.size();
        //Since we can find the answer in any portion of [1,m] so use binary search
        //Now, problem reduces to solving if possible in the chosen portion and 
        //if so what is the ans in that case
        int start=0,end=m-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(isPossible(nums,changeIndices,mid,n)){
                end=mid-1;
                ans=mid; // If possible ans is mid (at end of binary search,
                         //                         we will have minimum mid)
            }
            else{
                start=mid+1;
            }
        }
        return ans==-1?-1:ans+1;
    }
};