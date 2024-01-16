#include "ui.hh"
#include "../globals.hh"
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"
#include "iostream"
#include <fstream>
#include "../vendor/voids.h"
#include "../auth/auth.hpp"

KeyAuth::api init();

void ui::render() {


    if (!globals.active) return;

    ImGui::SetNextWindowPos(ImVec2(window_pos.x, window_pos.y), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(window_size.x, window_size.y));
    ImGui::SetNextWindowBgAlpha(1.0f);
   
    if (globals.showLogin) 
    {
        ImGui::Begin(window_title, &globals.active, window_flags);
        {
            ImGui::SetCursorPos(ImVec2(70, 50));
            ImGui::InputText("", globals.user_name, IM_ARRAYSIZE(globals.user_name));

            ImGui::SetCursorPos(ImVec2(70, 72));
            ImGui::InputText(" ", globals.pass_word, IM_ARRAYSIZE(globals.pass_word), ImGuiInputTextFlags_Password);

            ImGui::SetCursorPos(ImVec2(172, 110));
            if (ImGui::Button("Login")) {
                if (Login(globals.user_name,globals.pass_word)) {
                    visibilidade();
                    globals.showMenu = true;
                }

            }

            ImGui::SetCursorPos(ImVec2(162.5f, 135));
            if (ImGui::Button("register")) {
                visibilidade();
                globals.showRegister = true;
            }
        }
        ImGui::End();

    }

    if (globals.showRegister) {
        ImGui::Begin(window_title, &globals.active, window_flags);
        {

            ImGui::SetCursorPos(ImVec2(70, 50));
            ImGui::InputText("", globals.user_name, IM_ARRAYSIZE(globals.user_name));

            ImGui::SetCursorPos(ImVec2(70, 72));
            ImGui::InputText(" ", globals.pass_word, IM_ARRAYSIZE(globals.pass_word), ImGuiInputTextFlags_Password);

            ImGui::SetCursorPos(ImVec2(70, 94));
            ImGui::InputText("  ", globals.key, IM_ARRAYSIZE(globals.key));

            ImGui::SetCursorPos(ImVec2(162.5f, 135));
            if (ImGui::Button("register")) {
               
                if (Register(globals.user_name,globals.pass_word,globals.key)) {
                    globals.registerStatus = "sucefully registered!";                 
                }
               
            }

            TextCentered(globals.registerStatus,255,255,255,1);

            ImGui::SetCursorPos(ImVec2(138, 177));
            if (ImGui::Button("return to login")) {
                visibilidade();
                globals.showLogin = true;
            }

        }
        ImGui::End();

    }
    
    
    if (globals.showMenu) {
        ImGui::Begin(window_title, &globals.active, window_flags);
        {
           

            if (ImGui::Button("account info")) {
                visibilidade();
                globals.showAccInfo = true;

            }
           

            
        }
        ImGui::End();

    }

    if (globals.showAccInfo) {
        ImGui::Begin(window_title, &globals.active, window_flags);
        {

            showUserData();
            setCursorPosCentered("back ");
            if (ImGui::Button("back")) {
                visibilidade();
                globals.showMenu = true;
            }

        }
        ImGui::End();

    }
    

    
}



void ui::init(LPDIRECT3DDEVICE9 device) {
    dev = device;
	
    // colors
    ImGui::StyleColorsDark();

	if (window_pos.x == 0) {
		RECT screen_rect{};
		GetWindowRect(GetDesktopWindow(), &screen_rect);
		screen_res = ImVec2(float(screen_rect.right), float(screen_rect.bottom));
		window_pos = (screen_res - window_size) * 0.5f;

		// init images here
	}
}