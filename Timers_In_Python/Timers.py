import time
import threading

#simple delay
print("I'll be back in 3 seconds")
time.sleep(3)
print("I'm back\n")


def timerEndFunction():
	print("\nCookies are ready!")
	print(str(time.time()))

print("I'm going to schedule a timer")
t = threading.Timer(8, timerEndFunction)
t.start()

print("Oh look I can keep running code")
print("This is considered 'non-blocking'")
print("I'm starting to get hungry...")
print("What time is it? Good question. It's " + str(time.time()))
