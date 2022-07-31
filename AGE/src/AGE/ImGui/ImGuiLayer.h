#pragma once


#include "AGE/Core/Layer.h"

#include "AGE/Events/ApplicationEvent.h"
#include "AGE/Events/KeyEvent.h"
#include "AGE/Events/MouseEvent.h"


namespace AGE
{
	class AGE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;
		

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};
}