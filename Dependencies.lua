-- Crypt Dependencies

VULKAN_SDK = os.getenv("VULKAN_SDK")
IncludeDir = {}
IncludeDir["stb_image"] = "%{wks.location}/Crypt/vendor/stb_image"
IncludeDir["yaml_cpp"] = "%{wks.location}/Crypt/vendor/yaml-cpp/include"
IncludeDir["Box2D"] = "%{wks.location}/Crypt/vendor/Box2D/include"
IncludeDir["GLFW"] = "%{wks.location}/Crypt/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Crypt/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Crypt/vendor/ImGui"
IncludeDir["ImGuizmo"] = "%{wks.location}/Crypt/vendor/ImGuizmo"
IncludeDir["glm"] = "%{wks.location}/Crypt/vendor/glm"
IncludeDir["entt"] = "%{wks.location}/Crypt/vendor/entt/include"
IncludeDir["shaderc"] = "%{wks.location}/Crypt/vendor/shaderc/include"
IncludeDir["SPIRV_Cross"] = "%{wks.location}/Crypt/vendor/SPIRV-Cross"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

LibraryDir = {}

LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"
LibraryDir["VulkanSDK_Debug"] = "%{wks.location}/Crypt/vendor/VulkanSDK/Lib"

Library = {}
Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Library["VulkanUtils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"

Library["ShaderC_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/shaderc_sharedd.lib"
Library["SPIRV_Cross_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/spirv-cross-cored.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/spirv-cross-glsld.lib"
Library["SPIRV_Tools_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/SPIRV-Toolsd.lib"

Library["ShaderC_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_shared.lib"
Library["SPIRV_Cross_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsl.lib"