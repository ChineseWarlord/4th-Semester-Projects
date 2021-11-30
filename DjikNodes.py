from queue import PriorityQueue
import time
from numpy import random
import matplotlib.pyplot as plt

class Graph:

    def __init__(self, num_of_vertices):
        self.v = num_of_vertices
        self.edges = [[-1 for i in range(num_of_vertices)] for j in range(num_of_vertices)]
        self.visited = []
        
    def add_edge(self, u, v, weight):
        self.edges[u][v] = weight
        self.edges[v][u] = weight
        
    def dijkstra(self, start_vertex):
        D = {v:float('inf') for v in range(self.v)}
        D[start_vertex] = 0

        pq = PriorityQueue()
        pq.put((0, start_vertex))

        while not pq.empty():
            (dist, current_vertex) = pq.get()
            self.visited.append(current_vertex)

            for neighbor in range(self.v):
                if self.edges[current_vertex][neighbor] != -1:
                    distance = self.edges[current_vertex][neighbor]
                    if neighbor not in self.visited:
                        old_cost = D[neighbor]
                        new_cost = D[current_vertex] + distance
                        if new_cost < old_cost:
                            pq.put((new_cost, neighbor))
                            D[neighbor] = new_cost
            
        return D


g1 = Graph(6)
g1.add_edge(0,1,4)
g1.add_edge(0,2,2)
g1.add_edge(0,3,6)
g1.add_edge(1,2,1)
g1.add_edge(1,4,7)
g1.add_edge(2,4,6)
g1.add_edge(2,5,3)
g1.add_edge(3,5,3)
g1.add_edge(4,5,2)
g1.add_edge(5,3,3)

TimeStart1 = time.time()
D = g1.dijkstra(0)
TimeStop1 = (time.time() - TimeStart1)
print("Running time: ", TimeStop1)
for vertex in range(len(D)):
    print("Distance from vertex 0 to vertex", vertex, "is", D[vertex])


g2 = Graph(12)
g2.add_edge(0,1,5)
g2.add_edge(0,5,7)
g2.add_edge(0,3,8)
g2.add_edge(1,10,2)
g2.add_edge(1,2,3)
g2.add_edge(3,4,4)
g2.add_edge(3,11,5)
g2.add_edge(4,10,8)
g2.add_edge(4,1,3)
g2.add_edge(4,8,6)
g2.add_edge(5,8,6)
g2.add_edge(6,10,2)
g2.add_edge(6,7,1)
g2.add_edge(9,11,3)

TimeStart2 = time.time()
D = g2.dijkstra(0)
TimeStop2 = (time.time() - TimeStart2)
print("Running time: ", TimeStop2)
for vertex in range(len(D)):
    print("Distance from vertex 0 to vertex", vertex, "is", D[vertex])


g3 = Graph(16)
g3.add_edge(0,2,1)
g3.add_edge(0,3,3)
g3.add_edge(3,4,7)
g3.add_edge(2,1,3)
g3.add_edge(2,7,5)
g3.add_edge(2,5,6)
g3.add_edge(1,8,4)
g3.add_edge(7,8,2)
g3.add_edge(5,6,2)
g3.add_edge(6,7,1)
g3.add_edge(5,10,4)
g3.add_edge(6,10,2)
g3.add_edge(9,10,4)
g3.add_edge(10,11,1)
g3.add_edge(11,12,3)
g3.add_edge(12,15,5)
g3.add_edge(15,14,1)
g3.add_edge(14,13,3)
g3.add_edge(13,8,2)
g3.add_edge(7,14,8)

TimeStart3 = time.time()
D = g3.dijkstra(0)
TimeStop3 = (time.time() - TimeStart3)
print("Running time: ", TimeStop3)
for vertex in range(len(D)):
    print("Distance from vertex 0 to vertex", vertex, "is", D[vertex])


g4 = Graph(24)
g4.add_edge(0,2,2)
g4.add_edge(0,18,4)
g4.add_edge(0,23,6)
g4.add_edge(0,8,8)
g4.add_edge(0,3,9)
g4.add_edge(1,4,1)
g4.add_edge(3,4,3)
g4.add_edge(3,5,5)
g4.add_edge(4,9,7)
g4.add_edge(6,15,9)
g4.add_edge(7,22,3)
g4.add_edge(8,11,6)
g4.add_edge(8,13,9)
g4.add_edge(9,10,4)
g4.add_edge(10,17,8)
g4.add_edge(12,19,7)
g4.add_edge(13,14,9)
g4.add_edge(14,15,5)
g4.add_edge(15,6,3)
g4.add_edge(16,14,2)
g4.add_edge(19,21,1)
g4.add_edge(20,21,7)
g4.add_edge(21,22,4)
g4.add_edge(22,23,8)

