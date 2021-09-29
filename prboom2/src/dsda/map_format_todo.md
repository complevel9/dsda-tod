### Lines
- ML_BLOCK_PLAYERS
- ML_BLOCKEVERYTHING
- SPAC_UseThrough
- P_ExecuteLineSpecial ~170 specials

### Sectors
- "Open" scripts in P_SpawnSpecials
- SCROLLTYPE
- Scroller copying
- Push / pull type abstraction
- Sector damage
- Sector gravity
- Custom scrollers in thing movement
- Friction effect in P_Thrust?
- zs_sky2 uses PL_SKYFLAT but the representation is not compatible
- zs_d_damage_lava_wimpy, zs_d_damage_lava_hefty, zs_d_scroll_east_lava_damage
  - floor impact effect + lava inflictor

### Setup
- Look at special / flag handling in loaders in p_setup.cpp

### Things to Check
- P_UpdateSpecials
- floor type / friction -> hexen format?
- CheckForPushSpecial / MF2_PUSHWALL