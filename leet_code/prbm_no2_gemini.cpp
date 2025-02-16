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
    // 2�̘A�����X�g�̘a���v�Z����֐�
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;

        // l1, l2 �̂����ꂩ�� null �ɂȂ�܂ŁA�������� carry ���c��܂Ń��[�v
        while (l1 || l2 || carry) {
            int sum = carry; // carry �𑫂�����
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;                    // �J��オ����v�Z
            curr->next = new ListNode(sum % 10); // �V�����m�[�h���쐬
            curr = curr->next;
        }

        return dummyHead->next;
    }
};