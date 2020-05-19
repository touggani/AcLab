import modules.fileParser as parser
import modules.mapping as mapping
import modules.pathfinder as pathfinder

def main():
    fileData = parser.FileData("files/sample_input.txt")

    map = mapping.Map()
    for x in range(len(fileData.weights)):
        for y in range(len(fileData.weights[x])):
            map.addLocation(mapping.Location((x+1, y+1), fileData.weights[x][y]))

    for route in fileData.routes:
        origin = (route[0], route[1])
        destination = (route[2], route[3])
        map.addRoute(origin, destination)

    path = pathfinder.Path(map.getFromPosition((1,1)), map.getFromPosition((1,3)))
    path.findPath()


if __name__ == '__main__':
    main()
