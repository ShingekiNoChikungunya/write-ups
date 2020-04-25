from pwn import *
from heapq import *
from math import inf

def Parse(response):
    '''
    output will be
    matrix[0] = numbers_of_paths, number_of_doors
    matrix[1] = list of times of all doors
    matrix[2..n] = relacionamento das portas
    matrix[source, dest]
    '''
    matrix=[]
    response=response.split(b"The answer is: ")[0].split(b'\n')
    for line in response:
        if line==b'' or line==b'     ':
            continue
        matrix.append(list(map(int,line.decode().split(' '))))
    return matrix

def int_to_bytes(x):
    s = '%d\n' % x
    return s.encode('ascii')

def assign(matrix):
    n_doors, n_paths = matrix[0][0], matrix[0][1]
    t = matrix[1]
    times = {}

    rel = {}
    for i in range(1, n_doors+1):
        rel[i] = []
        times[i] = t[i-1]

    for i in range(2,len(matrix)-1):
        path = matrix[i]

        '''
        bidirectional
        distance comes first
        '''
        rel[path[0]].append((path[2], path[1]))
        rel[path[1]].append((path[2], path[0]))

    ll = matrix[len(matrix)-1]
    s, d = ll[0], ll[1]

    return s, d, times, rel, n_doors

def Solve(matrix):
    source, target, times, graph, n_nodes = assign(matrix)


    #dijkstra
    pq = []
    heappush(pq, (0, source))

    dist = {}
    vis = {}

    for i in range(1,n_nodes+1):
        dist[i] = inf
        vis[i] = False
    dist[source] = 0

    while len(pq) != 0:
        curr = heappop(pq)[1]

        if vis[curr]:
            continue
        vis[curr] = True

        if curr == target:
            return dist[curr]

        for i in range( len(graph[curr]) ):
            path_dist = graph[curr][i][0]
            _next     = graph[curr][i][1]

            if (dist[curr] + path_dist) % times[_next] != 0:
                path_dist +=  abs( times[_next] - ((dist[curr]+path_dist)%times[_next]))

            #relax
            if dist[_next] > dist[curr] + path_dist:
                dist[_next] = dist[curr] + path_dist
                heappush(pq, (dist[_next], _next))



    return -1


conn = remote('142.93.113.55',31085)
conn.recvuntil(b'runaway: ')
conn.send(b'start\n')

for i in range(50):
    response= conn.recvuntil(b'The answer is: ').split(b':\n')[1]
    matrix=Parse(response)
    to_send=Solve(matrix)
    to_send = int_to_bytes(to_send)
    conn.send(to_send)
    print(f"Sent: {to_send}")
    '''DEBUG
    print(matrix)
    '''

response=conn.recvall()
print(f"Response: {response}")