TimeStart4 = time.time()
D = g4.dijkstra(0)
TimeStop4 = (time.time() - TimeStart4)
print("Running time: ", TimeStop4)
for vertex in range(len(D)):
    print("Distance from vertex 0 to vertex", vertex, "is", D[vertex])


g5 = Graph(30)
g5.add_edge(0,1,4)
g5.add_edge(0,2,3)
g5.add_edge(0,3,4)
g5.add_edge(3,6,3)
g5.add_edge(6,7,2)
g5.add_edge(5,7,5)
g5.add_edge(3,5,2)
g5.add_edge(2,4,6)
g5.add_edge(4,5,3)
g5.add_edge(4,12,8)
g5.add_edge(4,10,1)
g5.add_edge(5,8,4)
g5.add_edge(8,9,2)
g5.add_edge(8,16,4)
g5.add_edge(16,17,2)
g5.add_edge(15,16,2)
g5.add_edge(14,15,1)
g5.add_edge(9,10,5)
g5.add_edge(9,14,2)
g5.add_edge(15,18,3)
g5.add_edge(17,24,11)
g5.add_edge(14,20,3)
g5.add_edge(19,20,4)
g5.add_edge(18,19,3)
g5.add_edge(12,11,2)
g5.add_edge(10,11,2)
g5.add_edge(12,13,2)
g5.add_edge(11,13,5)
g5.add_edge(10,20,6)
g5.add_edge(20,22,2)
g5.add_edge(19,22,5)
g5.add_edge(21,22,1)
g5.add_edge(22,23,3)
g5.add_edge(23,24,3)
g5.add_edge(24,29,5)
g5.add_edge(23,29,9)
g5.add_edge(21,25,2)
g5.add_edge(25,26,1)
g5.add_edge(25,28,6)
g5.add_edge(26,27,3)
g5.add_edge(27,28,1)
g5.add_edge(23,27,7)
g5.add_edge(29,28,3)

TimeStart5 = time.time()
D = g5.dijkstra(0)
TimeStop5 = (time.time() - TimeStart5)
print("Running time: ", TimeStop5)
for vertex in range(len(D)):
    print("Distance from vertex 0 to vertex", vertex, "is", D[vertex])


#for vertex in range(len(D)):
#    print("Distance from vertex A to vertex", Vertices5[vertex], "is", D[vertex])

TimeArr = []
TimeArr.append(TimeStop1)
TimeArr.append(TimeStop2)
TimeArr.append(TimeStop3)
TimeArr.append(TimeStop4)
TimeArr.append(TimeStop5)
print("Timear is: ", TimeArr)

# Plot running time
fig, axs = plt.subplots(2, 2)
xLabel = ['6', '12', '18', '24', '30']
x2Label = [6,12,18,24,30]

for ax in axs.flat:
    ax.set(xlabel='No. of nodes', ylabel='Running Time (s)')

# Linear
axs[0, 0].set_title('Running time Djikstra\n Linear')
axs[0, 0].set_yscale("linear")
axs[0, 0].set_xscale("linear")
axs[0, 0].plot(xLabel, TimeArr, '-bo')

# Semilog y
axs[0, 1].set_title('Running time Djikstra \n Semilog y')
axs[0, 1].set_yscale("log")
axs[0, 1].set_xscale("linear")
axs[0, 1].plot(xLabel, TimeArr, '-ro')

# Semilog x
axs[1, 0].set_title('Running time Djikstra \n Semilog x')
axs[1, 0].set_yscale("linear")
axs[1, 0].set_xscale("log")
axs[1, 0].plot(x2Label, TimeArr, '-go')

# Double log
axs[1, 1].set_title('Running time Djikstra \n Double log')
axs[1, 1].set_yscale("log")
axs[1, 1].set_xscale("log")
axs[1, 1].plot(x2Label, TimeArr, '-yo')

fig.tight_layout()
plt.show()