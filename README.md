# Epitech-my_rpg :video_game:
Create your own RPG with CSFML library.

## SUBJECT 

Create a RPG in C.

Your main challenge for this game will be to create a complete product using everything that you and your team know.

Your game must follow the following rules:
- The player needs to have characteristics which you can find in the status menu.
- The player can fight enemies, statistics will impact the fights results.
- There must be NPC in your game.
- You need to implement at least one quest.
- The player must have an inventory which can contain a limited set of items.
- The player can earn experience by winning fights and accomplishing specific actions.
- With enough experience, the player can level up, upgrading its statistics.

To give the users the feeling that you’re delivering a complete product you need to polish as much as possible
your game.

- Having a pleasant user interface.
- Create a coherent universe (visual assets, audio assets, scenario, . . .)
- Create a funny game where the player has at least one goal.
- Create a game with a beginning and an end.

## GAME REQUIEREMENTS
### MANDATORY :bangbang:
The following features are mandatory (if your project is missing one of them it will not be evaluated further):

- the window can be closed using events. :heavy_check_mark:
- the game manages the input from the mouse click and keyboard. :heavy_check_mark:
- the game contains animated sprites rendered thanks to sprite sheets. :heavy_check_mark:
- animations in your program are frame rate independent. :heavy_check_mark:
- animations and movements in your program are timed by clocks. :heavy_check_mark:

### TECHNICAL REQUIEREMENTS
This project, being the last project of the module, the following requierement are the mathematical and
technical parts which has to be present in your final project:

- A collision system including moving and static elements with different shapes. :heavy_check_mark:
- A simple particle system that can display at least 2 types of particles. :heavy_check_mark:
- Particle effects (changing colors, scaling, bouncing, fading) to simulate realistic environment (wind,
fire, rain, snow. . .). :heavy_check_mark:
- Camera movements (zoom, translation, rotation). :heavy_check_mark:
- 3D effects (depth scaling, isometric projection. . .). :heavy_check_mark:

### MUST :bangbang:
The game must have:
- A starting menu with at least two buttons, one to launch a game, and one to quit the game. :heavy_check_mark:
- An escape key to pause the game when launched. :heavy_check_mark:
- A menu when the game is paused with at least two buttons, one to go to the starting menu and the
other to leave the game. :heavy_check_mark:
- A basic fighting system. :heavy_check_mark:
- An inventory and status menu. :heavy_check_mark:

### SHOULD :bangbang:
- Your window should stick between 800x600 pixels and 1920x1080 pixels. :heavy_check_mark:
- The game should have an “How To play” menu, explaining how to play your game. :heavy_check_mark:
- The game should have NPC with whom the player can interact (fight, quest, discuss). :heavy_check_mark:
- As much information as possible about the game should be stored in a configuration file. :heavy_check_mark:
- The buttons in your game should have at least three visual states: idle, hover, and clicked. :heavy_check_mark:
- If your game has cut scenes or an animated intro (and it should) the player should be able to skip it. :heavy_check_mark:
- The game should have a beginning and an end. :heavy_check_mark:
- The game should have an advanced collision system to manage complex fighting. :heavy_check_mark:

### COULD :heavy_exclamation_mark:
The game could:
- let the player save and load its own save. :x:
- let the user customize its character. :heavy_check_mark:
- have different types of enemies. :heavy_check_mark:
- have a skill tree, unlocking different abilities (active and passive). :heavy_check_mark:
- have a “settings” menu that could contain sound options and/or screen size options. :heavy_check_mark:
- have a particle engine. :heavy_check_mark:
- use scripting to describe entities. :heavy_check_mark:
- have a map editor. :heavy_check_mark:

## OUR GAME
### Setup
Clone the repository, and do a make at the root. Then, ./my_rpg and have fun, everything is easy to understand in the game.

### How to play 
After the cutscene, you can edit the map with map editor, edit sounds settings, change FPS, resize the window or play the game.

If you want to custom the game, make a file name ".config".

Use this syntax to configure the ".config" file :

```sh
[COMMAND]
    arg1,arg2,arg3,etc...

AVALIABLE COMMANDS:

[SKIN]
    Args:
        skin_name
    Possible values:
        HERO1,HERO2,VILLAGER3,VILLAGER7,VILLAGER8,VILLAGER9
    Description:
        change the default player's skin


[CLICK_TEXTURE] / [SNOW_TEXTURE] / [RAIN_TEXTURE] [VIDEOMODE]
    Args:
        filepath
    Description:
        change the file used to create the particle.
```

You can also edit the "map.txt" file as follow:

``` sh
N -> Necromancer ennemy.

P -> Spawn an NPC.

Z -> Spawn a Dread_knight ennemy.

X -> Spawn Death_knight ennemy.

T -> Spawn Fire duck. (Tyler)

I -> Spawn Ice duck. (Patrick)

V -> Spawn Water duck. (Valerie)

D -> Spawn Rock duck. (Denis)

```

Now you can move your Carlos with zqsd, attack with space, open skill tree with H, open quest menu with X and check your stats with E. 
Press Escape to pause the game.

Interact with the NPC to get Quests.

Your goal is find the 4 divine Ducks, and kill the big boss. Level up, by killing monsters to increase your stats in the skill tree menu (very important).

##### Skill tree
Each level give you 1 skill point, wich can unlock something in the skill tree.

## PUSH CONVENTION

*  __[ACTION]  (description)__


> [ADD]: 
  Adding a new thing to the project (like a file or a functionnality)

> [DEL]:
  Deleting something from the project (like a file or a functionnality that is obsolete)

> [FIX]:
  Fixing something from the project (like a file or a functionnaly that was not working well or to upgrade it)

> [MERGE]:
  Fixing merge conflict between branches.