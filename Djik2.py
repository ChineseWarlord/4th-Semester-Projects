from queue import PriorityQueue
import time

class Graph:

    def __init__(self, num_of_vertices):
        self.v = num_of_vertices
        self.edges = [[-1 for i in range(num_of_vertices)] for j in range(num_of_vertices)]
        self.visited = []
        
    def add_edge(self, u, v, weight):
        self.edges[u][v] = weight
        self.edges[v][u] = weight
        
    def dijkstra(self, start_vertex):
        TimeStart = time.time()
        TimeArr = []
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
            TimeArr.append((time.time() - TimeStart))
            
        print("Weight from start vertex to each vertice = Vertex 'x' : Weight ", D)
        print("The running time for each visit:", TimeArr)
            
        return D


g = Graph(6)
A = 0
B = 1
C = 2
D = 3
E = 4
F = 5
#g.add_edge(A,A,0)
g.add_edge(A,B,4)
g.add_edge(A,C,2)
g.add_edge(A,D,6)
#g.add_edge(B,B,0)
g.add_edge(B,A,4)
g.add_edge(B,C,1)
g.add_edge(B,E,7)
#g.add_edge(C,C,0)
g.add_edge(C,A,2)
g.add_edge(C,B,1)
g.add_edge(C,E,6)
g.add_edge(C,F,3)
#g.add_edge(D,D,0)
g.add_edge(D,A,6)
g.add_edge(D,F,3)
#g.add_edge(E,E,0)
g.add_edge(E,B,7)
g.add_edge(E,C,6)
g.add_edge(E,F,2)
#g.add_edge(F,F,0)
g.add_edge(F,C,3)
g.add_edge(F,E,2)
g.add_edge(F,D,3)

D = g.dijkstra(0)

Vertices = ["A", "B", "C", "D", "E", "F",]
#Vertices = [1,2,3,4,5,6]
for vertex in range(len(D)):
    print("Distance from vertex A to vertex", Vertices[vertex], "is", D[vertex])


