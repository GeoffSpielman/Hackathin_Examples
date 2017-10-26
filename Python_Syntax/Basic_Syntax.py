#!/usr/bin/python
import math

print("hello world")

myName = "Geoff"
print("Hello " + myName)

a = 3
b = 5
print(a + b)

a += 1  # a++ not supported
print(a)


testString = 'pineapple'

if testString == 'pear':
	print('it\'s a pear')

elif testString == 'pineapple':
	print('it\'s a pineapple')
	print('hooray!')

else:
	print('it\'s no fun')

print("\n=== String Properties ===")
print("String length: " + str(len(testString))) #+ is text concatenation operator which needs two strings.  len() returns an int
print("First char: " + testString[0])
print("Last char: " + testString[-1])
print("Second last char: " + testString[-2])
print("First 3 chars: " + testString[0:3])
print("Third to fifth characters " + testString[2:5])
print("Every second letter of the entire sting: " + testString[0::2])
print("Whole string backwards: " + testString[::-1])

# there
# is
# no 
# multi-line
# comment
# functionality :(

print("\n=== Functions ===")
def SquareIt(num):
	return num*num

def SquareWithDefault(num = 3):
	return num * num

potato = 4
print(str(SquareIt(potato)))
print(str(SquareWithDefault()))

result = SquareIt(SquareIt(SquareIt(potato)))
print("Big number: " + str(result))


print("\n=== Math Operators ===")
a = -5
print(abs(a))
a = 90
print(math.cos(a))
a = math.radians(a) # easier to read than (a * 180 / math.pi)
print(math.cos(a))
b = 67.365465
print("Using round: " + str(round(b)))
print("Using floor: " + str(math.floor(b)))
print("Using ceil: " + str(math.ceil(b)))




print("\n=== Lists/Arrays ===")
bob = [2,4,5,3]
print (bob)
sam = [2, 'walrus', 9.9234, True, math.pi]
print(sam)

#auto generate lists from ranges
incrementalList = range(5)
print("Ranges are not exactly lists: " + str(incrementalList))
print("But you can typecast them into one: " + str(list(incrementalList)))

skippingList = range(0, 10, 2)
print("Skipping list: " + str(list(skippingList)))

emptyList = []
emptyList.append(-2)
emptyList.append(-1)
print(emptyList)
emptyList = emptyList + list(incrementalList)
print("You can concantenate lists: " + str(emptyList))
print("Third item: " + str(emptyList[2])) # never forget indices start at 0

list2D = [[1, 2, 3], [4, 5, 6]]
print(list2D[0])
print(list2D[1])
print('looking for five: ' + str(list2D[1][1]))




print("\n=== Loops ===")
count = 1
while (count < 5):
	print (count)
	count += 1
else:
	print("I only run once at the end")

print("What is the point of the else if this runs next anyway?")


greatNumbers = [2, 7, 19, 32, 81, 42, 360, 12]
for i in range(0, len(greatNumbers)):
	print("Number " + str(i + 1) + " is " + str(greatNumbers[i]))

for letter in 'Python':
   print ('Current Letter :', letter)

fruits = ['banana', 'apple',  'mango']
for fruit in fruits: 
   print ('Current fruit :', fruit)

#break terminates the current loop and moves to the next line below it
for i in range (0, 10):
	if (i == 4):
		print("I DON'T LIKE FOUR!!!")
		break
	print(i)

print('\n')

#continue returns to the beggining of the loop for the next iteration 
# (skips the rest of the body of the loop)
for i in range(0,10):
	if (i == 4):
		print("Four is pretty mediocre")
		continue
	print (i)