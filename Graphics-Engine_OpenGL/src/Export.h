#ifndef EXPORT_H
#define EXPORT_H

#ifdef ENGINE_EXPORT
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllexport)
#endif

#endif // !EXPORT_H
