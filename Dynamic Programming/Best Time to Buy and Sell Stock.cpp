// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5

Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0

Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104

*/


Cpp code :

// O(n) Approach

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int minm = INT_MAX, maxm = 0;
        
        for(int i=0;i<n;i++)
        {
            minm = min(minm,prices[i]);
            maxm = max(maxm,prices[i] - minm);
        }
        
        return maxm;
    }
};


// O(n*logn) Approach

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        priority_queue<int> pq;
        int n = prices.size();
        int maxm = 0;
        pq.push(prices[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            int temp = pq.top() - prices[i];
            if(temp>0)
                maxm = max(maxm, temp);
            
            pq.push(prices[i]);
        }
        
        return maxm;
    }
};
