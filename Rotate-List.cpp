1class Solution{
2public:
3    ListNode* rotateRight(ListNode* head,int k){
4        if(!head||!head->next||k==0) return head; 
5
6        int len=1;
7        ListNode* tail=head;
8        while(tail->next){ tail=tail->next; len++; } 
9
10        k%=len;
11        if(k==0) return head; 
12
13        tail->next=head; // circular
14
15        int steps=len-k;
16        ListNode* newtail=head;
17        for(int i=1;i<steps;i++) newtail=newtail->next; 
18
19        ListNode* newhead=newtail->next; 
20        newtail->next=NULL; // break
21
22        return newhead;
23    }
24};