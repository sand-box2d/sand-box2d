/**
 * @brief SDL2 Implementation of the Dear ImGui Manager.
 * 
 * This implementation works with SDL2 window and its renderer.
 * 
 * It might not work on PS Vita. If it doesn't,
 * create a new implementation named `sdl2-vita`.
 */

#include "../imgui-manager.hpp"

#include "../../../lib/imgui/backends/imgui_impl_sdl2.h"
#include "../../../lib/imgui/backends/imgui_impl_sdlrenderer2.h"

ImGuiManager::ImGuiManager(Renderer &r_renderer) {}
ImGuiManager::~ImGuiManager() {}
