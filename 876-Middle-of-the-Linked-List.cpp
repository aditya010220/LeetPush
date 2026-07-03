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
vector<int>toArray(ListNode* head){
    vector<int>arr;
    while(head){
        arr.push_back(head->val);
        head=head->next;
    }
 return arr;
}

ListNode* toLinkedList(vector<int>&arr){
    ListNode dummy(0);

    ListNode*tail = &dummy;

    for(int x:arr){
        tail->next = new ListNode(x);
        tail= tail->next;
    }
    return dummy.next;
}
    ListNode* middleNode(ListNode* head) {
        vector<int>ans = toArray(head);
        int mid = ans.size()/2;
        vector<int>temp;
        for(int i = mid;i<ans.size();i++){
            temp.push_back(ans[i]);
        }
        return toLinkedList(temp);
    }
};