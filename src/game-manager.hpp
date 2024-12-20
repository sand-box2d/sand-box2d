/// @brief This provides a declaration of the main class of the game, `GameManager`.

#pragma once

#include <string>

#include "platform/renderer/renderer.hpp"
#include "platform/controls/controls.hpp"
#include "platform/imgui-manager/imgui-manager.hpp"

#include "system/scene-manager.hpp"
#include "system/settings.hpp"

/**
 * @brief GameManager is the principal class of the game. It manages all.
 * 
 * It is responsible for creating, storaging and linking up everything.
 * 
 * When created, GM sets everything up but does nothing.
 * In order to tell it to "run the game", call `step()` and then `render()` in the loop
 * (e.g. `while (gm.step()) {gm.render();}`).
 */
class GameManager
{
public:
    /// @brief Init all the game systems.
    /// @param pathToSettings path to the JSON where user settings are stored.
    /// If doesn't exist - it'll create it. If leave empty, settings affect only the current session.
    /// @param pathToDefSettings path to the JSON where default settings are stored.
    /// If leave empty, all default settings will be considered as 0.
    GameManager(std::string pathToSettings = "", std::string pathToDefSettings = "");
    ~GameManager();

    /// @brief Make a logical step of the game.
    ///
    /// It will update all the game global parameters
    /// and tell SceneManager to update the scene.
    /// For more info refer to `system/scene-manager.hpp`.
    /// @return False when game has to be closed now.
    bool step();

    /// @brief Render current scene.
    void render();

private:
    /// @brief Settings (manager) of the game.
    ///
    /// This object lets us save some parameters
    /// and define their default values for different platforms.
    Settings m_Settings;

    /// @brief Renderer of the game.
    ///
    /// Renderer is a class which represents basic renderer functions.
    /// To know more about it, see class `Renderer`.
    Renderer m_Renderer;

    /// @brief Object providing state of the currently pressed buttons.
    Controls m_Controls;

    /// @brief Object providing state of the buttons pressed in the previous frame.
    Controls m_OldControls;

    /// @brief Object allowing us to work with the Dear ImGui.
    ImGuiManager m_ImGuiManager;

    /// @brief Object allowing us to work with all the game scenes.
    SceneManager m_SceneManager;
};
