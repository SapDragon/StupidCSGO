#pragma once
#include "../../../Core.hpp"

/*
 Vector2_t is a class that represents a vector in 2d dimension, this class implements basic geometric operations, as well as arefmetic operations with it.
 @SapDragon 26.11.2022
 Refactoring: 01.03.2022
*/

struct Vector2_t
{
	/* Fields ( x, y dots ) */
	f32 m_flX, m_flY;

	/* Basic constructors for initializing, reinitializing vectors. */
	Vector2_t() { m_flX = m_flY = 0.0f; }
	Vector2_t(f32 flX, f32 flY) { m_flX = flX; m_flY = flY; }
	Vector2_t(const Vector2_t& vec) { m_flX = vec.m_flX; m_flY = vec.m_flY; }

	/* Basic arithmetic operations with vectors. */
	Vector2_t operator+(const Vector2_t& vecAnother) const { return Vector2_t(m_flX + vecAnother.m_flX, m_flY + vecAnother.m_flY); }
	Vector2_t operator-(const Vector2_t& vecAnother) const { return Vector2_t(m_flX - vecAnother.m_flX, m_flY - vecAnother.m_flY); }
	Vector2_t operator*(const Vector2_t& vecAnother) const { return Vector2_t(m_flX * vecAnother.m_flX, m_flY * vecAnother.m_flY); }
	Vector2_t operator/(const Vector2_t& vecAnother) const { return Vector2_t(m_flX / vecAnother.m_flX, m_flY / vecAnother.m_flY); }
	
	Vector2_t& operator+=(const Vector2_t& vecAnother) { m_flX += vecAnother.m_flX; m_flY += vecAnother.m_flY; return *this; }
	Vector2_t& operator-=(const Vector2_t& vecAnother) { m_flX -= vecAnother.m_flX; m_flY -= vecAnother.m_flY; return *this; }
	Vector2_t& operator*=(const Vector2_t& vecAnother) { m_flX *= vecAnother.m_flX; m_flY *= vecAnother.m_flY; return *this; }
	Vector2_t& operator/=(const Vector2_t& vecAnother) { m_flX /= vecAnother.m_flX; m_flY /= vecAnother.m_flY; return *this; }
	
	/* Basic arithmetic operations with scalars. */
	Vector2_t operator+(f32 flScalar) const { return Vector2_t(m_flX + flScalar, m_flY + flScalar); }
	Vector2_t operator-(f32 flScalar) const { return Vector2_t(m_flX - flScalar, m_flY - flScalar); }
	Vector2_t operator*(f32 flScalar) const { return Vector2_t(m_flX * flScalar, m_flY * flScalar); }
	Vector2_t operator/(f32 flScalar) const { return Vector2_t(m_flX / flScalar, m_flY / flScalar); }
	
	Vector2_t& operator+=(f32 flScalar) { m_flX += flScalar; m_flY += flScalar; return *this; }
	Vector2_t& operator-=(f32 flScalar) { m_flX -= flScalar; m_flY -= flScalar; return *this; }
	Vector2_t& operator*=(f32 flScalar) { m_flX *= flScalar; m_flY *= flScalar; return *this; }
	Vector2_t& operator/=(f32 flScalar) { m_flX /= flScalar; m_flY /= flScalar; return *this; }
	
	/* Basic comparison operations with vectors. */
	bool operator==(const Vector2_t& vecAnother) const { return m_flX == vecAnother.m_flX && m_flY == vecAnother.m_flY; }
	bool operator!=(const Vector2_t& vecAnother) const { return m_flX != vecAnother.m_flX || m_flY != vecAnother.m_flY; }
	
	/* Another overloads */
	Vector2_t& operator=(const Vector2_t& vecAnother) { m_flX = vecAnother.m_flX; m_flY = vecAnother.m_flY; return *this; }
	Vector2_t operator-() const { return Vector2_t(-m_flX, -m_flY); }

	/* Basic geometric operations with vectors. */
	f32 Dot(const Vector2_t& vecAnother) const 
	{ 
		return m_flX * vecAnother.m_flX + m_flY * vecAnother.m_flY; 
	}
	
	f32 Cross(const Vector2_t& vecAnother) const
	{
		return m_flX * vecAnother.m_flY - m_flY * vecAnother.m_flX;
	}

	f32 Length() const
	{
		return sqrt(m_flX * m_flX + m_flY * m_flY);
	}
	
	f32 LengthSqr() const
	{
		return m_flX * m_flX + m_flY * m_flY;
	}

	Vector2_t& Normalize()
	{
		f32 flLength = Length();
		if (flLength == 0.0f)
			return *this;

		m_flX /= flLength;
		m_flY /= flLength;
		return *this;
	}

	Vector2_t Normalized() const
	{
		f32 flLength = Length();
		if (flLength == 0.0f)
			return *this;

		return Vector2_t(m_flX / flLength, m_flY / flLength);
	}

	f32 DistTo(const Vector2_t& vecAnother) const
	{
		return (*this - vecAnother).Length();
	}

	f32 DistToSqr(const Vector2_t& vecAnother) const
	{
		return (*this - vecAnother).LengthSqr();
	}
	
	/* Validity methods */

	bool IsValid() const
	{
		return !isinf(m_flX) && !isinf(m_flY);

	}
	
	bool IsZero() const
	{
		return m_flX == 0.0f && m_flY == 0.0f;
	}
	

	/* Another functions */
	void Clear()
	{
		m_flX = m_flY = 0.0f;
	}
	
};