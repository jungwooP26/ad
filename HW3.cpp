#include "HW3.h"

// Implementation of VertexBuffer

// TODO: Define every member function of VertexBuffer here


// Implementation of FaceBuffer

// TODO: Define every member function of FaceBuffer here


// Implementation of Vector3

Vector3::Vector3()
{
	v[0] = v[1] = v[2] = 0.0f;
}

Vector3::Vector3(const Vector4& vec)
{
	if (vec.w() != 0.0f)
	{
		v[0] = vec.x() / vec.w();
		v[1] = vec.y() / vec.w();
		v[2] = vec.z() / vec.w();
	}
	else
	{
		v[0] = vec.x();
		v[1] = vec.y();
		v[2] = vec.z();
	}
}

Vector3::Vector3(float x, float y, float z)
{
	// TODO: Implement here
}

Vector3::Vector3(float v[3])
{
	// TODO: Implement here
}


// Implementation of Vector4

Vector4::Vector4()
{
	v[0] = v[1] = v[2] = v[3] = 0.0f;
}

Vector4::Vector4(const Vector3& vec)
{
	v[0] = vec.x();
	v[1] = vec.y();
	v[2] = vec.z();
	v[3] = 0.0;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	// TODO: Implement here
}

Vector4::Vector4(float v[4])
{
	// TODO: Implement here
}


// Implementation of Matrix4x4

Matrix4x4::Matrix4x4()
{
}

Matrix4x4::Matrix4x4(float _00, float _01, float _02, float _03,
	float _10, float _11, float _12, float _13,
	float _20, float _21, float _22, float _23,
	float _30, float _31, float _32, float _33)
{
	rows[0] = Vector4(_00, _01, _02, _03);
	rows[1] = Vector4(_10, _11, _12, _13);
	rows[2] = Vector4(_20, _21, _22, _23);
	rows[3] = Vector4(_30, _31, _32, _33);
}

Matrix4x4::Matrix4x4(const Vector4& row0, const Vector4& row1, const Vector4& row2, const Vector4& row3)
{
	rows[0] = row0;
	rows[1] = row1;
	rows[2] = row2;
	rows[3] = row3;
}

Matrix4x4::Matrix4x4(float m[16])
{
	for (int r = 0; r < 4; r++)
	{
		rows[r] = Vector4(m[r * 4 + 0], m[r * 4 + 1], m[r * 4 + 2], m[r * 4 + 3]);
	}
}


// Implementation of Vector3 operations

std::ostream& operator<<(std::ostream& os, const Vector3& v)
{
	os << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
	return os;
}

Vector3 operator+(const Vector3& v1, const Vector3& v2)
{
	// TODO: Implement here
}

Vector3 operator-(const Vector3& v1, const Vector3& v2)
{
	// TODO: Implement here
}

Vector3 operator*(float k, const Vector3& v)
{
	// TODO: Implement here
}

Vector3 operator*(const Vector3& v, float k)
{
	return Vector3(k * v.x(), k * v.y(), k * v.z());
}

Vector3 operator/(const Vector3& v, float k)
{
	if (k == 0.0f)
	{
		return v;
	}
	else
	{
		return Vector3(v.x() / k, v.y() / k, v.z() / k);
	}
}

Vector3 operator^(const Vector3& v1, const Vector3& v2)
{
	// TODO: Implement here
}

float operator%(const Vector3& v1, const Vector3& v2)
{
	// TODO: Implement here
}


// Implementation of Vector4 operations

std::ostream& operator<<(std::ostream& os, const Vector4& v)
{
	os << "(" << v.x() << ", " << v.y() << ", " << v.z() << ", " << v.w() << ")";
	return os;
}

Vector4 operator+(const Vector4& v1, const Vector4& v2)
{
	// TODO: Implement here
}

Vector4 operator-(const Vector4& v1, const Vector4& v2)
{
	// TODO: Implement here
}

Vector4 operator*(float k, const Vector4& v)
{
	// TODO: Implement here
}

Vector4 operator*(const Vector4& v, float k)
{
	return Vector4(k * v.x(), k * v.y(), k * v.z(), k * v.w());
}

Vector4 operator/(const Vector4& v, float k)
{
	if (k == 0.0f)
	{
		return v;
	}
	else
	{
		return Vector4(v.x() / k, v.y() / k, v.z() / k, v.w() / k);
	}
}

float operator%(const Vector4& v1, const Vector4& v2)
{
	// TODO: Implement here
}


// Implementation of Matrix4x4 operations

std::ostream& operator<<(std::ostream& os, const Matrix4x4& m)
{
	os << "( ";
	os << "(" << m[0][0] << ", " << m[0][1] << ", " << m[0][2] << ", " << m[0][3] << "), ";
	os << "(" << m[1][0] << ", " << m[1][1] << ", " << m[1][2] << ", " << m[1][3] << "), ";
	os << "(" << m[2][0] << ", " << m[2][1] << ", " << m[2][2] << ", " << m[2][3] << "), ";
	os << "(" << m[3][0] << ", " << m[3][1] << ", " << m[3][2] << ", " << m[3][3] << "), ";
	os << " )";

	return os;
}

Matrix4x4 operator+(const Matrix4x4& m1, const Matrix4x4& m2)
{
	// TODO: Implement here
}

Matrix4x4 operator-(const Matrix4x4& m1, const Matrix4x4& m2)
{
	// TODO: Implement here
}

