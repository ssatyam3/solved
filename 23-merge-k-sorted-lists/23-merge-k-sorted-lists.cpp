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
    class compare {
        public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare > pq;
        for(int i=0; i<lists.size() ; i++){
            if(lists[i]!=NULL)
                pq.push(lists[i]);
        }
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        while(pq.empty()==false){
            ListNode* tmp = pq.top();
            pq.pop();
            res->next = tmp;
            res = tmp;
            if(tmp->next != NULL){
                pq.push(tmp->next);
            } 
        }
        return head->next;
    }
};