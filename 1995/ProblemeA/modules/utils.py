def getSign(x, y):
    diff = x - y
    if diff > 0:
        return 1
    elif diff < 0:
        return -1
    else:
         return 0

class Vertex:
    def __init__(self, position, weight):
        self.position = position
        self.weight = weight


class Map:
    def __init__(self):
        self.vertices = []
        self.routes = []

    def addRoute(self, origin_pos, destination_pos):
        sign_x = getSign(destination_pos[0], origin_pos[0])
        if sign_x != 0:
            print(range(origin_pos[0], destination_pos[0]+sign_x, sign_x))
            for x in range(origin_pos[0], destination_pos[0]+sign_x, sign_x):
                self.routes.append((x, origin_pos[1]))

        sign_y = getSign(destination_pos[1], origin_pos[1])
        if sign_y != 0:
            print(range(origin_pos[1], destination_pos[1]+sign_y, sign_y))
            for y in range(origin_pos[1], destination_pos[1]+sign_y, sign_y):
                self.routes.append((origin_pos[0], y))
