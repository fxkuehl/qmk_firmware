/*
Copyright 2022 Felix Kuehling <felix.kuehling@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// Layer definitions
enum layers {
    L_BASE,
    L_FN_LOCKED,
    L_BASE_OV_FN,
    L_SYM_LOCKED,
    L_BASE_OV_SYM,
#ifdef MOUSEKEY_ENABLE
    L_MOUSE,
#endif
    L_FN,
    L_SYM,
    L_MACRO,
    L_MEDIA,
    L_NUM_LAYERS
};
