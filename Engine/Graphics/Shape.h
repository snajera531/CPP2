#pragma once
#include "core.h"
#include "../Math/Vector2.h"
#include "../Math/Color.h"
#include "../Math/Transform.h"
#include <vector>
#include <string>

namespace sn {
	class Shape {
	public:
		Shape() {}
		Shape(const std::vector<Vector2>& points, const Color& color) : m_points{points}, m_color{color}

		bool Load(const std::string& filename);

		void Draw(Core::Graphics& graphics, Vector2 position, float scale = 1.0f, float angle = 0.0f);
		void Draw(Core::Graphics& graphics, const Transform transform);

		void setColor(Color color) { m_color = color; }
		const Color& getColor() const { return m_color; }

	private:
		std::vector<Vector2> m_points;
		Color m_color;
	};
}