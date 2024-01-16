#include "../globals.hh"
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"
#include "iostream"
#include <windows.h>
#include "fstream"
#include "cstdio"
#include <TlHelp32.h>
#include "../auth/auth.hpp"
#include "voids.h"


auto name = (" "); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
auto ownerid = (" "); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
auto secret = (" "); // app secret, the blurred text on licenses tab and other tabs
auto version = ("1.0"); // leave alone unless you've changed version on website
auto url = ("https://keyauth.win/api/1.2/"); // change if you're self-hosting

KeyAuth::api KeyAuthApp(name, ownerid, secret, version, url);
bool Login(std::string user, std::string senha) {
    KeyAuthApp.init();
    KeyAuthApp.login(user, senha);
    if (KeyAuthApp.data.success) {
        return true;
    }
    else {
        return false;
    }
    

}

bool Register(std::string user, std::string pass, std::string key) {
    KeyAuthApp.init();
    KeyAuthApp.regstr(user, pass, key);
    if (KeyAuthApp.data.success) {
        return true;
    }
    else {
        globals.registerStatus = KeyAuthApp.data.message;
        return false;
    }
}

void setCursorPosCentered(std::string text) {
    auto windowWidth = ImGui::GetWindowSize().x;
    auto textWidth = ImGui::CalcTextSize(text.c_str()).x;

    ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
}

void showUserData() {
    TextCentered("username: " + KeyAuthApp.data.username, 255, 255, 255, 1);
    TextCentered("ip: " + KeyAuthApp.data.ip, 255, 255, 255, 1);
    TextCentered("hwid: " + KeyAuthApp.data.hwid, 255, 255, 255, 1);
}

void visibilidade() {
    globals.showLogin = false;
    globals.showAccInfo = false;
    globals.showMenu = false;
    globals.showRegister = false;
}

void TextCentered(std::string text, float r,float g, float b, float a) {
    auto windowWidth = ImGui::GetWindowSize().x;
    auto textWidth = ImGui::CalcTextSize(text.c_str()).x;

    ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
    ImGui::TextColored(ImVec4(r,g,b,a), text.c_str());
}



void MyComboBox(const char* label, const char* items[], int itemCount, int& currentItem) {
    if (ImGui::BeginCombo(label, items[currentItem])) {
        for (int i = 0; i < itemCount; i++) {
            const bool isSelected = (currentItem == i);
            if (ImGui::Selectable(items[i], isSelected))
                currentItem = i;

            if (isSelected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
    }
}


void mbox(LPCSTR text) {
    MessageBoxA(NULL, text, "pollo", MB_OK);
}
