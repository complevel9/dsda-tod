//
// Copyright(C) 2022 by Ryan Krafnick
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//	DSDA UDMF
//

#ifndef __DSDA_UDMF__
#define __DSDA_UDMF__

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>

#define UDMF_ML_BLOCKING           0x0000000000000001ull
#define UDMF_ML_BLOCKMONSTERS      0x0000000000000002ull
#define UDMF_ML_TWOSIDED           0x0000000000000004ull
#define UDMF_ML_DONTPEGTOP         0x0000000000000008ull
#define UDMF_ML_DONTPEGBOTTOM      0x0000000000000010ull
#define UDMF_ML_SECRET             0x0000000000000020ull
#define UDMF_ML_SOUNDBLOCK         0x0000000000000040ull
#define UDMF_ML_DONTDRAW           0x0000000000000080ull
#define UDMF_ML_MAPPED             0x0000000000000100ull
#define UDMF_ML_PASSUSE            0x0000000000000200ull
#define UDMF_ML_TRANSLUCENT        0x0000000000000400ull
#define UDMF_ML_JUMPOVER           0x0000000000000800ull
#define UDMF_ML_BLOCKFLOATERS      0x0000000000001000ull
#define UDMF_ML_PLAYERCROSS        0x0000000000002000ull
#define UDMF_ML_PLAYERUSE          0x0000000000004000ull
#define UDMF_ML_MONSTERCROSS       0x0000000000008000ull
#define UDMF_ML_MONSTERUSE         0x0000000000010000ull
#define UDMF_ML_IMPACT             0x0000000000020000ull
#define UDMF_ML_PLAYERPUSH         0x0000000000040000ull
#define UDMF_ML_MONSTERPUSH        0x0000000000080000ull
#define UDMF_ML_MISSILECROSS       0x0000000000100000ull
#define UDMF_ML_REPEATSPECIAL      0x0000000000200000ull
#define UDMF_ML_PLAYERUSEBACK      0x0000000000400000ull
#define UDMF_ML_ANYCROSS           0x0000000000800000ull
#define UDMF_ML_MONSTERACTIVATE    0x0000000001000000ull
#define UDMF_ML_BLOCKPLAYERS       0x0000000002000000ull
#define UDMF_ML_BLOCKEVERYTHING    0x0000000004000000ull
#define UDMF_ML_FIRSTSIDEONLY      0x0000000008000000ull
#define UDMF_ML_ZONEBOUNDARY       0x0000000010000000ull
#define UDMF_ML_CLIPMIDTEX         0x0000000020000000ull
#define UDMF_ML_WRAPMIDTEX         0x0000000040000000ull
#define UDMF_ML_MIDTEX3D           0x0000000080000000ull
#define UDMF_ML_MIDTEX3DIMPASSIBLE 0x0000000100000000ull
#define UDMF_ML_CHECKSWITCHRANGE   0x0000000200000000ull
#define UDMF_ML_BLOCKPROJECTILES   0x0000000400000000ull
#define UDMF_ML_BLOCKUSE           0x0000000800000000ull
#define UDMF_ML_BLOCKSIGHT         0x0000001000000000ull
#define UDMF_ML_BLOCKHITSCAN       0x0000002000000000ull
#define UDMF_ML_TRANSPARENT        0x0000004000000000ull

typedef uint64_t udmf_line_flags_t;

typedef struct {
  int id;
  int v1;
  int v2;
  int special;
  int arg0;
  int arg1;
  int arg2;
  int arg3;
  int arg4;
  int sidefront;
  int sideback;
  int locknumber;
  udmf_line_flags_t flags;
} udmf_line_t;

#define UDMF_SF_LIGHTABSOLUTE  0x01
#define UDMF_SF_LIGHTFOG       0x02
#define UDMF_SF_NOFAKECONTRAST 0x04
#define UDMF_SF_SMOOTHLIGHTING 0x08
#define UDMF_SF_CLIPMIDTEX     0x10
#define UDMF_SF_WRAPMIDTEX     0x20
#define UDMF_SF_NODECALS       0x40

