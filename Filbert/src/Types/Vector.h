#pragma once

namespace Filbert
{
	template<typename T>
	class FLB_API Vector2
	{
	public:
		T X, Y;
	public:
		Vector2() {}
		Vector2(const T& x, const T& y) : X(x), Y(y) {}
		~Vector2() {}
	};

	template<typename T>
	class FLB_API Vector3
	{
	public:
		T X, Y, Z;
	public:
		Vector3() {}
		Vector3(const T& x, const T& y, const T& z) : X(x), Y(y), Z(z) {}
		~Vector3() {}
	};
}
