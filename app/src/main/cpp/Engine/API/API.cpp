//
// Created by aimar on 12/28/2019.
//

#include "API.h"
#include <locale>
#include <codecvt>
#include <Logger.h>

namespace {
    const void *(*il2cpp_assembly_get_image)(const void *assembly);

    void *(*il2cpp_domain_get)();

    void **(*il2cpp_domain_get_assemblies)(const void *domain, size_t *size);

    const char *(*il2cpp_image_get_name)(void *image);

    void *(*il2cpp_class_from_name)(const void *image, const char *namespaze, const char *name);

    void *(*il2cpp_class_get_property_from_name)(void *klass, const char *name);

    void *(*il2cpp_class_get_field_from_name)(void *klass, const char *name);

    void *(*il2cpp_class_get_method_from_name)(void *klass, const char *name, int argsCount);

    void *(*il2cpp_runtime_invoke)(void* method, void* obj, void** params, void* exec);

    void *(*il2cpp_property_get_get_method)(void *prop);

    void *(*il2cpp_property_get_set_method)(void *prop);

    size_t (*il2cpp_field_get_offset)(void *field);

    void (*il2cpp_field_static_get_value)(void *field, void *value);

    void (*il2cpp_field_static_set_value)(void *field, void *value);

    void *(*il2cpp_array_new)(void *elementTypeInfo, size_t length);

    int32_t (*il2cpp_string_length)(void *str);

    char16_t *(*il2cpp_string_chars)(void *str);

    void* (*il2cpp_string_new)(const char* str);

    char *(*il2cpp_type_get_name)(void *type);

    void* (*il2cpp_method_get_param)(void *method, uint32_t index);

    void* (*il2cpp_class_get_methods)(void *klass, void* *iter);

    const char* (*il2cpp_method_get_name)(void *method);

    void *(*il2cpp_class_get_interfaces)(void *klass, void **iter);

    const char *(*il2cpp_class_get_name)(void *klass);

     void *(*il2cpp_class_from_type)(int);

    int (*il2cpp_class_get_type)(void *);

    void *(*il2cpp_class_get_parent)(void *);

    void *(*il2cpp_class_get_declaring_type)(void *);

    void *(*il2cpp_class_get_nested_types)(void *, void **);

    void *(*il2cpp_object_new)(void *);
}
// ================================================================================================================ //
void *getExportFunction(void *handle, const char *name)
{
    void *fn = dlsym(handle, name);
    if (fn) {
        return fn;
    }

    LOGI("%s: %p %s", __FUNCTION__, handle, name);
    return nullptr;
}

