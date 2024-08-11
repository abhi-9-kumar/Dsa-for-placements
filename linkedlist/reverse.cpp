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
    ListNode* reverseList(ListNode* head) {
        // stack<int>st;
        // ListNode* temp = head;
        // while(temp!=nullptr)
        // {
        //     st.push(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp!=nullptr){
        //     temp->val=st.top();
        //     st.pop();
        //     temp=temp->next;
        // }
        // return head;

        //iterative approach
        /*
        if(head==nullptr||head->next==nullptr)
        return head;

        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* forward=nullptr;

        while(curr!=nullptr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
        */
        //recursive approach

        if(head==nullptr||head->next==nullptr)
        {
            return head;
        }
        ListNode *chotahead=reverseList(head->next);

        head->next->next=head;
        head->next= nullptr;

        return chotahead;
    }
};