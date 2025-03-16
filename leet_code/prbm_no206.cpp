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
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current != nullptr) {
            next = current->next;   // 1
            current->next = prev;   // 2
            prev = current;         // 3
            current = next;         // 4
        }
        return prev;
    }
    ListNode* reverseList_yoshi(ListNode* head) {
        stack<int> s;

        ListNode* current = head;
        while (current != nullptr) {
            s.push(current->val);
            current = current->next;
        }

        current = head;
        while (current != nullptr) {
            current->val = s.top();
            s.pop();
            current = current->next;
        }
        return head;
    }
};