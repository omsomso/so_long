# so_long

A small 2D game made for the 42 school curriculum with MiniLibX. Grab every item, dodge the
foe, get out. That's the whole plot.

[![so_long gameplay: click to watch on YouTube](https://img.youtube.com/vi/8jCU5gmKVdw/hqdefault.jpg)](https://youtu.be/8jCU5gmKVdw)

*Gameplay video (click the picture to watch it on YouTube).*

## How to play

- Move with **W A S D** or the **arrow keys**. **Esc** quits.
- Collect every item, then walk into the exit to win.
- Some maps have a foe. Every time you move, it takes a step towards you. If it catches you,
  you lose.
- The counter in the corner keeps track of your moves and items, for bragging rights.

## Build and run

macOS only (the macOS version of MiniLibX is included in `src/mlx`).

```sh
make
./so_long maps/map1.ber
```

Three maps come with it: `map1.ber` is a quick warm-up, `map2.ber` and `map3.ber` are bigger
and come with a foe.

## Make your own map

A map is a `.ber` text file made of these characters:

| Character | Meaning |
| --- | --- |
| `1` | wall |
| `0` | floor |
| `P` | you (exactly one) |
| `E` | the exit (exactly one) |
| `C` | an item (at least one) |
| `F` | the foe (optional, at most one) |

The map has to be a rectangle closed off by walls, and you must be able to reach every item
and the exit. If something's off, the game will tell you, in its own words:
*"The map's borders aren't closed with walls or smth."*
