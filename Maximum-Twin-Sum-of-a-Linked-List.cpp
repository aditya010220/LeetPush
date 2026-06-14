1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    int pairSum(ListNode* head) {
14        ListNode* slow = head;
15        ListNode* fast = head;
16        ListNode* prev = nullptr;
17
18        while (fast && fast->next) {
19            fast = fast->next->next;
20            swap(slow->next, prev);
21            swap(prev, slow);
22        }
23
24        int res = 0;
25        while (slow) {
26            res = max(res, prev->val + slow->val);
27            prev = prev->next;
28            slow = slow->next;
29        }
30
31        return res;
32    }
33};