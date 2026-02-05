1class Solution {
2public:
3    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
4        ListNode* dummy = new ListNode();
5        ListNode* res = dummy;
6        int total = 0, carry = 0;
7
8        while (l1 || l2 || carry) {
9            total = carry;
10
11            if (l1) {
12                total += l1->val;
13                l1 = l1->next;
14            }
15            if (l2) {
16                total += l2->val;
17                l2 = l2->next;
18            }
19
20            int num = total % 10;
21            carry = total / 10;
22            dummy->next = new ListNode(num);
23            dummy = dummy->next;
24        }
25
26        ListNode* result = res->next;
27        delete res;
28        return result;         
29    }
30};