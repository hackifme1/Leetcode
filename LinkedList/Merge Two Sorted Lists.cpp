// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.


Example 1:

Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: l1 = [], l2 = []
Output: []

Example 3:

Input: l1 = [], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.

*/


Cpp code :

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) 
            return l2;
        
        if (l2 == NULL)
            return l1;
        
        ListNode* head = NULL;
        
        if (l1->val <= l2->val) 
        {
            head = l1;
            l1 = l1->next;
        } 
        else 
        {
            head = l2;
            l2 = l2->next;
        }
        
        ListNode* curr = head;
        
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val) 
            {
                curr->next = l1;
                l1 = l1->next;
            } 
            else 
            {
                curr->next = l2;
                l2 = l2->next;                
            }
            
            curr = curr->next;
        }
        
        if((l1 == NULL))
         curr->next = l2;
        else
         curr->next = l1;
        
        return head;
    }
};
