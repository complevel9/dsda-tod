## HUD Configuration

HUD configurations are stored in the DSDAHUD lump. These defaults can be changed by replacing the lump or specifying a hud config file with `-hud filename`. There are separate configurations for each game (doom, heretic, and hexen), with or without the status bar.

### Specification

A HUD configuration starts with the environment: `game variant`
- The `game` is `doom`, `heretic`, or `hexen`
- The `variant` options are:
  - `ex` (with status bar and extended hud on)
  - `off` (with status bar and extended hud off)
  - `full` (without status bar)

The configuration then consists of a series of components to display: `name x y alignment`
- The `name` specifies which component to display
- The `x` and `y` fields set the location of the component
- The `alignment` controls how the position is translated in different screen sizes
  - `top`
  - `top_left`
    - This alignment accounts for the size of the message area
  - `top_right`
  - `bottom`
  - `bottom_left`
  - `bottom_right`
  - `left`
  - `right`
- For convenience, bottom-aligned `y` values are the distance from the bottom of the screen (`full`) or top of the status bar (`ex` and `off`)

This example configures the extended hud for doom with just the stat totals and time in the bottom left (above the status bar):
```
doom ex
stat_totals 2 8 bottom_left
composite_time 2 16 bottom_left
```

You can find the current default configuration [here](../prboom2/data/lumps/dsdahud.lmp).

### Components

- `stat_totals`: shows the kills / secrets / items on the current map
- `composite_time`: shows the current level time and the total time
- `keys`: shows the acquired keys
- `ammo_text`: shows the weapons and ammo as the status bar does
- `weapon_text`: shows the acquired weapons (color-coded for berserk)
- `ready_ammo_text`: shows the ammo for the current weapon
- `big_ammo`: shows the ammo for the current weapon in the status bar font
- `armor_text`: shows the player armor (color-coded)
- `big_armor`: shows the player armor (color-coded) in the status bar font with the armor sprite
- `big_armor_text`: shows the player armor (color-coded) in the status bar font
- `health_text`: shows the player health (color-coded)
- `big_health`: shows the player health (color-coded) in the status bar font with the health sprite
- `big_health_text`: shows the player health (color-coded) in the status bar font
- `big_artifact`: shows the current artifact as seen on the status bar
- `fps`: shows the current fps
- `attempts`: shows the current and total demo attempts
- `render_stats`: shows various render stats (`idrate`)
- `speed_text`: shows the game clock rate
- `command_display`: shows the history of player commands (demo or otherwise)
- `coordinate_display`: shows various coordinate and velocity data
- `event_split`: shows the time of an event tracked by the `-time_*` arguments
- `level_splits`: shows the splits for the level time and the total time (intermission screen)
- `line_display`: shows the last lines the player activated
- `tracker`: shows the active trackers (they stack *vertically*)
- `local_time`: shows the local time
