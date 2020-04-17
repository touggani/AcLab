import modules.fileParser as parser
import modules.utils as utils

def main():
    fileData = parser.FileData("files/sample_input.txt")

    map = utils.Map()
    for x in range(len(fileData.weights)):
        for y in range(len(fileData.weights[x])):
            map.addLocation(utils.Location((x+1, y+1), fileData.weights[x][y]))

    for route in fileData.routes:
        origin = (route[0], route[1])
        destination = (route[2], route[3])
        map.addRoute(origin, destination)


    for location in map.getLocations():
        print(location.getPosition(), "->", location.getRoutes())


    print(fileData.routes)
    print(fileData.queries)


if __name__ == '__main__':
    main()
