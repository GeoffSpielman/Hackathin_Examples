import pygame

pygame.init()

#You must pass in a tuple with a width and height
canvas = pygame.display.set_mode([800,600])
pygame.display.set_caption("Geoff's Game")

exitGame = False

while (not exitGame):

	for event in pygame.event.get():
		
		if event.type == pygame.QUIT:
			exitGame = True
		elif event.type == pygame.KEYDOWN:
			
			#clear previous rectangles
			canvas.fill((0,0,0))

			if event.key == pygame.K_LEFT:
				print("Left")
				pygame.draw.rect(canvas, (0, 255, 0), (200, 200, 50, 50))
			
			elif event.key == pygame.K_RIGHT:
				print("Right")
				pygame.draw.rect(canvas, (0, 255, 0), (300, 200, 50, 50))
			
			elif event.key == pygame.K_UP:
				print("Up")
				pygame.draw.rect(canvas, (0, 255, 0), (250, 150, 50, 50))
			
			elif event.key == pygame.K_DOWN:
				print("Down")
				pygame.draw.rect(canvas, (0, 255, 0), (250, 250, 50, 50))

			#draw the new shape
			pygame.display.update()

pygame.quit()
quit()