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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<int>values;
        for(ListNode* list:lists){
            while(list){
                values.push_back(list->val);
                list=list->next;
            }
        }

        sort(values.begin(),values.end());

        ListNode* dummy= new ListNode(-1);
        ListNode* curr=dummy;

        for(auto it: values){
            curr->next=new ListNode(it);
            curr=curr->next;


        }
        return dummy->next;

    }
};