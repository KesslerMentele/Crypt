#pragma once
#include <filesystem>

#include "Crypt/Renderer/Texture.h"

namespace Crypt {

	class ContentBrowserPanel
	{
	public:
		ContentBrowserPanel();

		void OnImGuiRender();


	private:
		std::filesystem::path m_CurrentDirectory;

		Ref<Texture2D> m_DirectoryIcon;
		Ref<Texture2D> m_FileIcon;

	};
}
