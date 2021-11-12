#include "MathEx.h"

float My::Cos(float value)
{
	return cosf(value);
}
double My::Cos(double value)
{
	return cos(value);
}

float My::Sin(float value)
{
	return sinf(value);
}
double My::Sin(double value)
{
	return sin(value);
}

float My::Tan(float value)
{
	return tanf(value);
}
double My::Tan(double value)
{
	return tan(value);
}

float My::Acos(float value)
{
	return acosf(value);
}
double My::Acos(double value)
{
	return acos(value);
}

float My::Asin(float value)
{
	return asinf(value);
}
double My::Asin(double value)
{
	return asin(value);
}

float My::Atan(float value)
{
	return atanf(value);
}
double My::Atan(double value)
{
	return atan(value);
}

float My::Atan2(float firstValue, float secondValue)
{
	return atan2f(firstValue, secondValue);
}
double My::Atan2(double firstValue, double secondValue)
{
	return atan2(firstValue, secondValue);
}

float My::Cosh(float value)
{
	return coshf(value);
}
double My::Cosh(double value)
{
	return cosh(value);
}

float My::Sinh(float value) 
{
	return sinhf(value);
}
double My::Sinh(double value) 
{
	return sinh(value);
}

float My::Tanh(float value)
{
	return tanhf(value);
}
double My::Tanh(double value)
{
	return tanh(value);
}

float My::Acosh(float value) 
{
	return acoshf(value);
}
double My::Acosh(double value) 
{
	return acosh(value);
}

float My::Asinh(float value)
{
	return asinhf(value);
}
double My::Asinh(double value)
{
	return asinh(value);
}

float My::Atanh(float value)
{
	return atanhf(value);
}
double My::Atanh(double value)
{
	return atanh(value);
}

float My::Exp(float value)
{
	return expf(value);
}
double My::Exp(double value)
{
	return exp(value);
}

float My::Frexp(float x, int* y)
{
	return frexpf(x, y);
}
double My::Frexp(double x, int* y)
{
	return frexp(x, y);
}

float My::Ldexp(float x, int y)
{
	return ldexpf(x, y);
}
double My::Ldexp(double x, int y)
{
	return ldexp(x, y);
}

float My::Log(float value)
{
	return logf(value);
}
double My::Log(double value)
{
	return log(value);
}

float My::Log10(float value)
{
	return log10f(value);
}
double My::Log10(double value)
{
	return log10(value);
}

float My::Modf(float x, float* y)
{
	return modff(x, y);
}
double My::Modf(double x, double* y)
{
	return modf(x, y);
}

float My::Exp2(float value)
{
	return exp2f(value);
}
double My::Exp2(double value)
{
	return exp2(value);
}

float My::Expm1(float value)
{
	return expm1f(value);
}
double My::Expm1(double value)
{
	return expm1(value);
}

float My::Ilogb(float value)
{
	return ilogbf(value);
}
double My::Ilogb(double value)
{
	return ilogb(value);
}

float My::Log1p(float value)
{
	return log1pf(value);
}
double My::Log1p(double value)
{
	return log1p(value);
}

float My::Log2(float value) 
{
	return log2f(value);
}
double My::Log2(double value) {
	return log2(value);
}

float My::Logb(float value)
{
	return logbf(value);
}
double My::Logb(double value)
{
	return logb(value);
}

float My::Scalbln(float x, float y) {
	return scalblnf(x, y);
}
double My::Scalbln(double x, double y)
{
	return scalbln(x, y);
}

float My::Scalbn(float x, float y)
{
	return scalbnf(x, y);
}
double My::Scalbn(double x, double y)
{
	return scalbn(x, y);
}

float My::Pow(float x, float y) 
{
	return powf(x, y);
}
double My::Pow(double x, double y)
{
	return pow(x, y);
}

float My::Sqrt(float value)
{
	return sqrtf(value);
}
double My::Sqrt(double value)
{
	return sqrt(value);
}

float My::Cbrt(float value)
{
	return cbrtf(value);
}
double My::Cbrt(double value)
{
	return cbrt(value);
}

float My::Hypot(float x, float y)
{
	return hypotf(x, y);
}
double My::Hypot(double x, double y)
{
	return hypot(x, y);
}

float My::Erf(float value)
{
	return erff(value);
}
double My::Erf(double value)
{
	return erf(value);
}

float My::Erfc(float value)
{
	return erfcf(value);
}
double My::Erfc(double value)
{
	return erfc(value);
}

float My::Tgamma(float value)
{
	return tgammaf(value);
}
double My::Tgamma(double value)
{
	return tgamma(value);
}

float My::Lgamma(float value)
{
	return lgammaf(value);
}
double My::Lgamma(double value)
{
	return lgamma(value);
}

float My::Copysing(float number, float sing)
{
	return copysignf(number, sing);
}
double My::Copysing(double number, double sing)
{
	return copysign(number, sing);
}

float My::Nanf(const char* value)
{
	return nanf(value);
}
double My::Nan(const char* value)
{
	return nan(value);
}

float My::Nextafter(float x, float y)
{
	return nextafterf(x, y);
}
double My::Nextafter(double x, double y)
{
	return nextafter(x, y);
}

float My::Nexttoward(float x, float y)
{
	return nexttowardf(x, y);
}
double My::Nexttoward(double x, double y)
{
	return nexttoward(x, y);
}

float My::Dif(float x, float y)
{
	return fdimf(x, y);
}
double My::Dif(double x, double y)
{
	return fdim(x, y);
}

float My::Max(float x, float y)
{
	return fmaxf(x, y);
}
double My::Max(double x, double y)
{
	return fmax(x, y);
}

float My::Min(float x, float y)
{
	return fminf(x, y);
}
double My::Min(double x, double y) 
{
	return fmin(x, y);
}

int My::Abs(int value)
{
	return abs(value);
}
float My::Abs(float value)
{
	return fabsf(value);
}
double My::Abs(double value)
{
	return fabs(value);
}

float My::Fma(float x, float y, float z)
{
	return fmaf(x, y, z);
}
double My::Fma(double x, double y, double z)
{
	return fma(x, y, z);
}

template<class T> bool My::IsFinite(T)
{
	return isfinite(T);
}

template<class T> bool My::IsInfinite(T)
{
	return isinf(T);
}

template<class T> bool My::IsNaN(T)
{
	return isnan(T);
}

template<class T> bool My::IsNormal(T)
{
	return isnormal(T);
}