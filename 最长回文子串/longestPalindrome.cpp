class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        // Write your code here
        static int flag=0,legth=0;
        int c=0,max=0,i,j;
        int n=s.size();
        if(s.size()==0) return 0;
        for(i=0;i<n;i++)
        {
            for(j=0;i-j>=0&&(i+j)<n;j++)
            {
                if(s[i-j]!=s[i+j])
                    break;
                c=j*2+1;
                
            }
            if(c>max)
                {
                    max=c;
                    flag=i;
                    legth=j-1;
                }
            for(j=0;i-j>=0&&(i+j+1)<n;j++)
            {
                if(s[i-j]!=s[i+j+1])
                    break;
                c=j*2+2;
                
            }
            if(c>max)
            {
                    legth=j-1;
                    max=c;
                    flag=i;
            }
        }
        string res;
        for(int t=flag-legth;t<flag-legth+max;t++)
        {
            res.push_back(s[t]);
        }
        return res; 

    }
};