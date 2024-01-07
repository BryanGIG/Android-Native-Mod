#include "CBaseEntry.hpp"

/*
 * This file is just sample, you can modify this
 */
class CheatDetector : public CBaseEntry {
public:
    const char *getAssembly() override;

    const char *getNamespace() override;

    const char *getClass() override;

    void Initialize() override;

    void Hook() override;
};
