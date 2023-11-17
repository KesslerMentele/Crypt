#pragma once

namespace Crypt {
	class Timestep
	{
	public:
		Timestep(float time)
			: m_Time(time)
		{

		}

		operator float() const { return m_Time; }

		float GetSeconds() const {	return m_Time; }
		float GetMiliseconds() const { return m_Time * 1000; }


	private:
		float m_Time;
	};
}