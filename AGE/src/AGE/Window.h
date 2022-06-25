#pragma once

#include "AGEpch.h"

#include "AGE/Core.h"
#include "AGE/Events/Event.h"

namespace AGE
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Apologue Game Engine",
					unsigned int width = 1280,
					unsigned int height = 720)
					:Title(title),Width(width),Height(height) 
		{
		}
	};

	//Interface reprecenting a desktop system based window

	class AGE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;
		
		virtual unsigned int GetWidth() const  = 0;
		virtual unsigned int GetHeight() const = 0;

		//window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

	};



}