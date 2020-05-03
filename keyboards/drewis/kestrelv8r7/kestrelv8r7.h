/*
 * Copyright 2019 REPLACE_WITH_YOUR_NAME
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
    k11, k12, k13, k14, k15, k16,                               k56, k55, k54, k53, k52, k51,  \
    k21, k22, k23, k24, k25, k26, k17, k27, k37, k77, k67, k57, k66, k65, k64, k63, k62, k61, \
    k31, k32, k33, k34, k35, k36,                               k76, k75, k74, k73, k72, k71, \
         k42, k43, k44, k45,      k46, k47, k41, k81, k87, k86,      k85, k84, k83, k82 \
) \
{ \
    { k11, k12, k13, k14, k15, k16, k17 }, \
    { k21, k22, k23, k24, k25, k26, k27 }, \
    { k31, k32, k33, k34, k35, k36, k37 }, \
    { k41, k42, k43, k44, k45, k46, k47 }, \
    { k51, k52, k53, k54, k55, k56, k57 }, \
    { k61, k62, k63, k64, k65, k66, k67 }, \
    { k71, k72, k73, k74, k75, k76, k77 }, \
    { k81, k82, k83, k84, k85, k86, k87 }, \
}

