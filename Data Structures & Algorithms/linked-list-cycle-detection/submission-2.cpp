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
        ListNode* step1 = head;
        ListNode* step2 = head;
        
        while (step2 && step2->next) {
            step1 = step1->next;
            step2 = step2->next->next;
            if (step1 == step2) {
                return true;
            }
        }
        return false;
    }
};
