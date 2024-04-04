from PIL import Image   

#loading the image

img=Image.open("C:\\Users\\DELL\\Downloads\\MARS-1\\strong dose\\python(playing with images)\\rohit.jpg")  #image object
width=img.width
height=img.height
total_pixels=width *height

threshold = (160, 160, 160)  #limit of RGB values(array)

typeA_count = 0  #counter var for type A and type B pixels
typeB_count = 0

#iterating through each coordinates(pixel)
for x in range(width):
   for y in range(height):
    R,G,B=img.getpixel((x,y))
    if R> threshold[0] and G > threshold[1] and B > threshold[2]:
            typeA_count +=1  #incrementing the count
    else:
            typeB_count += 1

percentage_typeA=(typeA_count/total_pixels)*100   #percentage calculation
percentage_typeB=(typeB_count/total_pixels)*100

print("Percentage of typeA pixels in the chosen image:", percentage_typeA)
print("Percentage of typeB pixels in the chosen image:", percentage_typeB)

grey_img=img.convert('L')  #converting image from RGB image to Grayscale image(pixels:0 to 255 scale representing brightness level)

new_img= Image.new('L', img.size)  #creating new image of same size of type grayscale for black-white output

brightness_value=60  #setting my brightness level

for x in range(width):
   for y in range(height):
    R,G,B=img.getpixel((x,y))

    brightness= (0.21 * R + 0.72 * G + 0.07 * B) / 3  #calculating brightness

    #changing pixels
    if brightness > brightness_value:
            new_img.putpixel((x, y), 0)  # Set pixel to black
    else:
            new_img.putpixel((x, y), 255)  # Set pixel to white

new_img.show()