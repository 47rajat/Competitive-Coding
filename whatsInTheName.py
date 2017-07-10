for t in range(int(input())):
    full = input()
    all = list(full.split(' '))

    if len(all) == 1:
        print(all[0].capitalize())
    else:
        ans = ''
        for i in range(len(all)-1):
            ans += (all[i].capitalize())[0] + '. '
        
        ans += all[-1].capitalize()

        print(ans)