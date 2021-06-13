// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎

/* Problem Statement :


*/

Cpp code :

// Linked lists only

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* l3 = new ListNode();
        l3->val = (temp1->val + temp2->val)%10;
        int carr = (temp1->val + temp2->val)/10;
        l3->next = NULL;
        temp1=temp1->next;
        temp2=temp2->next;
       
        ListNode* temp3 = l3;
        while(temp1 != NULL && temp2 != NULL)
        {
            int s = (temp1->val + temp2->val + carr)%10;
            carr = (temp1->val + temp2->val + carr)/10;
            
            ListNode* t = new ListNode();
            t->val = s;
            t->next = NULL;
            temp3 ->next = t;
            temp3 = temp3->next;
             temp1=temp1->next;
             temp2=temp2->next;
        }
        
        while(temp1!=NULL)
        {
             int s = (temp1->val + carr)%10;
            carr = (temp1->val + carr)/10;
            ListNode* t = new ListNode();
            t->val = s;
            t->next = NULL;
            temp3 ->next = t;
            temp3 = temp3->next;
            temp1=temp1->next;
        }
        
        while(temp2!=NULL)
        {
            int s = (temp2->val + carr)%10;
            carr = (temp2->val + carr)/10;
            ListNode* t = new ListNode();
            t->val = s;
            t->next = NULL;
            temp3->next = t;
            temp3 = temp3->next;
            temp2 = temp2->next;
        }
        
        if(carr>0)
        {
            ListNode* t = new ListNode();
            t->val = carr;
            t->next = NULL;
            temp3->next = t;
            temp3 = temp3->next;
        }
        
        return l3;
    }
};


// Using vectors (not recommended)

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;
        int i,j;
        
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        
        while(temp1)
        {
            v1.push_back(temp1->val);
            temp1=temp1->next;
        }
        
         while(temp2)
        {
            v2.push_back(temp2->val);
            temp2=temp2->next;
        }
           
        int minm=min(v1.size(),v2.size());
        int carr=0;
        for(i=0;i<minm;i++)
        {
            int s=v1[i]+v2[i]+carr;;
            int r=s%10;
             carr=s/10;
            v3.push_back(r);
        }
         if(v1.size()<v2.size())
         {
             for(j=i;j<v2.size();j++)
             {
                    int s=v2[j]+carr;
                    int r=s%10;
                     carr=s/10;
                    v3.push_back(r);
             }
         }
        if(v1.size()>v2.size())
        {
             for(j=i;j<v1.size();j++)
             {
                    int s=v1[j]+carr;
                    int r=s%10;
                    carr=s/10;
                    v3.push_back(r);
             }
        }
        if(carr!=0)
            v3.push_back(carr);
        
        ListNode* head=NULL;
        ListNode* nwnode=new ListNode();
        nwnode->val=v3[0];
        nwnode->next=NULL;
        head=nwnode;
        
        for(i=1;i<v3.size();i++)
        {
            ListNode* newnode=new ListNode();
            newnode->val=v3[i];
            newnode->next=NULL;
            nwnode->next=newnode;
            nwnode=newnode;
        }
        
        return head;
    }
};
