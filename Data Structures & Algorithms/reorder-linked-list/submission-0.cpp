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
    void reorderList(ListNode* head) {
        ListNode* single = head;
        ListNode* twice = head;

        while (twice->next != nullptr && twice->next->next != nullptr){
            single = single->next;
            twice = twice->next->next;
        }

        ListNode* curptr = single->next;
        ListNode* prevptr = nullptr;
        single->next = nullptr;

        while(curptr != nullptr){
            ListNode* temp = curptr->next;
            curptr->next = prevptr;
            prevptr = curptr;

            curptr = temp;
        }

        ListNode* ptr = head;
        curptr = prevptr;
        
        while(ptr != nullptr && curptr != nullptr){
            ListNode* temp = ptr->next;
            ptr->next = curptr;

            ListNode* newtemp = curptr->next;
            curptr->next = temp;

            ptr = temp;
            curptr = newtemp;
        }
    }
};
