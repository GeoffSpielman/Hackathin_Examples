import pygame

pygame.init()

#You must pass in a tuple with a width and height
canvas = pygame.display.set_mode([800,600])
pygame.display.set_caption("Geoff's Game")

#must pass in the surface, an RGB colour value, position, width and height
pygame.draw.rect(canvas, (35, 235, 64), (200, 200, 30, 50))
pygame.display.update()

exitGame = False

while (not exitGame):
	for event in pygame.event.get():
		print(event)
		
		if event.type == pygame.QUIT:
			exitGame = True

pygame.quit()
quit()