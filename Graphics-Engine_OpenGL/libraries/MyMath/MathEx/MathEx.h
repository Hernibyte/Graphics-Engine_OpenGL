#ifndef MATHEX_H
#define MATHEX_H
#include <math.h>
using namespace std;

namespace My 
{
	const float PI = 3.14159265358979323846f;
	const float Infinity = INFINITY;
	const float NaN = NAN;
	const float radToDeg = (180.0f / PI);
	const float degToRad = (PI / 180.0f);
	const float kEpsilon = 1e-05f;

	float Cos(float value);
	double Cos(double value);
	float Sin(float value);
	double Sin(double value);
	float Tan(float value);
	double Tan(double value);
	float Acos(float value);
	double Acos(double value);
	float Asin(float value);
	double Asin(double value);
	float Atan(float value);
	double Atan(double value);
	float Atan2(float firstValue, float secondValue);
	double Atan2(double firstValue, double secondValue);

	float Cosh(float value);
	double Cosh(double value);
	float Sinh(float value);
	double Sinh(double value);
	float Tanh(float value);
	double Tanh(double value);
	float Acosh(float value);
	double Acosh(double value);
	float Asinh(float value);
	double Asinh(double value);
	float Atanh(float value);
	double Atanh(double value);

	float Exp(float value);
	double Exp(double value);
	float Frexp(float x, int* y);
	double Frexp(double x, int* y);
	float Ldexp(float x, int y);
	double Ldexp(double x, int y);
	float Log(float value);
	double Log(double value);
	float Log10(float value);
	double Log10(double value);
	float Modf(float x, float* y);
	double Modf(double x, double* y);
	float Exp2(float value);
	double Exp2(double value);
	float Expm1(float value);
	double Expm1(double value);
	float Ilogb(float value);
	double Ilogb(double value);
	float Log1p(float value);
	double Log1p(double value);
	float Log2(float value);
	double Log2(double value);
	float Logb(float value);
	double Logb(double value);
	float Scalbln(float x, float y);
	double Scalbln(double x, double y);
	float Scalbn(float x, float y);
	double Scalbn(double x, double y);

	float Pow(float x, float y);
	double Pow(double x, double y);
	float Sqrt(float value);
	double Sqrt(double value);
	float Cbrt(float value);
	double Cbrt(double value);
	float Hypot(float x, float y);
	double Hypot(double x, double y);

	//completar error and gamma functions
	float Erf(float value);
	double Erf(double value);
	float Erfc(float value);
	double Erfc(double value);
	float Tgamma(float value);
	double Tgamma(double value);
	float Lgamma(float value);
	double Lgamma(double value);
	//=====

	//completar rounding and remainder functions
	
	//=====

	//completar floating-point manipulation functions
	float Copysing(float number, float sing);
	double Copysing(double number, double sing);
	float Nanf(const char* value);
	double Nan(const char* value);
	float Nextafter(float x, float y);
	double Nextafter(double x, double y);
	float Nexttoward(float x, float y);
	double Nexttoward(double x, double y);
	//=====

	float Dif(float x, float y);
	double Dif(double x, double y);
	float Max(float x, float y);
	double Max(double x, double y);
	float Min(float x, float y);
	double Min(double x, double y);

	int Abs(int value);
	float Abs(float value);
	double Abs(double value);
	float Fma(float x, float y, float z);
	double Fma(double x, double y, double z);

	//falta uno aca
	template <class T> bool IsFinite(T);
	template <class T> bool IsInfinite(T);
	template <class T> bool IsNaN(T);
	template <class T> bool IsNormal(T);
	//falta uno aca

	// completar comparison macro / funtions

	//=====
}

#endif // !MATHEX_H
