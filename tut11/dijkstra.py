class Graph():
    def __init__(self, vertices, edges):
        self.vertices = vertices    # set of all vertices
        self.edges = edges          # dict of (from, to) : weight pairs

    def shortest_paths(self, start):
        inf = float('inf')

        # initialization
        dist = dict.fromkeys(self.vertices, inf)
        prev = dict.fromkeys(self.vertices, None)
        working = self.vertices.copy()

        dist[start] = 0

        # compute shortest distances
        while working:
            chosen_vertex = min(working, key=lambda v: dist[v])
            working.remove(chosen_vertex)

            incident_edges = set(filter(lambda e: e[0] == chosen_vertex, edges.keys()))
            neighbours = {neighbour for (chosen_vertex, neighbour) in incident_edges}

            for neighbour in neighbours.intersection(working):
                alternative_path_length = dist[chosen_vertex] + self.edges[(chosen_vertex, neighbour)]
                if alternative_path_length < dist[neighbour]:
                    dist[neighbour] = alternative_path_length
                    prev[neighbour] = chosen_vertex
        
        self.distances = dist

        # reconstruct paths
        self.shortest_paths = {}
        for v in self.vertices:
            path = []
            prev_vertex = v
            while prev_vertex is not None:
                path.append(prev_vertex)
                prev_vertex = prev[prev_vertex]
            path.reverse()
            self.shortest_paths[v] = path
        



if __name__ == "__main__":
    vertices = set(range(1,7)) # Knoten 1 bis 6
    graph_input = {(1, 3, 3), (1, 4, 10), (1, 5, 15), (2, 5, 4), (3, 2, 6), (3, 4, 5), (4, 6, 6), (5, 6, 2)}
    
    vertices = {vertex for (vertex, _, _) in graph_input}.union({vertex for (_, vertex, _) in graph_input})
    edges = { (start, to) : distance for (start, to, distance) in graph_input}

    g = Graph(vertices, edges)
    g.shortest_paths(1)

    print("Distances: \t", g.distances)
    print("Shortest Paths: \t", g.shortest_paths)

