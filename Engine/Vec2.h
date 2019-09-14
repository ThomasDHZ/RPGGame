#pragma once
class Vec2
{
private:
	int x;
	int y;
public:
	Vec2();
	Vec2(int X, int Y);
	~Vec2();

	void SetX(int X);
	void SetY(int Y);
	int GetX() { return x; }
	int GetY() { return y; }

	Vec2 operator+(const Vec2& rhs);
	Vec2 operator-(const Vec2& rhs);
	Vec2& operator+=(const Vec2& rhs);
	Vec2& operator-=(const Vec2& rhs);
	bool operator==(const Vec2& rhs);
};

