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
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        int flag = 1;

        while (fast != nullptr && slow != nullptr){
            if (slow == nullptr || fast == nullptr){
                return 0;
            }

            if (slow == fast && flag == 0) return 1;
            if (slow == fast && flag == 1) flag = 0;
            
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr) fast = fast->next;
        }

        return 0;
    }
};
