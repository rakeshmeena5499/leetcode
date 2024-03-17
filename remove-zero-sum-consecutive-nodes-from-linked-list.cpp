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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // ListNode* front = new ListNode(0, head);
        // ListNode* curr = front;
        // while(curr!=NULL){
        //     int prefixSum = 0;
        //     ListNode* temp = curr->next;
        //     while(temp!=NULL){
        //         prefixSum += temp->val;
        //         if(prefixSum==0){
        //             curr->next = temp->next;
        //         }
        //         temp = temp->next;
        //     }
        //     curr = curr->next;
        // }
        // return front->next;

        ListNode* front = new ListNode(0, head);
        ListNode* curr = front;
        unordered_map<int, ListNode*> mp;
        int prefixSum = 0;
        mp[0] = front;
        while(curr!=NULL){
            prefixSum += curr->val;
            mp[prefixSum] = curr;
            curr = curr->next;
        }
        prefixSum = 0;
        curr = front;
        while(curr!=NULL){
            prefixSum += curr->val;
            curr->next = mp[prefixSum]->next;
            curr = curr->next;
        }
        return front->next;
    }
};