// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7

Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

Example 2:

Input: prices = [1,2,3,4,5]
Output: 4

Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Example 3:

Input: prices = [7,6,4,3,1]
Output: 0

Explanation: In this case, no transaction is done, i.e., max profit = 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104

*/


Cpp code :

// Both O(n) time complexity approaches

// Dynamic Approach 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int buy_date = 0;
        int sell_date = 1;
        int net_prft = 0;
        
        for(int i=1;i<n;i++)
        {
            if(prices[i] < prices[i-1])
            {
                net_prft += (prices[sell_date-1] - prices[buy_date]);
                buy_date = sell_date; 
                sell_date++;
            }
            else
            {
                sell_date++;
            }
        }
        
        net_prft +=(prices[sell_date-1] - prices[buy_date]); 
        return net_prft;
    }
};


// Greedy Approach (Tricky)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0;
            
        for(int i=1;i<n;i++)
        {
            res = res + max(prices[i]-prices[i-1],0);
        }
        
        return res;
    }
};
