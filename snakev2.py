import pygame
import random

# Initialize pygame
pygame.init()

# Screen dimensions
width, height = 800, 600
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption('Enhanced Snake Game')

# Colors
black = (0, 0, 0)
red = (255, 0, 0)
white = (255, 255, 255)
dark_gray = (30, 30, 30)
green = (0, 255, 0)

# Variables
clock = pygame.time.Clock()
snake_size = 20

# Font setup
font = pygame.font.SysFont('comicsansms', 35)

# Function to display text on the screen
def message(msg, color, x, y):
    text = font.render(msg, True, color)
    screen.blit(text, [x, y])

# Function to draw the snake
def draw_snake(snake_body):
    for segment in snake_body:
        pygame.draw.rect(screen, green, [segment[0], segment[1], snake_size, snake_size])  # Draw snake with rectangles

# Function to display the main menu
def game_menu():
    menu = True
    while menu:
        screen.fill(dark_gray)
        message("Select Difficulty:", white, width // 4, height // 4)
        message("1. Easy", green, width // 4, height // 3)
        message("2. Medium", white, width // 4, height // 2.5)
        message("3. Hard", red, width // 4, height // 2.2)
        pygame.display.update()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_1:
                    return 10  # Easy mode
                elif event.key == pygame.K_2:
                    return 20  # Medium mode
                elif event.key == pygame.K_3:
                    return 30  # Hard mode

# Main game loop function
def game_loop(speed):
    game_over = False
    game_close = False

    # Initial snake position and body
    x, y = width // 2, height // 2
    snake_body = [[x, y]]
    x_change, y_change = 0, 0
    length_of_snake = 1

    # Initial direction (no movement at the start)
    current_direction = None
    next_direction = None

    # Randomize apple position
    food_x = round(random.randrange(0, width - snake_size) / 20) * 20
    food_y = round(random.randrange(0, height - snake_size) / 20) * 20

    while not game_over:

        while game_close:
            screen.fill(black)
            message("Game Over! Press C to Play Again or Q to Quit", red, 100, height // 3)
            pygame.display.update()

            for event in pygame.event.get():
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_q:
                        game_over = True
                        game_close = False
                    if event.key == pygame.K_c:
                        speed = game_menu()  # Back to menu to select difficulty
                        game_loop(speed)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                game_over = True
            if event.type == pygame.KEYDOWN:
                # Update next direction only if it's not opposite to the current direction
                if event.key == pygame.K_LEFT and current_direction != 'RIGHT':
                    next_direction = 'LEFT'
                elif event.key == pygame.K_RIGHT and current_direction != 'LEFT':
                    next_direction = 'RIGHT'
                elif event.key == pygame.K_UP and current_direction != 'DOWN':
                    next_direction = 'UP'
                elif event.key == pygame.K_DOWN and current_direction != 'UP':
                    next_direction = 'DOWN'

        # Apply the next direction if available
        if next_direction:
            current_direction = next_direction

        # Update the snake's movement
        if current_direction == 'LEFT':
            x_change = -snake_size
            y_change = 0
        elif current_direction == 'RIGHT':
            x_change = snake_size
            y_change = 0
        elif current_direction == 'UP':
            y_change = -snake_size
            x_change = 0
        elif current_direction == 'DOWN':
            y_change = snake_size
            x_change = 0

        # Move the snake
        x += x_change
        y += y_change
        snake_body.append([x, y])

        # If the snake's length exceeds the required length, remove the oldest part
        if len(snake_body) > length_of_snake:
            del snake_body[0]

        # Check for self-collision
        for segment in snake_body[:-1]:
            if segment == [x, y]:
                game_close = True

        # Check for wall collision
        if x >= width or x < 0 or y >= height or y < 0:
            game_close = True

        # Draw everything
        screen.fill(dark_gray)
        pygame.draw.circle(screen, red, (food_x + snake_size // 2, food_y + snake_size // 2), snake_size // 2)  # Draw apple as a circle

        draw_snake(snake_body)
        message(f"Score: {length_of_snake - 1}", white, 0, 0)

        pygame.display.update()

        # Check if the snake eats the food
        if x == food_x and y == food_y:
            food_x = round(random.randrange(0, width - snake_size) / 20) * 20
            food_y = round(random.randrange(0, height - snake_size) / 20) * 20
            length_of_snake += 1

        clock.tick(speed)

    pygame.quit()
    quit()

# Main program flow
difficulty_speed = game_menu()  # Display menu and get selected difficulty
game_loop(difficulty_speed)  # Start the game with selected difficulty
