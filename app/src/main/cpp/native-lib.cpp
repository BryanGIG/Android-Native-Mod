#include <jni.h>
#include <string>
#include "Engine/Includes.hpp"

__attribute__ ((constructor))
void lib_main() {
    ProcMap map;
    do {
        map = KittyMemory::getElfBaseMap("libil2cpp.so");
    } while (!map.isValid() && !map.isValidELF());

    // Initialize the classes
    ListCBaseEntry::add({
        new CheatDetector()
    });
    ListCBaseEntry::Initialize();
}