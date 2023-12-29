#include "crypch.h"
#include "Crypt/ImGui/ImGuiLayer.h"

#include <imgui.h>

#include <examples/imgui_impl_glfw.h>
#include <examples/imgui_impl_opengl3.h>

#include "Crypt/Core/Application.h"

// Temporary
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Crypt {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{

	}

	void ImGuiLayer::OnAttach()
	{
		CRY_PROFILE_FUNCTION();
		
		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;
		
		io.Fonts->AddFontFromFileTTF("assets/fonts/JetBrainsMono-2.304/fonts/ttf/JetBrainsMono-Bold.ttf", 18.0f);
		io.FontDefault = io.Fonts->AddFontFromFileTTF("assets/fonts/JetBrainsMono-2.304/fonts/ttf/JetBrainsMono-Regular.ttf", 18.0f);
		
		// Setup Dear Gui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsClassic();

		// when viewports are enabled we tweak WindowRounding so platform windows can look identical
		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		SetDarkThemeColors();

		Application& app = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

		// Setup platfor/renderer bindings

		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 300 es");
	}

	void ImGuiLayer::OnDetach()
	{
		CRY_PROFILE_FUNCTION();
		
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::OnEvent(Event& e)
	{
		if (m_BlockEvents)
		{
			ImGuiIO& io = ImGui::GetIO();
			e.Handled |= e.IsInCategory(EventCategoryMouse) & io.WantCaptureMouse;
			e.Handled |= e.IsInCategory(EventCategoryKeyboard) & io.WantCaptureKeyboard;
		}
	}

	void ImGuiLayer::Begin()
	{
		CRY_PROFILE_FUNCTION();
		
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLayer::End()
	{
		CRY_PROFILE_FUNCTION();
		
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());

		// Rendering 
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}

	void ImGuiLayer::SetDarkThemeColors()
	{
		auto& colors = ImGui::GetStyle().Colors;

		ImVec4 bg = { 0.086f, 0.086f, 0.118f, 1.0f };
		ImVec4 bgLight = { 0.102f, 0.106f, 0.149f, 1.0f };
		ImVec4 header = { 0.161f, 0.18f, 0.259f, 1.0f};
		ImVec4 headerLight = { 0.337f, 0.373f, 0.537f, 1.0f};
		ImVec4 accent1 = { 0.467f, 0.62f, 0.941f, 1.0f};
		ImVec4 accent2 = { 1.0f, 0.459f, 0.498f, 1.0f};		// Unused
		ImVec4 accent3 = { 0.878f, 0.686f, 0.408f, 1.0f};	// Unused
		ImVec4 accent4 = { 0.651f,0.871f,1.0f, 1.0f};		// Unused

		// Headers
		colors[ImGuiCol_Header] = header;
		colors[ImGuiCol_HeaderHovered] = headerLight;
		colors[ImGuiCol_HeaderActive] = bg;

		// Buttons
		colors[ImGuiCol_Button] = header;
		colors[ImGuiCol_ButtonHovered] = headerLight;
		colors[ImGuiCol_ButtonActive] = bg;

		// Frames
		colors[ImGuiCol_FrameBg] = header;
		colors[ImGuiCol_FrameBgHovered] = headerLight;
		colors[ImGuiCol_FrameBgActive] = bg;

		// Tabs
		colors[ImGuiCol_Tab] = bg;
		colors[ImGuiCol_TabHovered] = bgLight;
		colors[ImGuiCol_TabActive] = headerLight;
		colors[ImGuiCol_TabUnfocused] = bg;
		colors[ImGuiCol_TabUnfocusedActive] = header;

		// Title
		colors[ImGuiCol_TitleBg] = bg;
		colors[ImGuiCol_TitleBgActive] = bg;
		colors[ImGuiCol_TitleBgCollapsed] = headerLight;

		colors[ImGuiCol_Text] = accent4;
	}



}
