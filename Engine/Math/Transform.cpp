#include "pch.h"
#include "Transform.h"

namespace sn {
	std::istream& sn::operator>>(std::istream& stream, Transform& transform)
	{
		stream >> transform.position;
		stream >> transform.scale;
		stream >> transform.angle;

		return stream;
	}
}

