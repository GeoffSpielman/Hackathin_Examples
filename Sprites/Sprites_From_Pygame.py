import pygame
import random
import time

MAX_SPEED = 2.5

#mostly taken from http://programarcadegames.com/python_examples/f.php?file=sprite_collect_blocks.py 

#this class is derived from the Sprite class (you get all that functionality)
class Block(pygame.sprite.Sprite):

	#constructor
	def __init__(self, colour, width, height, xVelocity, yVelocity):
		#calls the parent class constructor
		super().__init__()
		self.image = pygame.Surface([width, height]) # you could have used an image file instead of a rectangle
		self.image.fill(colour)
		#sets the 'bounding box' of the sprite
		self.rect = self.image.get_rect()
		self.xVel = xVelocity * MAX_SPEED
		self.yVel = yVelocity * MAX_SPEED

	def setColour(self, colour):
		self.image.fill(colour)

pygame.init()
#its useful to keep these as constants
SCREEN_WIDTH = 500
SCREEN_HEIGHT = 800
screen = pygame.display.set_mode([SCREEN_WIDTH, SCREEN_HEIGHT])
pygame.display.set_caption("Geoff's Game")

block_list = pygame.sprite.Group()
square_list = pygame.sprite.Group()
all_sprites_list = pygame.sprite.Group()

for i in range(15):

	#create block using constructor
	newBlock = Block([0,255,0], 30, 15, random.uniform(0,1), random.uniform(-1, 1))

	#locate it randomely in space
	newBlock.rect.x = random.randrange(SCREEN_WIDTH)
	newBlock.rect.y = random.randrange(SCREEN_HEIGHT)

	#add block to both lists
	block_list.add(newBlock)
	all_sprites_list.add(newBlock)

Upper_Square = Block([255, 0, 0], 30, 30, 0, 0)
Upper_Square.rect.x = SCREEN_WIDTH - 100
Upper_Square.rect.y = 200
all_sprites_list.add(Upper_Square)
square_list.add(Upper_Square)


Lower_Square = Block([0, 0, 255], 30, 30, 0, 0)
Lower_Square.rect.x = SCREEN_WIDTH - 100
Lower_Square.rect.y = 500
all_sprites_list.add(Lower_Square)
square_list.add(Lower_Square)

exitGame = False

#helps control frame rate
clock = pygame.time.Clock()

# main game loop
while not exitGame:
	for event in pygame.event.get(): 
		if (event.type == pygame.QUIT): 
			exitGame = True
		#clear the screen
	screen.fill((0, 0, 0))

	for block in block_list:
		block.rect.x += block.xVel
		block.rect.y += block.yVel
		#useful debugging code
		#print("new x: " + str(block.rect.x) + "\txVel: " + str(block.xVel) + "\t\t\tnew y: " + str(block.rect.y) + "\tyVel: " + str(block.yVel))

	#check if any blocks intersected with the squares (list 1, list 2, doKill in list 1, doKill in list 2)
	collidingEntities = pygame.sprite.groupcollide(block_list, square_list, False, False)

	for entity in collidingEntities:
		#check if colliding entity is a block
		if (block_list.has(entity)):
			#turn it yellow
			entity.setColour([255, 255, 0])

	#draw all the sprites
	all_sprites_list.draw(screen)
	pygame.display.update()

	#game doesn't run faster than 50 frames per seconds
	clock.tick(50)

pygame.quit()
quit()
