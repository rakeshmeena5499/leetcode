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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unordered_map<ListNode*, int> mp;                // Store all nodes in map and then check
        // while(headA!=NULL){
        //     mp[headA]++;
        //     headA = headA->next;
        // }
        // while(headB!=NULL){
        //     if(mp[headB]>0){
        //         return headB;
        //     }
        //     mp[headB]++;
        //     headB = headB->next;
        // }
        // return NULL;
        
        // if(headA==NULL || headB==NULL)                   // Same as difference of lengths bit more elegant 
        //     return NULL;                                 // Essentially we're traversing the shorter list pointer
        // ListNode* ptr1 = headA;                          // by difference of len of lists times in longer list while comparing
        // ListNode* ptr2 = headB;
        // while(ptr1!=ptr2){
        //     ptr1 = (ptr1==NULL)?headB:ptr1->next;
        //     ptr2 = (ptr2==NULL)?headA:ptr2->next;
        // }
        // return ptr1;

        int len1 = 0, len2 = 0;                             // Calculate the difference of length of lists
        ListNode* dummyA = headA;                           // and offset the longer list by that then find common point    
        ListNode* dummyB = headB;
        while(dummyA!=NULL){
            dummyA = dummyA->next;
            len1++;
        }
        while(dummyB!=NULL){
            dummyB = dummyB->next;
            len2++;
        }
        if(len1 > len2){
            while(len1 - len2 != 0){
                headA = headA->next;
                len1--;
            }
        }
        else{
            while(len2 - len1 != 0){
                headB = headB->next;
                len2--;
            }
        }
        while(headA!=NULL && headB!=NULL){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};