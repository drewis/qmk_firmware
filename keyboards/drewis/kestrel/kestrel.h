/* Copyright 2018 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#ifdef KESTREL_BRIDGED
#define LAYOUT( \
    k101, k102, k103, k104, k105, k106, k107, k108, k109, k110, k111, k112, \
    k201, k202, k203, k204, k205, k206, k207, k208, k209, k210, k211, k212, \
    k301, k302, k303, k304, k305, k306, k307, k308, k309, k310, k311, k312, \
    k401, k402, k403, k404, k405, k406, k407, k408, k409, k410, k411, k412  \
) \
{ \
    { k101, k102, k103, k104, k105, k106, k107, k108, k109, k110, k111, k112 }, \
    { k201, k202, k203, k204, k205, k206, k207, k208, k209, k210, k211, k212 }, \
    { k301, k302, k303, k304, k305, k306, k307, k308, k309, k310, k311, k312 }, \
    { k401, k402, k403, k404, k405, k406, k407, k408, k409, k410, k411, k412 }, \
}
#else
#define LAYOUT( \
    k11, k12, k13, k14, k15, k16, k56, k55, k54, k53, k52, k51, \
    k21, k22, k23, k24, k25, k26, k66, k65, k64, k63, k62, k61, \
    k31, k32, k33, k34, k35, k36, k76, k75, k74, k73, k72, k71, \
    k41, k42, k43, k44, k45, k46, k86, k85, k84, k83, k82, k81 \
) \
{ \
    { k11, k12, k13, k14, k15, k16 }, \
    { k21, k22, k23, k24, k25, k26 }, \
    { k31, k32, k33, k34, k35, k36 }, \
    { k41, k42, k43, k44, k45, k46 }, \
    { k51, k52, k53, k54, k55, k56 }, \
    { k61, k62, k63, k64, k65, k66 }, \
    { k71, k72, k73, k74, k75, k76 }, \
    { k81, k82, k83, k84, k85, k86 }, \
}
#endif
