#include "pch.h"
#include "Shape.h"
#include "Math/Transform.h"

void sn::Shape::Draw(Core::Graphics& graphics, sn::Vector2 position, float scale, float angle)
{
	graphics.SetColor(m_color);

	for (size_t i = 0; i < m_points.size() - 1; i++) {
		Vector2 p1 = m_points[i];
		Vector2 p2 = m_points[i + 1];

		p1 += scale;
		p2 += scale;
		p1 = Vector2::rotate(p1, angle);
		p2 = Vector2::rotate(p2, angle);
		p1 += position;
		p2 += position;

		graphics.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
}

void sn::Shape::Draw(Core::Graphics& graphics, const Transform transform)
{
	Draw(graphics, transform.position, transform.scale, transform.angle)
}