Matrix4x4 operator*(const Matrix4x4& m1, const Matrix4x4& m2)
{
	// TODO: Implement here
}

Vector4 operator*(const Matrix4x4& m, const Vector4& v)
{
	float w[4];

	for (int r = 0; r < 4; r++)
	{
		w[r] = Vector4(m[r][0], m[r][1], m[r][2], m[r][3]) % v;
	}

	return Vector4(w);
}


// Some helper functions for Vector3 and Vector4

Vector3 vector3_from_vertex(const Vertex& vertex)
{
	return Vector3(vertex.x, vertex.y, vertex.z);
}

Vector4 vector4_from_vertex(const Vertex& vertex)
{
	return Vector4(vertex.x, vertex.y, vertex.z, 1.0f);
}

float norm(const Vector3& v)
{
	return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

float norm(const Vector4& v)
{
	return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2] + v[3] * v[3]);
}

Vector3 normalize(const Vector3& v)
{
	Vector3 u(v);
	float s = 1.0f / norm(v);
	return s * u;
}

Vector4 normalize(const Vector4& v)
{
	Vector4 u(v);
	float s = 1.0f / norm(v);
	return s * u;
}


// Implementation of helper functions for Matrix4x4

Matrix4x4 matrix_identity()
{
	return Matrix4x4(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);
}

Matrix4x4 matrix_translation(float tx, float ty, float tz)
{
	return Matrix4x4(
		1, 0, 0, tx,
		0, 1, 0, ty,
		0, 0, 1, tz,
		0, 0, 0, 1
	);
}

// https://en.wikipedia.org/wiki/Rotation_matrix#General_rotations
Matrix4x4 matrix_rotation(const Vector3& axis, float angle)
{
	Vector3 u = normalize(axis);
	float ux = u.x();
	float uy = u.y();
	float uz = u.z();

	float cos_a = cosf(angle);
	float sin_a = sinf(angle);

	float _00 = cos_a + ux * ux * (1 - cos_a);
	float _01 = ux * uy * (1 - cos_a) - uz * sin_a;
	float _02 = ux * uy * (1 - cos_a) + uy * sin_a;
	float _03 = 0.0f;

	float _10 = uy * ux * (1 - cos_a) + uz * sin_a;
	float _11 = cos_a + uy * uy * (1 - cos_a);
	float _12 = uy * uz * (1 - cos_a) - ux * sin_a;
	float _13 = 0.0f;

	float _20 = uz * ux * (1 - cos_a) - uy * sin_a;
	float _21 = uz * uy * (1 - cos_a) + ux * sin_a;
	float _22 = cos_a + uz * uz * (1 - cos_a);
	float _23 = 0.0f;

	float _30 = 0.0f;
	float _31 = 0.0f;
	float _32 = 0.0f;
	float _33 = 1.0f;

	return Matrix4x4(
		_00, _01, _02, _03,
		_10, _11, _12, _13,
		_20, _21, _22, _23,
		_30, _31, _32, _33
	);
}

// http://www.codinglabs.net/article_world_view_projection_matrix.aspx
Matrix4x4 matrix_perspective(float fovy, float aspect_ratio, float z_near, float z_far)
{
	if (fovy == 0.0f || aspect_ratio == 0.0f || z_near == z_far)
	{
		return matrix_identity();
	}

	float fovx = 2.0f * atanf(tanf(fovy * 0.5f) * aspect_ratio);

	float _00 = 1.0f / tanf(fovx / 2.0f);
	float _01 = 0.0f;
	float _02 = 0.0f;
	float _03 = 0.0f;

	float _10 = 0.0f;
	float _11 = 1.0f / tanf(fovy / 2.0f);
	float _12 = 0.0f;
	float _13 = 0.0f;

	float _20 = 0.0f;
	float _21 = 0.0f;
	float _22 = -(z_far + z_near) / (z_far - z_near);
	float _23 = -2.0f * z_near * z_far / (z_far - z_near);

	float _30 = 0.0f;
	float _31 = 0.0f;
	float _32 = -1.0f;
	float _33 = 0.0f;

	return Matrix4x4(
		_00, _01, _02, _03,
		_10, _11, _12, _13,
		_20, _21, _22, _23,
		_30, _31, _32, _33
	);
}

// https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/lookat-function
Matrix4x4 matrix_lookat(const Vector3& eye, const Vector3& at, const Vector3& up)
{
	Vector3 n = normalize(eye - at);
	Vector3 u = normalize(normalize(up) ^ n);
	Vector3 v = normalize(n ^ u);

	float _00 = u.x();
	float _01 = u.y();
	float _02 = u.z();
	float _03 = -(eye % u);

	float _10 = v.x();
	float _11 = v.y();
	float _12 = v.z();
	float _13 = -(eye % v);

	float _20 = n.x();
	float _21 = n.y();
	float _22 = n.z();
	float _23 = -(eye % n);

	float _30 = 0.0f;
	float _31 = 0.0f;
	float _32 = 0.0f;
	float _33 = 1.0f;

	return Matrix4x4(
		_00, _01, _02, _03,
		_10, _11, _12, _13,
		_20, _21, _22, _23,
		_30, _31, _32, _33
	);
}

const float PI = 3.141592f;

float degree_from_radian(float rad)
{
	return rad * 180.0f / PI;
}

float radian_from_degree(float deg)
{
	// TODO: Implement here
}

