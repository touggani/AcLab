from math import sqrt

def getSign(x, y):
    diff = x - y
    if diff > 0:
        return 1
    elif diff < 0:
        return -1
    else:
         return 0



def getDistance(start_location, end_location):
    start_pos = start_location.getPosition()
    end_pos = end_location.getPosition()
    return sqrt( (end_pos[0]-start_pos[0])**2 + (end_pos[1]-start_pos[1])**2)