int init(void *handle)
{
    il2cpp_assembly_get_image = (const void *(*)(const void *)) getExportFunction(handle, "il2cpp_assembly_get_image");

    il2cpp_domain_get = (void *(*)()) getExportFunction(handle, "il2cpp_domain_get");

    il2cpp_domain_get_assemblies = (void **(*)(const void* , size_t*)) getExportFunction(handle, "il2cpp_domain_get_assemblies");

    il2cpp_image_get_name = (const char *(*)(void *)) getExportFunction(handle, "il2cpp_image_get_name");

    il2cpp_class_from_name = (void* (*)(const void*, const char*, const char *)) getExportFunction(handle, "il2cpp_class_from_name");

    il2cpp_class_get_property_from_name = (void* (*)(void *, const char *)) getExportFunction(handle, "il2cpp_class_get_property_from_name");;

    il2cpp_class_get_field_from_name = (void* (*)(void*, const char *)) getExportFunction(handle, "il2cpp_class_get_field_from_name");;

    il2cpp_class_get_method_from_name = (void* (*)(void *, const char*, int)) getExportFunction(handle, "il2cpp_class_get_method_from_name");

    il2cpp_runtime_invoke = (void *(*)(void* , void* , void** , void*)) getExportFunction(handle, "il2cpp_runtime_invoke");

    il2cpp_property_get_get_method = (void* (*)(void *)) getExportFunction(handle, "il2cpp_property_get_get_method");;

    il2cpp_property_get_set_method = (void* (*)(void *)) getExportFunction(handle, "il2cpp_property_get_set_method");;

    il2cpp_field_get_offset = (size_t (*)(void *)) getExportFunction(handle, "il2cpp_field_get_offset");;

    il2cpp_field_static_get_value = (void (*)(void*, void *)) getExportFunction(handle, "il2cpp_field_static_get_value");;

    il2cpp_field_static_set_value = (void (*)(void*, void *)) getExportFunction(handle, "il2cpp_field_static_set_value");;

    il2cpp_array_new = (void *(*)(void*, size_t)) getExportFunction(handle, "il2cpp_array_new");;

    il2cpp_string_chars = (char16_t *(*)(void*)) getExportFunction(handle, "il2cpp_string_chars");;

    il2cpp_string_length = (int32_t (*)(void*)) getExportFunction(handle, "il2cpp_string_length");;

    il2cpp_string_new = (void *(*)(const char *)) getExportFunction(handle, "il2cpp_string_new");;

    il2cpp_type_get_name = (char *(*)(void *)) getExportFunction(handle, "il2cpp_type_get_name");;

    il2cpp_method_get_param = (void *(*)(void *, uint32_t)) getExportFunction(handle, "il2cpp_method_get_param");;

    il2cpp_class_get_methods = (void *(*)(void *, void **)) getExportFunction(handle, "il2cpp_class_get_methods");;

    il2cpp_method_get_name = (const char *(*)(void *)) getExportFunction(handle, "il2cpp_method_get_name");;

    il2cpp_class_get_interfaces = (void *(*)(void *, void **)) getExportFunction(handle, "il2cpp_class_get_interfaces");;

    il2cpp_class_get_name = (const char *(*)(void *)) getExportFunction(handle, "il2cpp_class_get_name");

    il2cpp_class_from_type = (void *(*)(int)) getExportFunction(handle, "il2cpp_class_from_type");

    il2cpp_class_get_type = (int (*)(void *)) getExportFunction(handle, "il2cpp_class_get_type");

    il2cpp_class_get_parent = (void *(*)(void *)) getExportFunction(handle, "il2cpp_class_get_parent");

    il2cpp_class_get_declaring_type = (void *(*)(void *)) getExportFunction(handle, "il2cpp_class_get_declaring_type");

    il2cpp_class_get_nested_types = (void *(*)(void *, void **)) getExportFunction(handle, "il2cpp_class_get_nested_types");

    il2cpp_object_new = (void *(*)(void *)) getExportFunction(handle, "il2cpp_object_new");

    return 0;
}
// ================================================================================================================ //
int Il2Cpp::Init(const char *lib) {
    if(!lib) return -1;

    return init(dlopen(lib, 4));

}
// ================================================================================================================ //
int Il2Cpp::Init(void *handle) {
    if(!handle) return -1;

    return init(handle);

}
// ================================================================================================================ //
void *Il2Cpp::GetImageByName(const char *image) {
    size_t size;
    void **assemblies = il2cpp_domain_get_assemblies(il2cpp_domain_get(), &size);
    for(int i = 0; i < size; ++i)
    {
        void *img = (void *)il2cpp_assembly_get_image(assemblies[i]);

        const char *img_name = il2cpp_image_get_name(img);

        if(strcmp(img_name, image) == 0)
        {
            return img;
        }
    }
    return nullptr;
}
// ================================================================================================================ //
void Il2Cpp::GetStaticFieldValue(const char *image, const char *namespaze, const char *clazz, const char *name, void *output) {
    void *img = GetImageByName(image);
    if(!img) {
        LOGI("Can't find image %s!", image);
        return;
    }
    void *klass = GetClassType(image, namespaze, clazz);
    if(!klass) {
        LOGI("Can't find class %s for field %s!", clazz, name);
        return;
    }

    void *field = il2cpp_class_get_field_from_name(klass, name);
    if(!field) {
        LOGI("Can't find field %s in class %s!", name, clazz);
        return;
    }

    il2cpp_field_static_get_value(field, output);
}
// ================================================================================================================ //
void Il2Cpp::SetStaticFieldValue(const char *image, const char *namespaze, const char *clazz, const char *name, void* value) {
    void *img = GetImageByName(image);
    if(!img) {
        LOGI("Can't find image %s!", image);
        return;
    }
    void *klass = GetClassType(image, namespaze, clazz);
    if(!klass) {
        LOGI("Can't find class %s for field %s!", clazz, name);
        return;
    }

    void *field = il2cpp_class_get_field_from_name(klass, name);
    if(!field) {
        LOGI("Can't find field %s in class %s!", name, clazz);
        return;
    }

    il2cpp_field_static_set_value(field, value);
}
// ================================================================================================================ //
void *Il2Cpp::GetClassType(const char *image, const char *namespaze, const char *clazz) {
    void *img = GetImageByName(image);
    if(!img) {
        LOGI("Can't find image %s!", image);
        return nullptr;
    }

    void *klass = il2cpp_class_from_name(img, namespaze, clazz);
    if(!klass) {
        LOGI("Can't find class %s!", clazz);
        return nullptr;
    }
    return klass;
}
// ================================================================================================================ //
void *Il2Cpp::CreateClassInstance(const char *image, const char *namespaze, const char *clazz) {
    void *img = GetImageByName(image);
    if(!img) {
        LOGI("Can't find image %s!", image);
        return nullptr;
    }

    void *klass = GetClassType(image, namespaze, clazz);
    if(!klass) {
        LOGI("Can't find class %s!", clazz);
        return nullptr;
    }

    void *obj = il2cpp_object_new(klass);
    if(!obj)
    {
        LOGI("Can't create object for %s", clazz);
        return nullptr;
    }

    return obj;
}
// ================================================================================================================ //
void *Il2Cpp::GetMethodOffset(const char *image, const char *namespaze, const char *clazz, const char *name, int argsCount) {
    void *img = GetImageByName(image);
    if(!img) {
        LOGI("Can't find image %s!", image);
        return nullptr;
    }

    void *klass = GetClassType(image, namespaze, clazz);
    if(!klass) {
        LOGI("Can't find class %s for method %s!", clazz, name);
        return nullptr;
    }

    void **method = (void**)il2cpp_class_get_method_from_name(klass, name, argsCount);
    if(!method) {
        LOGI("Can't find method %s in class %s!", name, clazz);
        return nullptr;
    }

    return *method;
}
// ================================================================================================================ //
void *Il2Cpp::GetMethodOffset(const char *image, const char *namespaze, const char *clazz, const char *name, char** args, int argsCount) {
    void *img = GetImageByName(image);
    if(!img) {
        LOGI("Can't find image %s!", image);
        return nullptr;
    }

    void *klass = GetClassType(image, namespaze, clazz);
    if(!klass) {
        LOGI("Can't find class %s for method %s!", clazz, name);
        return nullptr;
    }

    void *iter = nullptr;

    int score = 0;

    void **method = (void**) il2cpp_class_get_methods(klass, &iter);
    while(method) {
        const char *fname = il2cpp_method_get_name(method);
        if(strcmp(fname, name) == 0) {
            for (int i = 0; i < argsCount; i++) {
                void *arg = il2cpp_method_get_param(method, i);
                if (arg) {
                    const char *tname = il2cpp_type_get_name(arg);
                    if (strcmp(tname, args[i]) == 0) {
                        score++;
                    } else {
                        LOGI("Argument at index %d didn't matched requested argument!\r\n\tRequested: %s\r\n\tActual: %s\r\nSkipping function...", i, args[i], tname);
                        score = 0;
                        goto skip;
                    }
                }
            }
        }
        skip:

        if(score == argsCount)
        {
            LOGI("Found matched function!");
            return *method;
        }

        method = (void **) il2cpp_class_get_methods(klass, &iter);
    }
    LOGI("Cannot find function %s in class %s!", name, clazz);
    return nullptr;
}

