# https://ac.nowcoder.com/acm/problem/275612
n=int(input())
cnt=0
a = map(int,input().split())
for i in a:
    cnt=(cnt+i)%3
if cnt==0:
    print("YES")
else:
    print("NO")