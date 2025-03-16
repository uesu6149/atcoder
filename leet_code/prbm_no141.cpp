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
	//‹T‚ÆƒEƒTƒM‚ÌƒAƒ‹ƒSƒŠƒYƒ€iFloyd‚ÌzŠÂŒŸo–@j
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
    
    bool hasCycle2(ListNode* head) {
        unordered_set<ListNode*> s;

        ListNode* current = head;
        while (current != NULL) {
            if (s.find(current) == s.end()) {
                s.insert(current);
            } else {
                // Find loop
                return true;
            }
            current = current->next;
        }
        return false;
    }
};