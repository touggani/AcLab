from modules.utils import getDistance

class Path:
    def __init__(self, start_location, end_location):
        self.origin = start_location
        self.end = end_location
        self.final_path = []
        self.visitNodes = []
        self.nodes = []


    def visitNode(self, node):
        if not node in self.nodes:
            print("not possible to visit node: ", node)
        else:
            self.visitedNodes.append(node)
            for route in node.routes:
                self.nodes.append(Node(route, self.end, self.origin))

    def sortNodes(self):
        self.nodes.sort(key = lambda node: node.f_cost)


class Node:
    def __init__(self, location, end_location, start_location):
        self.location = location
        self.h_cost = getDistance(location, end_location)
        self.g_cost = getDistance(location, start_location)
        self.weight = self.location.getWeight()
        self.f_cost = self.h_cost + self.g_cost + self.weight
        self.routes = self.location.getRoutes()
