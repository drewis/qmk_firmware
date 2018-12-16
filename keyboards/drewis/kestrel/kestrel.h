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
#define LAYOUT( \
    k11, k12, k21, k22, k31, k32,           k41, k42, k51, k52, k61, k62, \
    k13, k14, k23, k24, k33, k34, k39, k49, k43, k44, k53, k54, k63, k64,    \
    k15, k16, k25, k26, k35, k36, k29, k59, k45, k46, k55, k56, k65, k66,   \
    k17, k18, k27, k28, k37, k38, k19, k69, k47, k48, k57, k58, k67, k68   \
) \
{ \
    { k11, k21, k31, k41, k51, k61 }, \
    { k12, k22, k32, k42, k52, k62 }, \
    { k13, k23, k33, k43, k53, k63 }, \
    { k14, k24, k34, k44, k54, k64 }, \
    { k15, k25, k35, k45, k55, k65 }, \
    { k16, k26, k36, k46, k56, k66 }, \
    { k17, k27, k37, k47, k57, k67 }, \
    { k18, k28, k38, k48, k58, k68 }, \
    { k19, k29, k39, k49, k59, k69 }, \
}

