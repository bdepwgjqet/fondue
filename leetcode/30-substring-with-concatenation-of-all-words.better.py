#!/usr/bin/env python
# -*- coding: utf-8 -*-


class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        word_idx = {}
        target_word_cnt = []
        wl = len(words[0])
        cur_word_cnt = []
        for idx in range(len(words)):
            if words[idx] not in word_idx:
                word_idx[words[idx]] = len(target_word_cnt)
                target_word_cnt.append(1)
                cur_word_cnt.append(0)
            else:
                w_i = word_idx[words[idx]]
                target_word_cnt[w_i] = target_word_cnt[w_i] + 1
        s_find = []
        for idx in range(len(s)):
            cur_word = s[idx:idx+wl]
            if cur_word in word_idx:
                s_find.append(word_idx[cur_word])
            else:
                s_find.append(-1)
        subs = []
        for offset in range(0, wl):
            l = offset
            r = offset
            word_num = 0
            for idx in range(len(cur_word_cnt)):
                cur_word_cnt[idx] = 0
            while r < len(s):
                #print(l, r, word_num)
                if s_find[r] < 0:
                    next_l = r + wl
                    while l != next_l:
                        c_idx = s_find[l]
                        if c_idx >= 0:
                            cur_word_cnt[c_idx] = cur_word_cnt[c_idx] - 1
                            word_num = word_num - 1
                        l = l + wl
                    r = next_l
                    continue
                c_idx = s_find[r]
                #print(c_idx, cur_word_cnt[c_idx], target_word_cnt[c_idx])
                if cur_word_cnt[c_idx] == target_word_cnt[c_idx]:
                    while cur_word_cnt[c_idx] == target_word_cnt[c_idx]:
                        pre_idx = s_find[l]
                        cur_word_cnt[pre_idx] = cur_word_cnt[pre_idx] - 1
                        word_num = word_num - 1
                        l = l + wl
                    cur_word_cnt[c_idx] = cur_word_cnt[c_idx] + 1
                    word_num = word_num + 1
                else:
                    cur_word_cnt[c_idx] = cur_word_cnt[c_idx] + 1
                    word_num = word_num + 1
                if word_num == len(words):
                    subs.append(l)
                r = r + wl
        return subs


solution = Solution()
res = solution.findSubstring("barfoothefoobarman", ['foo', 'bar'])
#res = solution.findSubstring(
#    "barfoofoobarthefoobarman", ['foo', 'bar', 'the'])
#res = solution.findSubstring(
#    "wordgoodgoodgoodbestword", 
#    ["word","good","best","good"]
#)
#res = solution.findSubstring(
#    "aaaaaaaa", ["aa","aa","aa"])
for x in res:
    print(x)
