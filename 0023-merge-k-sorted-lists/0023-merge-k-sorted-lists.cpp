/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* DivideLL(vector<ListNode*>& lists,int l,int r){
        if(l>r)return NULL;
        if(l==r)return lists[l];

        int n=lists.size();

        int mid=l+(r-l)/2;

        ListNode*L1=DivideLL(lists,l,mid);
        ListNode*L2=DivideLL(lists,mid+1,r);

         return mergetwolists(L1, L2);


        





    }
    ListNode*mergetwolists(ListNode*l1, ListNode*l2){
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        

        if(l1->val<=l2->val){
            l1->next= mergetwolists(l1->next,l2);

            // l1=l1->next;
            return l1;


        }
        else{
            l2->next=mergetwolists(l2->next,l1);

           
            return l2;


        }
        // return NULL;

    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return NULL;
        int n=lists.size();

       return  DivideLL(lists,0,n-1);


        
    }
};