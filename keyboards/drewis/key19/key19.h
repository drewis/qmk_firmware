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
#ifndef DREWIS_KEY19_H
#define DREWIS_KEY19_H

#include "quantum.h"

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguments representing the physical
// layout of the board and position of the keys
// The second converts the arguments into a two-dimensional array which 
// represents the switch matrix. 
#define LAYOUT( \
    K00, K01, K02, K03, K04, \
    K10, K11, K12, K13, K14,   \
    K20, K21, K22, K23, K24, \
    K30, K31, K32, K33 \
) \
{ \
	{ K00, K01, K02, K03, K04 }, \
	{K10, K11, K12, K13, K14}, \
	{K20, K21, K22, K23, K24}, \
	{ K30, K31, K32, K33 }, \
}

#define LAYOUT_double( \
		k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
		k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
		k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
		k30, k31, k32, k33, k34, k35, k36, k36 \
		) \
{ \
	{k00, k01, k02, k03, k04, k05, k06, k07, k08, k09 }, \
	{k10, k11, k12, k13, k14, k15, k16, k17, k18, k19}, \
	{k20, k21, k22, k23, k24, k25, k26, k27, k28, k29 }, \
	{k30, k31, k32, k33, KC_NO, KC_NO, k34, k35, k36, k36 }\
}

#endif
