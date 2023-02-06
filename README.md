# so_long

## Description :

Simple 2D game accepting custom maps, my first graphical project ever. Assets by [shubibubi](https://shubibubi.itch.io/).

## How to compile

Run `make link` in root folder. Once MiniLibX finishes complaining, run `./so_long [map_name.ber]`, ex. `./so_long [maps/map2.ber]`.

PS : 42 school's MiniLibX has different versions depending on the system, I used the mac version so it won't work elsewhere, unless you change the `src/mlx` folder with your system's version. Plus I use mac key codes for pretty much everything, so it won't work elsewhere even more, unless you swap the `so_long.h` file's `KEY_<smth>` define macros with your system's ones.

## How to play

The goal is to make it to the exit in the least amounts of steps possible, while collecting all the items and avoiding the foe.

You can make your own maps : 

- 1 is a wall
- 0 is free space
- P is the player starting position
- C is an item
- E is the exit
- F is a foe

They must be rectangular, end with .ber extension and must be surrounded by walls. They also must have only 1 Player and 1 exit, at least one item, and there must be a path for the player to take. The foe is optional. Sounds like fun i know.

Example of maps are in /maps dir.

## Example

Here's a vid of the "gameplay" :

[![so_long](http://i3.ytimg.com/vi/8jCU5gmKVdw/hqdefault.jpg)](https://youtu.be/8jCU5gmKVdw)