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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddhead= new ListNode(-1), *oddtail=oddhead;
        ListNode *evenhead=new ListNode(-1), *eventail=evenhead;

        ListNode* temp;
        ListNode* curr=head;
         int i=1;
        while(curr!=nullptr){
           
            temp=curr;
            curr=curr->next;
            temp->next=nullptr;

            if(i%2==0){
                eventail->next=temp;
                eventail=temp;
            }
            else{
                oddtail->next=temp;
                oddtail=temp;
            }
            i++;  
        }
        oddtail->next=evenhead->next;
        return oddhead->next;

    }
};