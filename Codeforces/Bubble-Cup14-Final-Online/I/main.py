n, p = input().split()
n = int(n)
p = float(p)
 
gt = [1, 1, 2, 6]
 
def C(n, k):
    if(n<k):
        return 0
    ans = 1
    for i in range(n-k+1, n+1):
        ans*=i
    return ans//gt[k]
 
# k la so muon hoc
def check(k):
    t1 = (C(k, 1) * C(n - k, 2)) / C(n, 3)
    t2 = (C(k, 2) * C(n - k, 1)) / C(n, 3)
    t3 = C(k, 3) / C(n, 3)
 
    p1 = (1/3 + (1/3)*0.5) * t1
 
    return p1 + t2 + t3 >= p
 
l = 0
r = n-1
while l<=r:
    m = (l+r)//2
    if check(m):
        r = m - 1
    else:
        l = m + 1
print(l)