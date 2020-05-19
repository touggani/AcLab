from modules.utils import getDistance

class Path:
    def __init__(self, start_location, end_location):
        self.origin = Node(start_location, end_location, start_location)
        self.end = Node(end_location, end_location, start_location)
        self.final_path = []
        self.visited_nodes = []
        self.nodes = []
        for route in self.origin.location.getRoutes():
            self.nodes.append(Node(route, self.end.location, self.origin.location))


    def visitNode(self, node):
        if not node in self.nodes:
            print("not possible to visit node: ", node)
        else:
            self.visited_nodes.append(node)
            for route in node.routes:
                self.nodes.append(Node(route, self.end.location, self.origin.location))


    def sortNodes(self):
        self.nodes.sort(key = lambda node: node.f_cost)


    def findPath(self):
        atEnd = False
        while not atEnd:
            self.sortNodes()
            print("visited nodes : ",self.visited_nodes)
            i = 0
            while True:
                node = self.nodes[i]
                if not node in self.visited_nodes:
                    break
                i+=1

            self.visitNode(node)
            print("visited : ",node)
            if node == self.end:
                atEnd = True




class Node:
    def __init__(self, location, end_location, start_location):
        self.location = location
        self.h_cost = getDistance(location, end_location)
        self.g_cost = getDistance(location, start_location)
        self.weight = self.location.getWeight()
        self.f_cost = self.h_cost + self.g_cost + self.weight

        for route in self.location.getRoutes():
            self.routes = Node(route, end_location, start_location)
