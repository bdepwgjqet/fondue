#!/usr/bin/python

class Solution:
    # @param A, a list of integers
    # @return an integer
    def trap(self, A):
        st = []
        ret = 0
        for i in range(len(A)):
            if len(st) == 0:
                st.append((A[i],0,i))
                continue
            (pn,pv,pi) = st.pop()
            if pn <= A[i]:
                sub = 0
                while pn <= A[i]:
                    sub += pv
                    if len(st) == 0:
                        break
                    (pn,pv,pi) = st.pop()
                ret += min(A[i],pn)*(i-pi-1)
                ret -= sub
                if pn <= A[i]:
                    ret += pv
                if pn > A[i]:
                    st.append((pn,pv,pi))
                st.append((A[i],min(A[i],pn)*(i-pi-1)+A[i],i))
            else:
                ret += A[i]*(i-pi-1)
                st.append((pn,pv,pi))
                st.append((A[i],A[i]*(i-pi),i))
        return ret

if __name__=='__main__':
    s = Solution()
    print s.trap([0,1,0,2,1,0,1,3,2,1,2,1])
