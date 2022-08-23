#pragma once

#include "AGEpch.h"

#include "AGE/Core/Base.h"
#include "AGE/Events/Event.h"

namespace AGE
{
	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& title = "Apologue Game Engine",
					uint32_t width = 1600,
					uint32_t height = 900)
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
		
		virtual uint32_t GetWidth() const  = 0;
		virtual uint32_t GetHeight() const = 0;

		//window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Scope<Window> Create(const WindowProps& props = WindowProps());

	};



}