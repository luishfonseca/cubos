/// @dir
/// @brief @ref world-inspector-tool-plugin plugin directory.

/// @file
/// @brief Plugin entry point.
/// @ingroup world-inspector-tool-plugin

#pragma once

#include <cubos/engine/cubos.hpp>

namespace cubos::engine::tools
{
    /// @defgroup world-inspector-tool-plugin World inspector
    /// @ingroup tool-plugins
    /// @brief Shows all of the entities in the world through a ImGui window, and allows selecting
    /// them.
    ///
    /// @note Selected entities are identified by the @ref EntitySelector resource.
    ///
    /// ## Dependencies
    /// - @ref imgui-plugin
    /// - @ref entity-selector-tool-plugin

    /// @brief Plugin entry function.
    /// @param cubos @b CUBOS. main class
    /// @ingroup world-inspector-tool-plugin
    void worldInspectorPlugin(Cubos& cubos);
} // namespace cubos::engine::tools