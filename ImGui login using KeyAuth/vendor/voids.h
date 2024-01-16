#pragma once
#include "../globals.hh"
#include "../globals.hh"
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"
#include "iostream"

void TextCentered(std::string text, float r, float g, float b, float a);
void mbox(std::string text);
void MyComboBox(const char* label, const char* items[], int itemCount, int& currentItem);
bool Login(std::string user, std::string senha);
void visibilidade();
void showUserData();
void setCursorPosCentered(std::string text);
bool Register(std::string user, std::string pass, std::string key);