class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // if (!head || !head->next) {  // Check if the list is empty or has only one node
        //     delete head;
        //     return nullptr;
        // }

        // int n = 0;
        // ListNode* temp = head;

        // // Count the total number of nodes
        // while (temp != nullptr) {
        //     n++;
        //     temp = temp->next;
        // }

        // int mid = n / 2;  // Calculate the middle index
        // temp = head;

        // // Traverse to the node just before the middle node
        // for (int i = 0; i < mid - 1; i++) {
        //     temp = temp->next;
        // }

        // // Delete the middle node
        // ListNode* nodeToDelete = temp->next;
        // temp->next = temp->next->next;
        // delete nodeToDelete;  // Free the memory

        // return head;

       if (!head || !head->next) {  // If the list is empty or has only one node, return nullptr
            delete head;
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;  // To keep track of the node before `slow`

        // Move `fast` by two steps and `slow` by one step until `fast` cannot move by two steps
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;  // Update `prev` to be the current `slow` before moving `slow`
            slow = slow->next;
            fast = fast->next->next;
        }

        // `slow` is now at the middle node; delete it
        prev->next = slow->next;
        delete slow;

        return head;
    }
};
