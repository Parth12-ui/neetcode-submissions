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
        if (head == nullptr) return nullptr;

        ListNode* ptr = head;
        int size = 0;
        while(ptr != nullptr){
            ptr = ptr->next;
            size++;
        }

        ListNode* prev = nullptr;
        ptr = head;
        if (n == size) return ptr->next;

        int counter = 0;
        while(counter != size - n){
            prev = ptr;
            ptr = ptr->next;
            counter++;
        }

        if (ptr == nullptr || ptr->next == nullptr){
            prev->next = nullptr;
            return head;
        }
        else{
            prev->next = ptr->next;
            return head;
        }

    }
};
