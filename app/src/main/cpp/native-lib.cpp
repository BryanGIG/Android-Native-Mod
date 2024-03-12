#include <jni.h>
#include <string>
#include <thread>
#include "Engine/Includes.hpp"

__attribute__ ((constructor))
void lib_main() {
    std::thread([]() {
        ProcMap map;
        do {
            map = KittyMemory::getElfBaseMap("libil2cpp.so");
            sleep(1);
        } while (!map.isValid() && !map.isValidELF());

        if (Il2Cpp::Init("libil2cpp.so") == -1) {
            LOGE("Il2Cpp::Init Failed!");
            return;
        }

        // Initialize the classes
        ListCBaseEntry::add(std::make_shared<ExampleEntry>());
        ListCBaseEntry::Initialize();
    }).detach();
}
