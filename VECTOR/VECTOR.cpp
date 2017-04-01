#include<cmath>
#include "VECTOR.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

const double Rad_to_deg = 45.0 / atan(1.0);

VECTOR::VECTOR(double x, double y, Mode mode)
{
	mode_ = mode;
	if (mode_ == RECT) {
		x_ = x;
		y_ = y;
		set_length();
		set_angle();
	}
	else if (mode == POLAR) {
		length_ = x;
		angle_ = y;
		set_x();
		set_y();
	}
	else {
		cout << "Incorrect third argument!\nMode set to RECT, x = 0, y = 0\n";
		mode_ = RECT;
		x_ = y_ = length_ = angle_ = 0;
	}
} // end of constructor
	void VECTOR::reset(double x, double y, Mode mode)
{
	mode_ = mode;
	if (mode_ == RECT) {
		x_ = x;
		y_ = y;
		set_length();
		set_angle();
	}
	else if (mode == POLAR) {
		length_ = x;
		angle_ = y;
		set_x();
		set_y();
	}
	else {
		cout << "Incorrect third argument!\nMode set to RECT, x = 0, y = 0\n";
		mode_ = RECT;
		x_ = y_ = length_ = angle_ = 0;
	}
}
	void VECTOR::set_mode(Mode mode)
{
	if (mode == RECT) {
		mode_ = RECT;
		//cout << "Mode set to RECT\n";
	}
	else if (mode = POLAR) {
		mode_ = POLAR;
		//cout << "Mode set to POLAR\n";
	}
	else {
		cout << "INCORRECT MODE. Mode set to RECT\n";
		mode_ = RECT;
	}
}
	VECTOR VECTOR::operator+(const VECTOR & v) const
{
	return VECTOR(x_ + v.x_, y_ + v.y_);
}
	VECTOR VECTOR::operator-(const VECTOR & v) const
{
	return VECTOR(x_ - v.x_, y_ - v.y_);
}
	VECTOR VECTOR::operator-()
{
	return VECTOR(-x_, -y_);
}
	VECTOR VECTOR::operator*(double n) const
{
	if (mode_ == POLAR) {
		return VECTOR(n * x_, y_);
	}
	else {
		return VECTOR(n * x_, n * y_);
	}
}
	VECTOR::~VECTOR()
{
}
	void VECTOR::set_x()
{
	x_ = length_ * cos(angle_);
}
	void VECTOR::set_y()
{
	y_ = length_ * sin(angle_);
}
	void VECTOR::set_length()
{
	length_ = sqrt(x_ * x_ + y_ * y_);
}
	void VECTOR::set_angle()
{
	if (x_ == 0 && y_ == 0) {
		angle_ = 0;
	}
	else {
		angle_ = atan2(y_, x_);
	}
}

VECTOR operator*(double n, const VECTOR & v)
{
	return v * n;
}
	std::ostream & operator<<(std::ostream & os, const VECTOR & v)
{
	if (v.mode_ == VECTOR::RECT) {
		os << "(x, y): " << "(" << v.x_ << "," << v.y_ << ")\n";
		return os;
	}
	else if (v.mode_ == VECTOR::POLAR) {
		os << "Length: " << v.length_ << "\t" << "Angle: " << v.angle_ *  Rad_to_deg << std::endl;
		return os;
	}
}