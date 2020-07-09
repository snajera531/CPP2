#pragma once
#include <windows.h>

namespace sn {
	struct Color {
		float r, g, b;

		Color() : r{0}, g{0}, b{0} {}
		Color(float r, float g, float b) : r{r}, g{g}, b{b}{}

		float& operator [] (size_t index) { return (&r)[index]; }
		//const float& operator [] (size_t index) { return (&r)[index]; }

		void Set(float r, float g, float b) { this->r = r; this->g = g; this->b = b; }

		Color operator + (const Color& c) const{ return Color{ r + c.r, g + c.g, b + c.b };}
		Color operator - (const Color& c) const{ return Color{ r - c.r, g - c.g, b - c.b }; }
		Color operator * (const Color& c) const{ return Color{ r * c.r, g * c.g, b * c.b }; }
		Color operator / (const Color& c) const{ return Color{ r / c.r, g / c.g, b / c.b }; }

		Color operator + (float s) const{ return Color{ r + s, g + s, b + s }; }
		Color operator - (float s) const{ return Color{ r - s, g - s, b - s }; }
		Color operator * (float s) const{ return Color{ r * s, g * s, b * s }; }
		Color operator / (float s) const{ return Color{ r / s, g / s, b / s }; }

		Color& operator += (const Color& c){ r += c.r; g += c.g; b += c.b; return *this; }
		Color& operator -= (const Color& c){ r -= c.r; g -= c.g; b -= c.b; return *this; }
		Color& operator *= (const Color& c){ r *= c.r; g *= c.g; b *= c.b; return *this; }
		Color& operator /= (const Color& c){ r /= c.r; g /= c.g; b /= c.b; return *this; }

		Color& operator += (float s){ r += s; g += s; b += s; return *this; }
		Color& operator -= (float s){ r -= s; g -= s; b -= s; return *this; }
		Color& operator *= (float s){ r *= s; g *= s; b *= s; return *this; }
		Color& operator /= (float s){ r /= s; g /= s; b /= s; return *this; }

		friend std::istream& operator >> (std::istream& stream, Color& c);

		operator COLORREF() const {
			BYTE _r = static_cast<BYTE>(r * 255.0f);
			BYTE _g = static_cast<BYTE>(g * 255.0f);
			BYTE _b = static_cast<BYTE>(b * 255.0f);

			return RGB(_r, _g, _b);
		}

	};