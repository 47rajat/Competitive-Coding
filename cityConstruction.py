'''
The solution for this problem involves finding the Strongly Connected Components(SCC)
of a directed graph using Kosaraju's Algo (Find it on GeeksForGeeks). Then reduce the
graph to these strongly connected components and use the reduced graph to find if a
path exisits between two vertex.

This solution despite being right  will not work for large test cases on account of python
 recursion limit (fuck you python) and will have to use C++ for getting AC.
'''


n, m = map(int , raw_input().split())

#original graph
graph = [[] for i in xrange(n)]
#transpose of original graph, used for finding SCC.
graph_rev = [[] for i in xrange(n)]

for i in xrange(m):
    u, v = map(int, raw_input().split())
    graph[u-1].append(v-1)
    graph_rev[v-1].append(u-1)

#storing all the query first and then using completed information to answer the
all_query = []

for i in xrange(int(raw_input())):
    query = map(int, raw_input().split())
    if query[0] == 1:
        if query[-1] == 0:
            graph.append([])
            graph[query[1]-1].append(n)
            
            graph_rev.append([query[1]-1])
            n += 1
        else:
            graph.append([query[1]-1])

            graph_rev.append([])
            graph_rev[query[1]-1].append(n)
            n += 1

    else:
        all_query.append(query)

#Performing DFS and other operations from here.

#required for some test cases
import sys
sys.setrecursionlimit(10000)


visited = [0 for i in xrange(n)]
stack = []

def dfs(i):
    if visited[i] == 0:
        # print 'dfs for vertext {}'.format(i)
        visited[i] = 1
        for v in graph[i]:
            if visited[v] == 0:
                dfs(v)
        stack.append(i)

for i in xrange(n):
    dfs(i)
  
# reversing the stack
stack.reverse()
# list representing the SCC component a vertex belongs to.
scc = [-1 for i in xrange(n)]

visited = [0 for i in xrange(n)]

def reduce_scc(i, s):
    if visited[i] == 0:
        # print 'reduce_scc for vertex {}'.format(i)
        scc[i] = s
        visited[i] = 1

        for v in graph_rev[i]:
            if visited[v] == 0:
                reduce_scc(v, s)

s = 0
for i in stack:
    if visited[i] == 0:
        reduce_scc(i, s)
        s += 1

#This will be a reduced graph where each SCC  will represent a vertex and edges will
# be an edge from a vertex of one SCC to a vertex of a different SCC from the original graph.
reduced_graph = [[] for i in xrange(s)]

for i in xrange(len(graph)):
    for j in graph[i]:
        if not scc[i] == scc[j]:
            reduced_graph[scc[i]].append(scc[j])

stack = []
#this 2D array will reperesent presence of path from i to j using their component number
path = [[0 for j in xrange(s)] for i in xrange(s)]
visited = [0 for i in xrange(len(reduced_graph))]

# necessary for performing dfs below.
graph = reduced_graph

for i in xrange(len(reduced_graph)):
    dfs(i)

for s in stack:
    path[s][s] = 1

    for v in graph[s]:
        path[s] = [a|b for a, b in zip(path[s], path[v])]

for q in all_query:
    if path[scc[q[1]-1]][scc[q[-1]-1]] == 1:
        print 'Yes'
    else:
        print 'No'

