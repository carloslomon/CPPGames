# Agario Simple Implementation. In this Agario implementation we will not have any visualizations. I will have a specific repository for a future, elaborate implementation. 

### Game Description
In this version of the game, each character starts as a circle with a fixed size (radius) in a random location on a 2D grid. Each character is given a unique ID indicating when they joined the game. IDs start at 0 and increase over time.

On each turn, each of the characters remaining in the game can move either up, down, left, or right by one unit. For this version of the game those moves are hard-coded at compile time and constant for all characters (to make the grading scripts work and make it easier for you to debug). Characters that run into walls (as defined by the max and min xy values bounce off of the walls and stay put.

When characters run into each other, one of two things happens:
1. If the characters are different sizes, the smaller character is removed from the game and the larger character wins and grows in size by the size of the smaller character. For example, if a character of size 3 runs into a character of size 2, the character of size 2 is removed from the game and the character of size 3 becomes size 5.

2. If the characters are the same size, the character that joined the game first (has a smaller `id`) wins and grows in size as described above.

At the end of the game your code should print the final surviving characters, their ID, location, and size.
