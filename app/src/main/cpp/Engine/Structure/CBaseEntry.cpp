#include "CBaseEntry.hpp"

std::mutex listMutex;
std::vector<std::shared_ptr<CBaseEntry>> list;

template<class T>
std::shared_ptr<T> ListCBaseEntry::get() {
    std::lock_guard<std::mutex> guard(listMutex);
    for (auto &entry : list) {
        if (dynamic_cast<T *>(entry)) {
            return std::static_pointer_cast<T>(entry);
        }
    }
    return nullptr;
}

void ListCBaseEntry::add(const std::vector<CBaseEntry *>& entry) {
    std::lock_guard<std::mutex> guard(listMutex);
    for (auto &e : entry) {
        add(std::shared_ptr<CBaseEntry>(e));
    }
}

void ListCBaseEntry::add(const std::shared_ptr<CBaseEntry>& entry)  {
    std::lock_guard<std::mutex> guard(listMutex);
    list.push_back(entry);
}

void ListCBaseEntry::remove(const std::shared_ptr<CBaseEntry>& entry) {
    std::lock_guard<std::mutex> guard(listMutex);
    auto it = std::find(list.begin(), list.end(), entry);
    if (it != list.end()) {
        list.erase(it);
    }
}

std::vector<std::shared_ptr<CBaseEntry>> ListCBaseEntry::getList() {
    std::lock_guard<std::mutex> guard(listMutex);
    return list;  // This makes a copy of the list
}

void ListCBaseEntry::Initialize() {
    std::lock_guard<std::mutex> guard(listMutex);
    for (auto &entry : list) {
        entry->Initialize();
        entry->Hook();
    }
}