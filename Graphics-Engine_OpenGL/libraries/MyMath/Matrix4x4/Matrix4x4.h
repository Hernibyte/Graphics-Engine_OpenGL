#ifndef MATRIX4X4_H
#define MATRIX4X4_H
#include "../Vector3/vector3.h"
#include "../Vector4/Vector4.h"
#include "../Quaternion/Quaternion.h"

namespace My
{
	struct Matrix4x4
	{
        float value[16];
        //0  1  2  3
        //4  5  6  7
        //8  9  10 11
        //12 13 14 15

        static Matrix4x4 identity;
        static Matrix4x4 zero;
        Matrix4x4 transpose();
        Vector3 lossyScale();

        Matrix4x4();
        Matrix4x4(Vector4 column0, Vector4 column1, Vector4 column2, Vector4 column3);
        Matrix4x4(const Matrix4x4& matrix);
	    
        Vector4 GetColumn(int index);
        Vector4 GetRow(int index);
        void SetColumn(int index, Vector4 column);
        void SetRow(int index, Vector4 row);

        float* Value_ptr();
        float* Value_ptr(int i);

        void Projection(const float& angleOfView, const float& near, const float& far);

        void Orthographic(const float& buttom, const float& top, const float& left, const float& right,
                          const float& near, const float& far);

        void TRS(Vector3 position, Quaternion rotation, Vector3 scale);

        void Translate(Vector3 translate);

        void Scale(Vector3 scale);

        void Rotate(Quaternion quaternion);

        static float* Value_ptr(Matrix4x4 matrix);
        static float* Value_ptr(Matrix4x4 matrix, int i);

        static Matrix4x4 Projection(const float& angleOfView, const float& near, const float& far, Matrix4x4 matrix);

        static Matrix4x4 Orthographic(const float& buttom, const float& top, const float& left, const float& right,
                                      const float& near, const float& far, Matrix4x4 matrix);
        
        static Matrix4x4 Rotate(Matrix4x4 matrix, Quaternion quaternion);

        static Matrix4x4 Scale(Matrix4x4 matrix, Vector3 scale);

        static Matrix4x4 Translate(Matrix4x4 matrix, Vector3 translate);

        static Matrix4x4 TRS(Matrix4x4 matrix, Matrix4x4 translate, Matrix4x4 rotate, Matrix4x4 scale);

        static Matrix4x4 TRS(Matrix4x4 translate, Matrix4x4 rotate, Matrix4x4 scale, Vector3 position, Quaternion rotation, Vector3 scalar);
    };

    Vector4 operator*(Matrix4x4 a, Vector4 vector);
    Matrix4x4 operator*(Matrix4x4 a, Matrix4x4 b);
    bool operator==(Matrix4x4 a, Matrix4x4 b);
    bool operator!=(Matrix4x4 a, Matrix4x4 b);
}

#endif // !MATRIX4X4_H
