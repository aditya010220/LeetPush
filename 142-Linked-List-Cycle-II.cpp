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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast ->next->next;

            if(slow==fast){
                break;
            }
        }
        ListNode* p = head;
        if (fast == NULL || fast->next == NULL)
        return NULL;
        while(p!=slow){
            p = p->next;
            slow=slow->next;
            // if(p==slow){
            //     return p;
            // }
            //  yeha while yeh guarntee kar rha hain ki .. ki p ==slow hoga hi ..
        }
        return p;   
    }
};