#include <Crypt.h>
#include <Crypt/Core/EntryPoint.h>

#include "Crypt-IDLayer.h"

namespace Crypt {


	class CryptID : public Application
	{
	public:
		CryptID(ApplicationCommandLineArgs args)
			: Application("CryptID", args)
		{
			PushLayer(new CryptIDLayer());
		}

		~CryptID()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new CryptID(args);
	}
}