const char *Il2Cpp::GetMethodName(void* method){
    return il2cpp_method_get_name(method);
}

uintptr_t Il2Cpp::GetFieldOffset(void *clazz, const char *name){
    void *field = il2cpp_class_get_field_from_name(clazz, name);
    if(!field) {
        LOGI("Can't find field %s!", name);
        return -1;
    }
    return il2cpp_field_get_offset(field);
}
// ================================================================================================================ //
size_t Il2Cpp::GetFieldOffset(const char *image, const char *namespaze, const char *clazz, const char *name) {
    void *img = GetImageByName(image);
    if(!img) {
        LOGI("Can't find image %s!", image);
        return -1;
    }
    void *klass = GetClassType(image, namespaze, clazz);
    if(!klass) {
        LOGI("Can't find class %s for field %s!", clazz, name);
        return -1;
    }

    void *field = il2cpp_class_get_field_from_name(klass, name);
    if(!field) {
        LOGI("Can't find field %s in class %s!", name, clazz);
        return -1;
    }
    return il2cpp_field_get_offset(field);
}
// ================================================================================================================ //
bool Il2Cpp::IsAssembliesLoaded() {
    size_t size;
    void **assemblies = il2cpp_domain_get_assemblies(il2cpp_domain_get(), &size);

    return size != 0 && assemblies != nullptr;
}
// ================================================================================================================ //
void* Il2Cpp::CreateArray(const char *image, const char *namespaze, const char *clazz, size_t length) {
    void *img = GetImageByName(image);
    if(!img) {
        LOGI("Can't find image %s!", image);
        return nullptr;
    }
    void *klass = GetClassType(image, namespaze, clazz);
    if(!klass) {
        LOGI("Can't find class %s!", clazz);
        return nullptr;
    }

    return il2cpp_array_new(klass, length);
}
// ================================================================================================================ //

std::string Il2Cpp::GetString(void *string) {
    if (string) {
        std::u16string str = il2cpp_string_chars(string);
        std::wstring wide_string(str.begin(), str.end());
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
        return convert.to_bytes(wide_string);
    }
    return "Object NULL!";
}