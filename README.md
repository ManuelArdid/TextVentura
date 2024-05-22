# TextVentura
Created as a project for a subject in my university education and graded with honors, TextVentura is an engine that allows you to create terminal-based interactive fiction games in a simple way through the editing of a single .dat file.

In TextVentura, you can create rooms and objects with rich descriptions, as well as doors that block the way until the appropriate object is used. The engine supports intricate object-collecting based puzzles and immersive storytelling, providing a robust foundation for your interactive fiction projects.

Being open-source and featuring simple, well-documented code, TextVentura is highly adaptable to the needs of your project. Whether you're a novice developer or an experienced programmer, you can easily modify and extend the engine to suit your creative vision.

In the following repository https://github.com/ManuelArdid/TextVentura-Herthal/, you can find an example of a simple game created with TextVentura (written in Spanish). Simply replace the .dat file to try it out and see the possibilities for yourself.

# How to make a game
To create a game with TextVentura, you only need to modify the data.dat file. By modifying this file, you can add rooms, objects, and links between rooms.

## Rooms
To add a room to the game, you must follow this format:
#s:[room id]|[room name]|[north link id]|[west link id]|[south link id]|[east link id]|[up link id]|[down link id]|[current light]|[initial light]|[general description]|[description]|[art1]|[art2]|[art3]
- **room id**: unique id of the room
- **room name**: name of the room
- **north link id**: id of the north link
- **west link id**: id of the west link
- **south link id**: id of the south link
- **east link id**: id of the east link
- **up link id**: id of the up link
- **down link id**: id of the down link
- **current light**: current light level (0/1), by default it should match the initial level
- **initial light**: initial light level (0/1)
- **general description**: short description of the room
- **description**: detailed description of the room
- **art**: you can paint the room's "artwork" with 3 lines of 7 characters. They will be painted on top of each other, art 1 at the top and art 3 at the bottom. For the default "empty" room, use: `|       |       |       |`

Room example:
#s:1|Entrance|-1|-1|1|-1|-1|-1|1|1|Mansion entrance|The eerie mansion door greets you wide open.| _____ |[ I ]|[ .I. ]|

## Links
Links connect the rooms; think of them as doors, but they can be anything (doors, hatches, puzzles, rivers...). To create a new link, you must follow this format:
#l:[link id]|[link name]|[room 1 id]|[room 2 id]|[state]|
- **link id**: unique id for the link
- **link name**: name of the link
- **room 1 id**: id of one of the two connected rooms
- **room 2 id**: id of the other connected room
- **state**: state of the link, open or closed (0/1)
  
Link example:
#l:1|door|2|1|0| this is a door between room 1 and 2

## Objects
Objects are located in rooms. To create an object, follow this format:
#[object id]|[object name]|[id room location]|[description]|[movable]|[object id dependency]|[id room key]|[illuminate]|[turned on]|[discovery]
- **object id**: unique id of the object
- **object name**: name of the object
- **id room location**: id of the room where the object is located
- **description**: description of the object
- **movable**: whether the object can be picked up or not (1/0)
- **object id dependency**: some objects need other objects to be picked up (e.g., water and bottle). id of the necessary object to pick this one up or -1 if it has no dependency
- **id room key**: some objects function as keys, id of the link they open or -1 if it is not a key
- **illuminate**: whether the object can illuminate or not (1/0)
- **turned on**: whether the object is turned on or not (0/1)
- **discovery**: whether the object has already been discovered by the player (0/1)
  
Object example:
#o:2|axe|6|A sharp axe capable of cutting wood.|1|-1|2|0|0 this axe can be picked up and is used to open a link, which could be, for example, a door with planks

## Player
Last but not least, the player. To create the pleayer use this format:
#p:1|[player name]|[initial position]|[max object]| 
- **player name**: name of the player
- **initial position**: room id of the initial room 
- **max objects**: maximum number of objects the player can carry

Note that the player id is always 1.


# Dice
The dice functionality is integrated into the code and continues to work with the roll command, but for design reasons, I have decided to remove it from the graphical part as the base game does not use it at any point.
It is only necessary to modify graphic_engine.c so that the command is displayed on the screen.
