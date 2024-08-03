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
        ListNode*findnewlast(ListNode*temp,int a ){
            int cnt=1;
            while(temp!=NULL){
                if(cnt==a)return temp;
                cnt++;
                temp=temp->next;
            }
            return temp;

        }











    ListNode* rotateRight(ListNode* head, int k) {
        int len=1;
        ListNode*tail=head;
        if(head==NULL || k==0 )return head;
        while(tail->next!=NULL){
            len+=1;
            tail=tail->next;

        }
        if(k%len==0)return head;
        k=k%len;

       tail->next=head;
       ListNode*newlastnode=findnewlast(head,len-k);

       head=newlastnode->next;
       newlastnode->next=NULL;



       return head;










        
    }
};