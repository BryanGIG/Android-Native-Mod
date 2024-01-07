#ifndef MATRIX4_HPP
#define MATRIX4_HPP

struct Matrix4x4 {


    union {
        struct {
            float m00;
            float m10;
            float m20;
            float m30;
            float m01;
            float m11;
            float m21;
            float m31;
            float m02;
            float m12;
            float m22;
            float m32;
            float m03;
            float m13;
            float m23;
            float m33;
        };
        float m[16];
    };

    inline Matrix4x4();

    inline Matrix4x4 operator*(const Matrix4x4 &m2) const;

    inline Matrix4x4(float entry00, float entry01, float entry02, float entry03, float entry10,
                     float entry11, float entry12, float entry13, float entry20, float entry21,
                     float entry22, float entry23, float entry30, float entry31, float entry32,
                     float entry33);

    inline Vector3 MultiplyPoint(Vector3 point);
};

Matrix4x4::Matrix4x4() : m00(1.0f), m10(0.0f), m20(0.0f), m30(0.0f),
                         m01(0.0f), m11(1.0f), m21(0.0f), m31(0.0f),
                         m02(0.0f), m12(0.0f), m22(1.0f), m32(0.0f),
                         m03(0.0f), m13(0.0f), m23(0.0f), m33(1.0f) {}

Matrix4x4::Matrix4x4(float entry00, float entry01, float entry02, float entry03,
                     float entry10, float entry11, float entry12, float entry13,
                     float entry20, float entry21, float entry22, float entry23,
                     float entry30, float entry31, float entry32, float entry33)
        : m{entry00, entry01, entry02, entry03,
            entry10, entry11, entry12, entry13,
            entry20, entry21, entry22, entry23,
            entry30, entry31, entry32, entry33} {}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &rhs) const {
    Matrix4x4 res;
    res.m00 = this->m00 * rhs.m00 + this->m01 * rhs.m10 + this->m02 * rhs.m20 + this->m03 * rhs.m30;
    res.m01 = this->m00 * rhs.m01 + this->m01 * rhs.m11 + this->m02 * rhs.m21 + this->m03 * rhs.m31;
    res.m02 = this->m00 * rhs.m02 + this->m01 * rhs.m12 + this->m02 * rhs.m22 + this->m03 * rhs.m32;
    res.m03 = this->m00 * rhs.m03 + this->m01 * rhs.m13 + this->m02 * rhs.m23 + this->m03 * rhs.m33;

    res.m10 = this->m10 * rhs.m00 + this->m11 * rhs.m10 + this->m12 * rhs.m20 + this->m13 * rhs.m30;
    res.m11 = this->m10 * rhs.m01 + this->m11 * rhs.m11 + this->m12 * rhs.m21 + this->m13 * rhs.m31;
    res.m12 = this->m10 * rhs.m02 + this->m11 * rhs.m12 + this->m12 * rhs.m22 + this->m13 * rhs.m32;
    res.m13 = this->m10 * rhs.m03 + this->m11 * rhs.m13 + this->m12 * rhs.m23 + this->m13 * rhs.m33;

    res.m20 = this->m20 * rhs.m00 + this->m21 * rhs.m10 + this->m22 * rhs.m20 + this->m23 * rhs.m30;
    res.m21 = this->m20 * rhs.m01 + this->m21 * rhs.m11 + this->m22 * rhs.m21 + this->m23 * rhs.m31;
    res.m22 = this->m20 * rhs.m02 + this->m21 * rhs.m12 + this->m22 * rhs.m22 + this->m23 * rhs.m32;
    res.m23 = this->m20 * rhs.m03 + this->m21 * rhs.m13 + this->m22 * rhs.m23 + this->m23 * rhs.m33;

    res.m30 = this->m30 * rhs.m00 + this->m31 * rhs.m10 + this->m32 * rhs.m20 + this->m33 * rhs.m30;
    res.m31 = this->m30 * rhs.m01 + this->m31 * rhs.m11 + this->m32 * rhs.m21 + this->m33 * rhs.m31;
    res.m32 = this->m30 * rhs.m02 + this->m31 * rhs.m12 + this->m32 * rhs.m22 + this->m33 * rhs.m32;
    res.m33 = this->m30 * rhs.m03 + this->m31 * rhs.m13 + this->m32 * rhs.m23 + this->m33 * rhs.m33;

    return res;
}

Vector3 Matrix4x4::MultiplyPoint(Vector3 point) {
    Vector3 res;
    float w;
    res.X = this->m00 * point.X + this->m01 * point.Y + this->m02 * point.Z + this->m03;
    res.Y = this->m10 * point.X + this->m11 * point.Y + this->m12 * point.Z + this->m13;
    res.Z = this->m20 * point.X + this->m21 * point.Y + this->m22 * point.Z + this->m23;
    w = this->m30 * point.X + this->m31 * point.Y + this->m32 * point.Z + this->m33;
    if (w > 0.01f) {
        w = 1.0F / w;
        res.X *= w;
        res.Y *= w;
        res.Z *= w;
        return res;
    } else {
        return Vector3::Zero();
    }
}

#endif
