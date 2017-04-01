#pragma once
#include<iostream>
class VECTOR
{
public:
	enum Mode { RECT, POLAR };
	VECTOR(double x = 0, double y = 0, Mode mode = RECT);
	void reset(double x = 0, double y = 0, Mode mode = RECT);
	void set_mode(Mode mode);
		VECTOR operator + (const VECTOR & v) const;
	VECTOR operator - (const VECTOR & v) const;
	VECTOR operator - ();
	VECTOR operator * (double n) const;
	friend VECTOR operator * (double n, const VECTOR & v);
	friend std::ostream & operator <<(std::ostream & os, const VECTOR & v);
	double xval() const { return x_; }
	double yval() const { return y_; }
	double length() const { return length_; }
	double angle() const { return angle_; }
	~VECTOR();
private:
	double x_;
	double y_;
	double length_;
	double angle_;
	Mode mode_;
	          
	void set_x();
	void set_y();
	void set_length();
	void set_angle();
};