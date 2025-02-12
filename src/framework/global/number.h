/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef MU_GLOBAL_NUMBER_H
#define MU_GLOBAL_NUMBER_H

#include <limits>
#include <cassert>

namespace mu {
template<typename T>
inline bool is_zero(T v)
{
    if constexpr (std::numeric_limits<T>::is_integer) {
        return v == 0;
    } else {
        return std::abs(v) <= std::numeric_limits<T>::epsilon();
    }
}

template<typename T>
inline T divide(const T& dividend, const T& divisor)
{
    if (is_zero(divisor)) {
        assert(!is_zero(divisor));
        return T();
    }
    return dividend / divisor;
}

template<typename T>
inline T divide(const T& dividend, const T& divisor, const T& def)
{
    if (is_zero(divisor)) {
        return def;
    }
    return dividend / divisor;
}
}

#endif // MU_GLOBAL_NUMBER_H
