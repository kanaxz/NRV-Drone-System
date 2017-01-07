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


#ifndef _QUATENION_H_
#define _QUATENION_H_

class Quaternion
{
public:
    float w;
    float x;
    float y;
    float z;

    Quaternion() {
        w = 1.0f;
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    Quaternion(float nw, float nx, float ny, float nz) {
        w = nw;
        x = nx;
        y = ny;
        z = nz;
    }

    Quaternion getProduct(Quaternion q) {
        return Quaternion(
                   w*q.w - x*q.x - y*q.y - z*q.z,  //     (Q1 * Q2).w = (w1w2 - x1x2 - y1y2 - z1z2)
                   w*q.x + x*q.w + y*q.z - z*q.y,  //     (Q1 * Q2).x = (w1x2 + x1w2 + y1z2 - z1y2)
                   w*q.y - x*q.z + y*q.w + z*q.x,  //     (Q1 * Q2).y = (w1y2 - x1z2 + y1w2 + z1x2)
                   w*q.z + x*q.y - y*q.x + z*q.w); //     (Q1 * Q2).z = (w1z2 + x1y2 - y1x2 + z1w2
    }

    Quaternion getConjugate() {
        return Quaternion(w, -x, -y, -z);
    }

    float getMagnitude() {
        return sqrt(w*w + x*x + y*y + z*z);
    }

    void normalize() {
        float m = getMagnitude();
        w /= m;
        x /= m;
        y /= m;
        z /= m;
    }

    Quaternion getNormalized() {
        Quaternion r(w, x, y, z);
        r.normalize();
        return r;
    }
};

#endif /* _QUATERNION_H_ */