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
    // int getLength(ListNode* head){
    //     int length=0;
    //     while(head!=nullptr){
    //         length++;
    //         head=head->next;
    //     }
    //     return length;
    // }
    // ListNode* middleNode(ListNode* head) {
    //     int len=getLength(head);
    //     int ans=len/2+1;
    //     ListNode* temp=head;
    //     for(int i=1;i<ans;i++){
    //         temp=temp->next;
    //     }
    //     return temp;

        
    // }

    //slow and fast pointers
     ListNode* middleNode(ListNode* head) {
    if(head==nullptr|| head->next==nullptr){
        return head;
    }
    if(head->next->next==nullptr){
        return head->next;
    }
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=nullptr){
        fast=fast->next;
        if(fast!=nullptr)
        fast=fast->next;
        
        slow=slow->next;
    }
    return slow;
    }
};