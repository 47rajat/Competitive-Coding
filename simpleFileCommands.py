from heapq import heappush, heappop
def create(files, name):
    index = 0
    if files.has_key(name):
            if files[name][1]:
                index = heappop(files[name][1])
            else:
                index = files[name][0] + 1
                files[name][0] += 1
    else:
        files[name] = [0, []]
    
    return index

def delete(files, command):
    if command[1].find('(') >= 0:
         name,  index = command[1].split('(')
         index = int(index.split(')')[0])
         heappush(files[name][1], index)
    else:
        heappush(files[command[1]][1], 0)
    

q = int(raw_input())

files = {}

for i in xrange(q):
    command = raw_input().split()

    if command[0] == 'crt':
        index = create(files, command[1])
        if index > 0:
            print '+ {}({})'.format(command[1], index)
        else:
            print '+ {}'.format(command[1])
    
    if command[0] == 'del':
        delete(files, command)
        print '- {}'.format(command[1])
    
    if command[0] == 'rnm':
        delete(files, command)
        index  = create(files, command[-1])

        if index > 0:
            print 'r {} -> {}({})'.format(command[1], command[-1], index)
        else:
            print 'r {} -> {}'.format(command[1], command[-1])


