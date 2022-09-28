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
    int length(ListNode* tmp){
        int cnt=0;
        while(tmp != NULL){
            cnt++;
            tmp = tmp->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        if(n==1 && len==1){
            ListNode* tmp = NULL;
            return tmp;
        }
        
        int pos = len - n + 1;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        for(int i=1 ; i<pos && curr!= NULL ; i++){
            prev = curr;
            curr = curr->next;
        }
        if(prev == NULL){
            return curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        return head;
    }
};