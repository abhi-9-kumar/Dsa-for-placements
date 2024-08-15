/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* intersection(ListNode *head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            return slow;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        // unordered_map<ListNode*,bool>vis;
        // ListNode* temp=head;
        // while(temp!=NULL){
        //     if(vis[temp]==true)
        //     return temp;

        //     vis[temp]=true;
        //     temp=temp->next;
        // }
        // return NULL;
        if(head==NULL){
            return NULL;
        }
        ListNode *intersectingpoint=intersection(head);
         if (intersectingpoint == NULL) {
            return NULL;
        }
        ListNode* slow=head;
        while(slow!=intersectingpoint){
            slow=slow->next;
            intersectingpoint=intersectingpoint->next;
        }
        return slow;
        
    }
};