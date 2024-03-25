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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start = NULL;
        ListNode* end = NULL;
        ListNode* head = list1;
        b+=1;
        b-=a;
        a-=1;
        while(a--){
            list1 = list1->next;
        }
        start = list1;
        while(b--){
            list1 = list1->next;
        }
        end = list1->next;
        start->next = list2;
        while(list2->next!=NULL){
            list2 = list2->next;
        }
        list2->next = end;
        return head;


    }
};