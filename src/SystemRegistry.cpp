#include "SystemRegistry.h"

#include "Systems/ISystem.h"

namespace TwoDE
{
    void SystemRegistry::init()
    {
        activeSystems.clear();
    }

    const std::unordered_map<std::type_index, std::shared_ptr<ISystem>> &SystemRegistry::getActiveSystems() const
    {
        return activeSystems;
    }
}