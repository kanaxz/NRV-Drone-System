/* ====================================================================
 * This file is part of Raspcopter.
 *
 * Copyright (C) 2014 - Florent Revest <florent.revest666@gmail.com>

 * Raspcopter is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Raspcopter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Raspcopter.  If not, see <http://www.gnu.org/licenses/>.
 * ================================================================== */


#ifndef _VECTORFLOAT_H_
#define _VECTORFLOAT_H_

 class VectorFloat
{
public:
    float x;
    float y;
    float z;

    VectorFloat() {
        x = 0;
        y = 0;
        z = 0;
    }

    VectorFloat(float nx, float ny, float nz) {
        x = nx;
        y = ny;
        z = nz;
    }

    float getMagnitude() {
        return sqrt(x*x + y*y + z*z);
    }

    void normalize() {
        float m = getMagnitude();
        x /= m;
        y /= m;
        z /= m;
    }

    VectorFloat getNormalized() {
        VectorFloat r(x, y, z);
        r.normalize();
        return r;
    }

    void rotate(Quaternion *q) {
        Quaternion p(0, x, y, z);
        p = q -> getProduct(p);
        p = p.getProduct(q -> getConjugate());
        x = p.x;
        y = p.y;
        z = p.z;
    }

    VectorFloat getRotated(Quaternion *q) {
        VectorFloat r(x, y, z);
        r.rotate(q);
        return r;
    }
};

#endif /* _VECTORFLOAT_H_ */