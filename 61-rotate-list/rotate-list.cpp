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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        int n = 0;
        ListNode* temp = head;

        while (temp) {
            n++;
            temp = temp->next;
        }

        k = k % n;

        if (k == 0)
            return head;

        temp = head;

        for (int i = 1; i < n - k; i++) {
            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;

        ListNode* tail = newHead;

        while (tail->next) {
            tail = tail->next;
        }

        tail->next = head;

        return newHead;
    }
};