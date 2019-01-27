import numpy as np

#=================================================
# FUNCTIONS
#=================================================

#-------------------------------------------------
# read functions
#-------------------------------------------------
def read_hiji(file_name):
    import csv
    #-------------------------------------------------
    #read init file
    #-------------------------------------------------
    def read_init():
        file_name = "init_data"
        reader = csv.reader(open(file_name+".csv", "rb"), delimiter=",")
        print file_name + " is opened.\n"
        
        width, height = 0, 0
        particle = 0
        fileNumber = 0

        for i in reader:
            width, height = int(i[0]), int(i[1])
            particle = int(i[2])
            fileNumber = int(i[3])

        return (width, height, particle)


    #-------------------------------------------------
    #read csv
    #-------------------------------------------------
    (width, height, particle) = read_init()
    #find max and min
    _max, _min = 0, 0
    reader = csv.reader(open(file_name + ".csv", "rb"), delimiter=",")
    for i in reader:
        _max = max(_max, i[2])
        _min = min(_min, i[2])

    #make image
    reader = csv.reader(open(file_name + ".csv", "rb"), delimiter=",")
    print file_name + " is opened.\n"

    image = np.zeros((height, width))
    for i in reader:
        image[i[1], i[0]] = i[2]

    return image
    

def read_professor(file_name):
	import csv
	#open a csv file
	#file_name = str(raw_input("Please Enter File Name (you don't have to type '.csv'): "))
	reader = csv.reader(open(file_name + ".csv", "rb"), delimiter = ";")

	print file_name + " is opened.\n"

	#image = np.empty((width, height))
	#skip lines
	for i in xrange(9):
		reader.next()

	#Read data
	datas = []
	for line in reader:
		datas += [line]

	#Make image
	image = np.zeros((len(datas), len(datas[0])))
	i = 0
	for line in datas:
		j = 0
		for x in line:
			image[i, j] = float(x)
			j += 1
		i += 1

	return image



#-------------------------------------------------
# read csv
#-------------------------------------------------
def read_csv(file_name="", mode = "hiji"):
    if mode is "hiji":
        return read_hiji("./particle/" + "particle_dist" + "_0")
    else:
        return read_professor("./particle/output")



#-------------------------------------------------
# plot image
#-------------------------------------------------
def plot_image(image):
    from matplotlib import pyplot as plt

    plt.imshow(image, interpolation = "none")
    image_file_name = "result_particle_dist_0" + ".png"

    plt.savefig(image_file_name)
    plt.clf()
    print "saving " + image_file_name


def rotate45(image):
    import numpy as np
    from math import sin, cos, radians
    r = radians(45)

    R = np.array([
    [ cos(r), sin(r)],
    [-sin(r), cos(r)]])

    newImage = np.zeros((len(image), len(image[0])))
    for y in xrange(len(image)):
        for x in xrange(len(image[0])):
            point = np.dot(R, np.array([[x],[y]])) #+ np.array([[200], [200]])
            if (0 <= point[0] < len(image[0])) and (0 <= point[1] < len(image)):
                newImage[int(point[1])][int(point[0])] = image[y][x]
    return newImage
#=================================================
# Main
#=================================================
#print read_csv().T[0]
#plot_image(smoothing_filter(read_csv().T))

image = read_csv()

# def function(x):
#     import math
#     return -1 * x + 100 * math.sqrt(2) + 300 + 0.01
#     #return x - (400 + 2*math.sqrt(25))

# for x in xrange(len(image)):
#     temp = function(x)
#     if 0 <= temp < len(image):
#         image[temp][x] = 0.001
#         print str(x) + " " + str(temp)
    # else:
    #     print str(x) + " " + str(temp)

# image = rotate45(image)

plot_image(image)

#plot_image(read_csv().T)

