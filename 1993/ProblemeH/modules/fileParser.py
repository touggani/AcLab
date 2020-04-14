class FileData:
    def __init__(self, file_path):
        input_file = open(file_path, "r")
        content = [line.split() for line in input_file]
        input_file.close

        self.nb_image = content[0]
        self.array_1 = content[1]
        self.array_2 = content[2]
        self.array_3 = content[3]
        self.array_4 = content[4]
