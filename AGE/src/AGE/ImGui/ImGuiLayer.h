#pragma once


#include "AGE/Layer.h"

#include "AGE/Events/ApplicationEvent.h"
#include "AGE/Events/KeyEvent.h"
#include "AGE/Events/MouseEvent.h"


namespace AGE
{
	class AGE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}