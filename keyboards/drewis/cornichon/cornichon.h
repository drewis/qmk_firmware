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
#ifndef CORNICHON_H
#define CORNICHON_H

#include "quantum.h"

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguments representing the physical
// layout of the board and position of the keys
// The second converts the arguments into a two-dimensional array which 
// represents the switch matrix. 
#ifndef CORNY2
#define LAYOUT( \
		k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
		k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
		k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
		k30, k31, k32, k33, k34, k35, k36, k37, k38, k39  \
		) \
{ \
	{k00, k01, k02, k03, k04, k05, k06, k07, k08, k09 }, \
	{k10, k11, k12, k13, k14, k15, k16, k17, k18, k19 }, \
	{k20, k21, k22, k23, k24, k25, k26, k27, k28, k29 }, \
	{k30, k31, k32, k33, k34, k35, k36, k37, k38, k39 }\
}
#else
#define LAYOUT( \
		k11, k21, k31, k41, k51, k61, k71, k81, k91, k101, \
		k12, k22, k32, k42, k52, k62, k72, k82, k92, k102, \
		k13, k23, k33, k43, k53, k63, k73, k83, k93, k103, \
		k14, k24, k34, k44, k54, k64, k74, k84, k94, k104  \
		) \
{ \
	{ k11, k21, k31, k41, k51 }, \
	{ k12, k22, k32, k42, k52 }, \
	{ k13, k23, k33, k43, k53 }, \
	{ k14, k24, k34, k44, k54 }, \
	{ k101,k91, k81, k71, k61 }, \
	{ k102,k92, k82, k72, k62 }, \
	{ k103,k93, k83, k73, k63 }, \
	{ k104,k94, k84, k74, k64 }, \
}
#endif

#endif
