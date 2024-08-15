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
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
        //editorial
        /*
         Instead of shifting the data of all subsequent nodes, we only need to overwrite the data of the node to be deleted with that of its immediate successor. Subsequently, we update the next pointer of the node to be deleted to point to the successor's next node. This effectively removes the successor node, achieving the desired result with minimal operations
        */
    }
};