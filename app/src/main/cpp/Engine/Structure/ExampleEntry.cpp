#include "../Includes.hpp"

bool (*AreStatsValid)(ExampleEntry *, void *) = nullptr;

bool new_AreStatsValid(ExampleEntry *self, void *a2) {
    return true;
}

void ExampleEntry::Initialize() {
    setPointer(AreStatsValid, "AreStatsValid", 1);
}

void ExampleEntry::Hook() {
    setHook(AreStatsValid, "AreStatsValid");
}

const char *ExampleEntry::getAssembly() {
    return "Assembly-CSharp.dll";
}

const char *ExampleEntry::getNamespace() {
    return "";
}

const char *ExampleEntry::getClass() {
    return "ExampleEntry";
}