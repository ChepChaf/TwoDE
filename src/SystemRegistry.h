#pragma once

#include <unordered_map>
#include <typeindex>
#include <memory>
#include "ISystem.h"

namespace TwoDE
{
    class SystemRegistry
    {
        std::unordered_map<std::type_index, std::shared_ptr<ISystem>> activeSystems;
    public:
        const std::unordered_map<std::type_index, std::shared_ptr<ISystem>> &getActiveSystems() const;

    public:
        void init();
        template<typename T, typename ...TArgs>
        void subscribe(TArgs &&... args)
        {
            std::shared_ptr<T> system = std::make_shared<T>(std::forward<TArgs>(args)...);
            activeSystems.insert(std::make_pair(std::type_index(typeid(T)), system));
        }

        template<typename T>
        void unsubscribe()
        {
            auto system = activeSystems.find(std::type_index(typeid(T)));
            activeSystems.erase(system);
        }
    };
}