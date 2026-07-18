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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        ListNode* result = &dummy;
        ListNode* tail;
        while (head) {
            ListNode* seek = head;
            int count = 0;
            while (count < k && seek) {
                seek = seek->next;
                count++;
            }
            if (count < k) {
                result->next = head;
                break;
            }
            ListNode* prevNode = nullptr;
            ListNode* currNode = head;
            ListNode* nextNode = nullptr;
            tail = currNode;
            while (currNode != seek) {
                nextNode = currNode->next;
                currNode->next = prevNode;
                prevNode = currNode;
                currNode = nextNode;
            }
            result->next = prevNode;
            result = tail;
            head = seek;
        }
        return dummy.next;
    }
};
