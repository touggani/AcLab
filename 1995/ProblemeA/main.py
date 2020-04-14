import modules.fileParser as parser
import modules.utils as utils

def main():
    fileData = parser.FileData("files/sample_input.txt")

    map = utils.Map()
    for x in range(len(fileData.weights)):
        for y in range(len(fileData.weights[x])):
            map.vertices.append(utils.Vertex((x, y), fileData.weights[x][y]))

    for route in fileData.routes:
        print(route)
        origin = (route[0], route[1])
        destination = (route[2], route[3])
        map.addRoute(origin, destination)
        print(map.routes)


if __name__ == '__main__':
    main()
