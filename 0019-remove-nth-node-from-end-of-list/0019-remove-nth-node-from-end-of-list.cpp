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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp= head;
        int count=0;
        if(head==nullptr)return nullptr;
        while(temp!=nullptr){
            count++;
            temp=temp->next;

        }
        
        
        if(count==n){
            ListNode*current=head;
            head=head->next;
            delete current;
            return head;

        }
         ListNode*curr1=head;

         int res=count-n;




        while(curr1!=nullptr){
            res--;
            if(res==0){
                ListNode*todel=curr1->next;
                curr1->next=curr1->next->next;
                delete todel;
                break;

            }
            curr1=curr1->next;
           
        }

        return head;



             




        

        
    }
};