while 1:
    n=int(input())
    if(n==0):break;
    m={}
    s=[]
    for i in range(n):
        a=str(input())
        a="".join(sorted(a.split()))
        m[a]=1 if m.get(a,0)==0 else m[a]+1
        s.append(a)
    ans=0
    for i in range(n):
       ans=max(m[s[i]],ans)
    c=0
    for i in range(n):
        if(m[s[i]]==ans):
           c+=1
    print(c)

