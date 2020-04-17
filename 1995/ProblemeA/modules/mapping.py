from modules.utils import getSign

class Location:
    def __init__(self, position, weight):
        self.__position = position
        self.__weight = weight
        self.__routes = []


    def getPosition(self):
        return self.__position


    def getWeight(self):
        return self.__weight


    def addRoute(self, destination_pos):
        self.__routes.append(destination_pos)

    def getRoutes(self):
        return self.__routes


class Map:
    def __init__(self):
        self.__locations = []


    def getLocations(self):
        return self.__locations

    def addLocation(self, location):
        self.__locations.append(location)

    def getFromPosition(self, position):
        for location in self.__locations:
            if location.getPosition() == position:
                return location

    def addRoute(self, origin_pos, destination_pos):
            sign_x = getSign(destination_pos[0], origin_pos[0])
            if sign_x != 0:
                for x in range(origin_pos[0], destination_pos[0], sign_x):
                    self.getFromPosition((x, origin_pos[1])).addRoute(self.getFromPosition((x+sign_x, origin_pos[1])))

            sign_y = getSign(destination_pos[1], origin_pos[1])
            if sign_y != 0:
                for y in range(origin_pos[1], destination_pos[1], sign_y):
                    self.getFromPosition((origin_pos[0], y)).addRoute(self.getFromPosition((origin_pos[0], y+sign_y)))
