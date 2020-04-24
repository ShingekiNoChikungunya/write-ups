# Dungeon Escape

Points: **472 Points**

nc 142.93.113.55 31085

## What we were prompted with:

+++     Fireshell CTF - DUNGEON ESCAPE     +++

 [+] After being caught committing crimes, you were locked up in a really strange 
     dungeon. You found out that the jailer is corrupt and after negotiating
     with him, he showed to you a map with all the paths and the necessary time
     to cross each one, and explained to you how the dungeon works. In some
     parts of the dungeon, there are some doors that only open periodically. The
     map looks something like this:

                4              +-+      1
        +----------------------+3+-------------+
       +-+                     +-+             |
       |C|                              2     +++     4
       +++                  +-----------------+7+--------------------+
        |           3      +-+                +-+                    |
        +------------------+4|        12                            +++
                           +-+--------------------------------------+E|
                                                                    +-+

 [+] All doors start at time zero together and if a door has time equals to 3,
     this door will open only at times 0, 3, 6, 9, ... So if you reach a door
     before it is open, you will need to wait until the door is open.

 [+] So, with a map you organized the infos like the following: first it will be 
     the number of doors and the number of paths. Second it will be a list with
     the time of all doors. After that each line will contains a path with the
     time needed to walk this path. For the last it will be the position of your
     cell (C) and the postion where it is the exit (E).
 
 [+] The jailer said that if you find out the minimum time from your cell to the 
     exit, he will set you free. In the example, the minimum time is 11.

### Input for the drawing:
```
5 6
1 8 3 7 1
1 2 3
1 3 4
2 4 2
3 4 1
2 5 12
4 5 4
1 5
```

### Result:
As stated, the result should be 11.

## Solution

As we should answer the minimun time to get to the exit [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm) sounds like a good idea. I splitted the chall in 3 parts, parse the input, implement the algorithm, finally think of and implement the needed modification(the doors opening from time to time).

### Step 1
To parse the response from the server we used pwntools, here's the code:

```python
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
'''
.
.
.
in main():
.
.
.
'''
response= conn.recvuntil(b'The answer is: ').split(b':\n')[1]
matrix=Parse(response)
```


### Step 2
To implement Dijkstra I based my code in this [C++ snippet](https://github.com/MaratonaAtUFSCar/Codigos/blob/master/graph/sssp/dijkstra/dijkstra_pq_adj_list.cpp). I created an assign function too, to help me putting the correct values from the parse in the correct variables in my dijkstra code.

```python
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

            #relax
            if dist[_next] > dist[curr] + path_dist:
                dist[_next] = dist[curr] + path_dist
                heappush(pq, (dist[_next], _next))


    #not found a path from source to dest
    return -1
```

### Step 3

The final step. Now we need to stop and do some reasoning.

If the door has time 3. The door will get open at 3, 6, 9, 12, .... So to get past a door, my time _T_ needs to be divisible by the door time _dT_. So *T % dT == 0*. So if I get to a door that has time 10, in time 7, 17, 27, ..., I need to wait 3 units of time. So how do I get to the number 3, from these _T_ and _dT_. I did like the following:

```python
'''
17 % 10 == 7
'''
T % dT
'''
then
this result -dT
'''
( T % dT ) - dT
'''
7 - 10 = -3
then we get the modulus
'''
abs( ( T % dT ) -dT )
'''
so instead of just adding up
the distance to the door, we
add this fraction of time too
if the arrivalTime % doorTime
differs from 0
my final code was this:
'''
if (dist[curr] + path_dist) % times[_next] != 0:
                path_dist +=  abs( times[_next] - ((dist[curr]+path_dist)%times[_next]))

```

Briefly, that was it. I did solve all instances and missed the flag a couple of times due to the code structure :P

Ended up in discovering that the chall threw 50 problems at us, that's why 50 is hardcoded.

I don't know how to explain but PPC challs gives us such a great satisfaction at solving them. Thanks to the author.

Flag
```
F#{KREEKX2DJ5JFERKDKRPUMTCBI5PUSU27KREEKX2CIFJUKMZS}
```
