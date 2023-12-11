#include <Crypt.h>
#include <Crypt/Core/EntryPoint.h>

#include "Crypt-IDLayer.h"

namespace Crypt {


	class CryptID : public Application
	{
	public:
		CryptID()
			: Application("CryptID")
		{
			PushLayer(new CryptIDLayer());
		}

		~CryptID()
		{
		}
	};

	Application* CreateApplication()
	{
		return new CryptID();
	}
}