#pragma once

/*
 * macro definitions
 */

#define getFieldOffset(method) Il2Cpp::GetFieldOffset(getAssembly(), getNamespace(), getClass(), method)
#define getMethodOffset(method, param) (uintptr_t) Il2Cpp::GetMethodOffset(getAssembly(), getNamespace(), getClass(), method, param)
#define getFieldStaticVal(method, out) Il2Cpp::GetStaticFieldValue(getAssembly(), getNamespace(), getClass(),method,out)
#define setPointer(func, method, param) func = Il2Cpp::GetMethod<decltype(func)>(getAssembly(), getNamespace(), getClass(), method, param)
#define setHook(func, func_name)                                                                                                       \
        if (func != nullptr)                                                                                                           \
            DobbyHook((void *) func, reinterpret_cast<dobby_dummy_func_t>(new_##func), reinterpret_cast<dobby_dummy_func_t *>(&func)); \
        else                                                                                                                           \
            LOGE("Failed to hook %s", func_name);                                                                                      \
                                                                                                                                       \
/*
 * API define
 */

#include "Logger.h"
#include "API/Unity.h"
#include "KittyMemory/KittyInclude.hpp"
#include <dobby.h>

/*
 * Early class define so it can be used for other classes
 */
class CheatDetector;

/*
 * Include our structure classes
 */
#include "Structure/CheatDetector.hpp"