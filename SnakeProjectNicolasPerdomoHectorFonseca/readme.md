#SnakeProjectNicolasPerdomoHectorFonseca
##ISI, L'institut Supérieur d'Informatique 

Table of contents:
1. About the project.
2. Usage.
3. Features.
4. Relevant information.
5. Bugs and problems.
6. Authors

1. About the project:
1.1. Description:
This project was planned to pay tribute to the popular and renowned arcade game “Snake” developed and published by  Gremlin in 1976.
The rules of “Snake” are as follows:
-  An apple is placed at a random location in the map not occupied by the snake.
-  If the snake hits an apple, then the snake grows (becomes longer).
	*When this happens, a new apple should appear at a new random location.
- There is not a victory condition.
- The player loses if the snake hit a wall or itself.
- When the player loses, display “Game Over” and then show in the console the score and length of the snake.

2. Usage:
2.1. Console game:
For our project we did a console game application, is meant to be played in the console tool that is more frequently used to debug our OOP projects in cpp, for this specific reason we faced problems with the responsiveness of the game, so we implemented the following solutions  each input is registered seven times in 70ms and the snake is updated every tenth of a second, this last variable will change every time the level increase so the difficulty of the game remains for more skilled players.

3. Features:
3.1. Player:
Every time that the game is restarted a new player is created, in our application, a player contains the current level that increases every time that a certain quantity of apples is reached, as mentioned before the level affects directly the difficulty of the game as the snake moves at a faster pace depending on this; the player also has a register of the time and the name of the person, the name is asked to the user at the moment when the game is over, and the time serves as a history to differentiate all the instances of player. 
3.2. Apple:
The apple is the objective of the player, it spawns on a random location inside the borders. In this project we had to make a validation because the apple is also not supposed to spawn in a location that is already occupied by the snake. (continuar...)
3.3. Snake:


4. Additional information:
4.1.

5. Bugs and problems:
5.1.

6. Authors:
6.1. Hector Fonseca:
6.2. Nicolas Perdomo:
-Describing the application features.
-Describe the additional features your team designed and developed.
-Describe relevant information.
-Describe bugs and problems