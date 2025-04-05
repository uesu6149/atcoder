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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* mid = getMiddle(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr; // 左側のリストを終端

        printf("Head:%d, Left:%d, mid:%d, Right:%d\n", head->val, left->val, mid->val, right->val);

        left = sortList(left);
        right = sortList(right);

        printf("Left:%d, Right:%d\n", left->val, right->val);

        return merge(left, right);
    }

private:
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        if (l1) {
            current->next = l1;
        }
        if (l2) {
            current->next = l2;
        }

        return dummyHead->next;
    }
};

 /*
class Solution {
public:
    // リンクリストの表示
    void printList(ListNode* head) {
        ListNode* current = head;
        while (current != nullptr) {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // 2つのソート済みリンクリストをマージする関数
    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left)
            return right;
        if (!right)
            return left;

        ListNode* result = nullptr;

        if (left->val <= right->val) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    // リンクリストの中央のノードを見つける関数
    // (スローポインタとファストポインタを使用)
    ListNode* getMiddle(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // リンクリストのマージソートを行う関数
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        // リストを中央で分割
        ListNode* middle = getMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = nullptr; // 左側のリストを終端

        // 各部分リストを再帰的にソート
        left = sortList(left);
        right = sortList(right);

        // ソートされた2つのリストをマージ
        return merge(left, right);
    }
};
*/