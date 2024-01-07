#pragma once

#include <vector>
#include <mutex>
#include <memory>

class CBaseEntry {
public:
    virtual const char *getAssembly() = 0;
    virtual const char *getNamespace() = 0;
    virtual const char *getClass() = 0;
    virtual void Initialize() = 0;

    // TODO: Add this to the game loop
    virtual void Update() {};

    // Define all necessary hooks here
    virtual void Hook() = 0;

    virtual ~CBaseEntry() = default;
};

namespace ListCBaseEntry {
    void add(const std::vector<CBaseEntry *>& entry);

    void add(const std::shared_ptr<CBaseEntry>& entry);

    void remove(const std::shared_ptr<CBaseEntry>& entry);

    template<class T>
    std::shared_ptr<T> get();

    std::vector<std::shared_ptr<CBaseEntry>> getList();

    void Initialize();
};