typedef uint8_t udmf_side_flags_t;

typedef struct {
  int offsetx;
  int offsety;
  char texturetop[8];
  char texturebottom[8];
  char texturemiddle[8];
  int sector;
  float scalex_top;
  float scaley_top;
  float scalex_mid;
  float scaley_mid;
  float scalex_bottom;
  float scaley_bottom;
  float offsetx_top;
  float offsety_top;
  float offsetx_mid;
  float offsety_mid;
  float offsetx_bottom;
  float offsety_bottom;
  int light;
  udmf_side_flags_t flags;
} udmf_side_t;

typedef struct {
  float x;
  float y;
} udmf_vertex_t;

#define UDMF_SECF_LIGHTFLOORABSOLUTE   0x0001
#define UDMF_SECF_LIGHTCEILINGABSOLUTE 0x0002
#define UDMF_SECF_SILENT               0x0004
#define UDMF_SECF_NOFALLINGDAMAGE      0x0008
#define UDMF_SECF_DROPACTORS           0x0010
#define UDMF_SECF_NORESPAWN            0x0020
#define UDMF_SECF_HIDDEN               0x0040
#define UDMF_SECF_WATERZONE            0x0080
#define UDMF_SECF_DAMAGETERRAINEFFECT  0x0100
#define UDMF_SECF_DAMAGEHAZARD         0x0200

typedef uint16_t udmf_sector_flags_t;

typedef struct {
  int heightfloor;
  int heightceiling;
  char texturefloor[8];
  char textureceiling[8];
  int lightlevel;
  int special;
  int id;
  float xpanningfloor;
  float ypanningfloor;
  float xpanningceiling;
  float ypanningceiling;
  float xscalefloor;
  float yscalefloor;
  float xscaleceiling;
  float yscaleceiling;
  float rotationfloor;
  float rotationceiling;
  int lightfloor;
  int lightceiling;
  float gravity;
  int damageamount;
  int damageinterval;
  int leakiness;
  udmf_sector_flags_t flags;
} udmf_sector_t;

#define UDMF_TF_SKILL1      0x00000001
#define UDMF_TF_SKILL2      0x00000002
#define UDMF_TF_SKILL3      0x00000004
#define UDMF_TF_SKILL4      0x00000008
#define UDMF_TF_SKILL5      0x00000010
#define UDMF_TF_AMBUSH      0x00000020
#define UDMF_TF_SINGLE      0x00000040
#define UDMF_TF_DM          0x00000080
#define UDMF_TF_COOP        0x00000100
#define UDMF_TF_FRIEND      0x00000200
#define UDMF_TF_DORMANT     0x00000400
#define UDMF_TF_CLASS1      0x00000800
#define UDMF_TF_CLASS2      0x00001000
#define UDMF_TF_CLASS3      0x00002000
#define UDMF_TF_STANDING    0x00004000
#define UDMF_TF_STRIFEALLY  0x00008000
#define UDMF_TF_TRANSLUCENT 0x00010000
#define UDMF_TF_INVISIBLE   0x00020000
#define UDMF_TF_COUNTSECRET 0x00040000

typedef uint32_t udmf_thing_flags_t;

typedef struct {
  int id;
  float x;
  float y;
  float height;
  int angle;
  int type;
  int special;
  int arg0;
  int arg1;
  int arg2;
  int arg3;
  int arg4;
  float gravity;
  int health;
  float scalex;
  float scaley;
  float scale;
  int floatbobphase;
  udmf_thing_flags_t flags;
} udmf_thing_t;

typedef struct {
  udmf_line_t* lines;
  udmf_side_t* sides;
  udmf_vertex_t* vertices;
  udmf_sector_t* sectors;
  udmf_thing_t* things;
} udmf_t;

extern udmf_t udmf;

typedef void (*udmf_errorfunc)(const char *fmt, ...);	// this must not return!

void dsda_ParseUDMF(const unsigned char* buffer, size_t length, udmf_errorfunc err);

#ifdef __cplusplus
}
#endif

#endif
