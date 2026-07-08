/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> original_to_copy;
        Node dummy(0);
        Node* head_copy = head;
        Node* new_list = &dummy;
        while (head_copy) {
            new_list->next = new Node(head_copy->val);
            new_list = new_list->next;

            original_to_copy[head_copy] = new_list;
            head_copy = head_copy->next;
        }
        new_list = dummy.next;
        while (head) {
            new_list->random = original_to_copy[head->random];
            new_list = new_list->next;
            head = head->next;
        }
        return dummy.next;
    }
};
