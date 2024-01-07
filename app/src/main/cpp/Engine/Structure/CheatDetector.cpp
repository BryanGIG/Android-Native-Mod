#include "../Includes.hpp"

bool (*AreStatsValid)(CheatDetector *, void *) = nullptr;

bool new_AreStatsValid(CheatDetector *self, void *a2) {
    return true;
}

void CheatDetector::Initialize() {
    setPointer(AreStatsValid, "AreStatsValid", 1);
}

void CheatDetector::Hook() {
    setHook(AreStatsValid, "AreStatsValid");
}

const char *CheatDetector::getAssembly() {
    return "Assembly-CSharp.dll";
}

const char *CheatDetector::getNamespace() {
    return "";
}

const char *CheatDetector::getClass() {
    return "CheatDetector";
}