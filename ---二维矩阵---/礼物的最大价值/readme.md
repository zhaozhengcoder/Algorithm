## 礼物的最大值



题目见图片

思路
```
这是一个典型的动归的问题，

dp[i][j]=max(dp[i-1][j],dp[i][j-1])+gift_value[i][j]


```

《剑指offer》 第47题