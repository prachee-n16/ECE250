import random

def generate_connected_graph(num_nodes, num_edges):
    # Generate a random spanning tree
    edges = []
    visited = set()
    root = random.randint(1, num_nodes)
    visited.add(root)
    
    #we need to ensure that the weights are all unique so that the MST is unique
    weightset = list(set(range(1,num_edges+1)))
    random.shuffle(weightset)
    weightNum = 0
    
    while len(visited) < num_nodes:
        node = random.sample(visited, 1)[0]
        new_node = random.randint(1, num_nodes)
        if new_node not in visited:
            visited.add(new_node)
            weight = weightset[weightNum]#random.randint(1, 100)
            weightNum = weightNum+1
            edges.append((node, new_node, weight))
    # Add additional edges to reach the desired number of edges
    while len(edges) < num_edges:
        node1 = random.randint(1, num_nodes)
        node2 = random.randint(1, num_nodes)
        #if node1 != node2 and (node1, node2) not in edges and (node2, node1) not in edges:
        if node1 != node2 and (node1, node2) not in [e[0:2] for e in edges] and (node2, node1) not in [e[0:2] for e in edges]:
            #weight = random.randint(1, 100)
            weight = weightset[weightNum]
            weightNum = weightNum+1
            edges.append((node1, node2, weight))
    return edges

nVertices = 10
nEdges = 20
edges = generate_connected_graph(nVertices,nEdges);
print(nVertices)
for edge in edges:
        print(edge[0], edge[1], edge[2])
