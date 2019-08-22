/* Copyright 2019 REPLACE_WITH_YOUR_NAME
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
#define LAYOUT( \
    k21, k11, k12, k13, k14, k15, k16, k66, k65, k64, k63, k62, k61, k71,  \
    k31, k22, k23, k24, k25, k26,           k76, k75, k74, k73, k72, k81, \
    k41, k32, k33, k34, k35, k36,           k86, k85, k84, k83, k82, k91, \
    k51, k42, k43, k44, k45, k46,           k96, k95, k94, k93, k92, k101, \
              k52, k53, k54, k55, k56, k106,k105,k104,k103,k102 \
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
    { k91, k92, k93, k94, k95, k96 }, \
    { k101, k102, k103, k104, k105, k106 }, \
}

