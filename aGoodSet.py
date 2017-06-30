for t in xrange(int(raw_input())):
    n = int(raw_input())

    ans = []

    exists = []

    for i in xrange(1, 501):
        if len(ans) >= n:
            break
        
        if i in exists:
            continue
        
        ans.append(i)

        for j in xrange(len(ans)):
            for k in xrange(j+1, len(ans)):
                exists.append(ans[j]+ans[k])
    
    print ' '.join(str(x) for x in ans)

