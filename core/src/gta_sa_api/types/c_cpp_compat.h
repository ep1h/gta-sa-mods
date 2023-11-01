/**
 * @file c_cpp_compat.h
 * @brief Macros to facilitate interoperability between C and C++ in varying
 * compiler environments.
 */
#ifndef C_CPP_COMPAT_H_
#define C_CPP_COMPAT_H_

#if defined(_MSC_VER)
#define CC_CDECL     __cdecl
#define CC_STDCALL   __stdcall
#define CC_FASTCALL  __fastcall
#define CC_THISCALL  __fastcall
#define TYPES_UNALIGNED __unaligned
#define TYPES_ALIGNAS(x)  __declspec(align(x))

#elif defined(__GNUC__) || defined(__clang__)
#define CC_CDECL     __attribute__((cdecl))
#define CC_STDCALL   __attribute__((stdcall))
#define CC_FASTCALL  __attribute__((fastcall))
#define CC_THISCALL  __attribute__((fastcall))
#define TYPES_UNALIGNED __attribute__((packed))
#define TYPES_ALIGNAS(x)  __attribute__((aligned(x)))
#endif /* _MSC_VER */

// TODO: Use alignas() if __cplusplus >= 201103L
// TODO: Use _Alignas() if __STDC_VERSION__ >= 201112L

#endif /* C_CPP_COMPAT_H_ */
