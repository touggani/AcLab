class Vertex:
    def __init__(self, position, weight):
        self.position = position
        self.weight = weight


class Map:
    def __init__(self):
        self.vertices = []
        self.routes = []
