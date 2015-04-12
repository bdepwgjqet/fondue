#!/usr/bin/python

class Solution:
    # @param word1, a string
    # @param word2, a string
    # @return an integer
    def minDistance(self, word1, word2):
        dp = []
        dp.append([])
        for i in range(len(word2)+1):
            dp[0].append(i)
        for i in range(len(word1)):
            dp.append([])
            dp[i+1].append(i+1)
            for j in range(len(word2)):
                dp[i+1].append(min(min(dp[i][j]+1 if word1[i] != word2[j] else dp[i][j],dp[i][j+1]+1),dp[i+1][j]+1))
        return dp[len(word1)][len(word2)]

        
if __name__=='__main__':
    s = Solution()
    print s.minDistance("good","gaedf")
