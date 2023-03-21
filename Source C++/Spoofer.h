#pragma once
#include <iostream>
#include <windows.h>
#include <thread>

#include <d3d9.h>
#pragma comment(lib,"d3d9.lib")

#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx9.h"
#include "imgui/imgui_impl_win32.h"

#include <D3dx9tex.h>
#pragma comment(lib, "D3dx9")
#pragma comment(lib, "user32.lib")

#include "bytes/font.h"
#include "bytes/logo.hpp"

#include "encrypt/xor.h"
#include "btfile/bytetofile.hpp"


std::string imagePath = _xor_("C:\\Windows\\System32\\Speech\\a16fb36f0911f878998c136191af705e.png");

#define COLOUR(x) x/255 
#define CENTER(width) ((ImGui::GetWindowSize().x - width) * 0.5f)

bool loader_active = true;
HWND main_hwnd = nullptr;

LPDIRECT3DDEVICE9        g_pd3dDevice;
D3DPRESENT_PARAMETERS    g_d3dpp;
LPDIRECT3D9              g_pD3D;

// Load a texture from a file using the DirectX API
bool LoadTextureFromFile(const char* filename, IDirect3DTexture9** out_texture, int* out_width, int* out_height)
{
    if (!filename || !out_texture || !out_width || !out_height)
    {
        return false; // check if the input parameters are valid
    }

    HRESULT hr;

    // create a texture object from the file
    IDirect3DTexture9* texture = nullptr;
    hr = D3DXCreateTextureFromFileA(g_pd3dDevice, filename, &texture);
    if (FAILED(hr))
    {
        return false; // return false if creating texture from file failed
    }

    D3DSURFACE_DESC desc;
    // get the texture description to determine its dimensions
    hr = texture->GetLevelDesc(0, &desc);
    if (FAILED(hr))
    {
        texture->Release();
        return false; // return false if getting texture description failed
    }

    // output the texture object and dimensions
    *out_texture = texture;
    *out_width = static_cast<int>(desc.Width);
    *out_height = static_cast<int>(desc.Height);
    return true;
}

// Check if a file exists at the given path
inline bool FileExists(const std::string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0 && S_ISREG(buffer.st_mode));
    // use stat to get information about the file
    // return true if file exists and is a regular file, false otherwise
}

void SetImGuiStyle() {

    // Get the ImGui style settings
    ImGuiStyle& style = ImGui::GetStyle();

    // Set the window background color
    style.Colors[ImGuiCol_WindowBg] = ImVec4(COLOUR(22.0f), COLOUR(24.0f), COLOUR(29.0f), 1.f);

    // Set the title bar background color when the window is active
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(COLOUR(30.0f), COLOUR(31.0f), COLOUR(38.0f), 1.f);

    // Set the border color for windows and panels
    style.Colors[ImGuiCol_Border] = ImVec4(COLOUR(22.0f), COLOUR(24.0f), COLOUR(29.0f), 0.9f);

    // Set the background color for panels, combo boxes, and menus
    style.Colors[ImGuiCol_FrameBg] = ImVec4(COLOUR(50.0f), COLOUR(50.0f), COLOUR(50.0f), 1.f);

    // Set the color for buttons
    style.Colors[ImGuiCol_Button] = ImVec4(COLOUR(67.0f), COLOUR(38.0f), COLOUR(235.0f), 1.f);

    // Set the active color for headers
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(COLOUR(5.0f), COLOUR(116.0f), COLOUR(203.0f), 1.f);

    // Set the color for headers
    style.Colors[ImGuiCol_Header] = ImVec4(COLOUR(5.0f), COLOUR(116.0f), COLOUR(203.0f), 1.f);

    // Set the rounding value for windows
    style.WindowRounding = 0.0f;

    // Set the rounding value for panels and frames
    style.FrameRounding = 2.f;
}

bool CreateDeviceD3D(HWND hWnd)
{
    // Create the D3D object
    g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
    if (!g_pD3D)
    {
        OutputDebugStringA("Error: Failed to create Direct3D object");
        return false;
    }

    // Set up the present parameters
    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
    g_d3dpp.Windowed = TRUE;
    g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    g_d3dpp.EnableAutoDepthStencil = TRUE;
    g_d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
    g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
    g_d3dpp.BackBufferCount = 1;

    // Check if the device supports vsync
    HRESULT result = g_pD3D->CheckDeviceType(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, D3DFMT_X8R8G8B8, D3DFMT_X8R8G8B8, TRUE);
    if (result != D3D_OK)
    {
        OutputDebugStringA("Warning: Device does not support vsync, disabling...");
        g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
    }

    // Create the device
    result = g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice);
    if (result != D3D_OK)
    {
        OutputDebugStringA("Error: Failed to create Direct3D device");
        return false;
    }

    return true;
}


void CleanupDeviceD3D()
{
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
    if (g_pD3D) { g_pD3D->Release(); g_pD3D = NULL; }
}

void ResetDevice()
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
    if (hr == D3DERR_INVALIDCALL)
        IM_ASSERT(0);
    ImGui_ImplDX9_CreateDeviceObjects();
}
