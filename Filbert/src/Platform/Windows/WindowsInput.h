#pragma once
#include "Input.h"

namespace Filbert
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool _IsKeyPressed(const KeyCode& key) const override;
		virtual bool _IsMouseButtonPressed(const MouseCode& btn) const override;
		virtual Vector2<double> _GetMousePosition() const override;
	};
}
