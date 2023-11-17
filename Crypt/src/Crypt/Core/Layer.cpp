#include "crypch.h"
#include "Crypt/Core/Layer.h"


namespace Crypt {

	Layer::Layer(const std::string& debugName)
		: m_DebugName(debugName)
	{
	}

	Layer::~Layer()
	{
	}

}