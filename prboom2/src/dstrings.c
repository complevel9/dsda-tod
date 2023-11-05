/* Emacs style mode select   -*- C -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2000 by
 *  Jess Haas, Nicolas Kalkhof, Colin Phipps, Florian Schulze
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *   Globally defined strings.
 *
 *-----------------------------------------------------------------------------
 */

#include "dstrings.h"


// killough 1/18/98: remove hardcoded limit, add const:
const char *const endmsg[]=
{
  // DOOM1
  QUITMSG,
  QUITMSG1,  // "please don't leave, there's more\ndemons to toast!",
  QUITMSG2,  // "let's beat it -- this is turning\ninto a bloodbath!",
  QUITMSG3,  // "i wouldn't leave if i were you.\ndos is much worse.",
  QUITMSG4,  // "you're trying to say you like dos\nbetter than me, right?",
  QUITMSG5,  // "don't leave yet -- there's a\ndemon around that corner!",
  QUITMSG6,  // "ya know, next time you come in here\ni'm gonna toast ya.",
  QUITMSG7,  // "go ahead and leave. see if i care.",  // 1/15/98 killough

  // QuitDOOM II messages
  QUITMSG8,  // "you want to quit?\nthen, thou hast lost an eighth!",
  QUITMSG9,  // "don't go now, there's a \ndimensional shambler waiting\nat the dos prompt!",
  QUITMSG10, // "get outta here and go back\nto your boring programs.",
  QUITMSG11, // "if i were your boss, i'd \n deathmatch ya in a minute!",
  QUITMSG12, // "look, bud. you leave now\nand you forfeit your body count!",
  QUITMSG13, // "just leave. when you come\nback, i'll be waiting with a bat.",
  QUITMSG14, // "you're lucky i don't smack\nyou for thinking about leaving.",  // 1/15/98 killough

  // FinalDOOM?

  // Internal debug. Different style, too.
  "THIS IS NO MESSAGE!\nPage intentionally left blank.",  // 1/15/98 killough
};

// killough 1/18/98: remove hardcoded limit and replace with var (silly hack):
const size_t NUM_QUITMESSAGES = sizeof(endmsg)/sizeof(*endmsg) - 1;
