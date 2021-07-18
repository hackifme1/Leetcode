// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the 
number of words in text you can fully type using this keyboard.


Example 1:

Input: text = "hello world", brokenLetters = "ad"
Output: 1

Explanation: We cannot type "world" because the 'd' key is broken.

Example 2:

Input: text = "leet code", brokenLetters = "lt"
Output: 1

Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.

Example 3:

Input: text = "leet code", brokenLetters = "e"
Output: 0

Explanation: We cannot type either word because the 'e' key is broken.
 

Constraints:

1 <= text.length <= 104
0 <= brokenLetters.length <= 26
text consists of words separated by a single space without any leading or trailing spaces.
Each word only consists of lowercase English letters.
brokenLetters consists of distinct lowercase English letters.

*/


Cpp code :

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.size();
        int m = brokenLetters.size();
        
        vector<string> v;
        string str = "";
        
        for(int i=0;i<n;i++)
        {
            if(text[i] == ' ')
            {
                v.push_back(str);
                str = "";
            }
            else
                str += text[i];
        }
        
        if(str.size()>0)
        v.push_back(str);
                
        int freq[30] = {0};
        int cnt = 0;
        
        for(int i=0;i<m;i++)
            freq[brokenLetters[i] - 'a']++;
        
        for(int i=0;i<v.size();i++)
        {
            int flag = 0;
            for(int j=0;j<v[i].size();j++)
            {
                if(freq[v[i][j] - 'a'] > 0)
                {
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0)
                cnt++;
        }
        
        return cnt;
    }
};
