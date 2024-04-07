#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>
#include <ostream>
#include <iomanip>
template<class T>

class Vector2D
{
public:
    T x, y;
    Vector2D() :x(0), y(0) {}
    Vector2D( T _x,  T _y) :x(_x), y(_y) {}
    Vector2D(const Vector2D& _v) :x(_v.x), y(_v.y) {}
    Vector2D& operator=(const Vector2D& _v)
    {
        x = _v.x;
        y = _v.y;
        return *this;
    }
    Vector2D operator+(Vector2D _v)
    {
        return Vector2D(x + _v.x, y + _v.y);
    }

    Vector2D operator-(Vector2D _v)
    {
        return Vector2D(x +(- _v.x), y +(- _v.y));
    }
    Vector2D& operator+=(Vector2D _v)
    {
        x += _v.x;
        y += _v.y;
        return *this;
    }
    Vector2D& operator-=(Vector2D _v)
    {
        x -= _v.x ;
        y -= _v.y;
        return *this;
    }
    Vector2D operator+(float _s)
    {
        return Vector2D(x + _s,y +_s);
    }
    Vector2D operator-(float _s)
    {
        return Vector2D(x + (-_s),y +(-_s));
    }
    Vector2D operator*(double s)
    {
        return Vector2D(x * s, y * s);
    }
    Vector2D operator/(float _s)
    {
        return Vector2D(x /(float) _s,y / (float)_s);
    }
    float operator*(Vector2D _v)
    {
        return _v.x * x + _v.y * y;
    }
    Vector2D& operator+=(float _s)
    {
        x += (float)_s;
        y += (float)_s;
        return *this;
    }
    bool operator!=(Vector2D _v)
    {
        if(x == (float)_v.x)
        {

            if( y == (float)_v.y)
            {

                return false;
            }
        }
        return true;
    }
    bool operator==(Vector2D _v)
    {
        if(x == (float)_v.x)
        {

            if( y == (float)_v.y)
            {

                return true;
            }
        }
        return false;
    }
    Vector2D& operator-=(float _s)
    {
        x -= _s;
        y -= _s;
        return *this;
    }
    Vector2D& operator*=(float _s)
    {
        x *= _s;
        y *= _s;
        return *this;
    }
    Vector2D& operator/=(float _s)
    {
        x /= _s;
        y /= _s;
        return *this;
    }
    Vector2D& operator-()
    {
        x *= -1;
        y *= -1;
        return *this;
    }
    Vector2D& GetRotation(float deg)
    {
    float ldeg2 = deg*(float)M_PI/(float)180;

double cs = cos(ldeg2);
double sn = sin(ldeg2);

        double px = x * cs - y * sn;
        double py = x * sn + y * cs;
x = px;
    y= py;

        return *this;
    }
    static int RadToDeg(float Rad)
    {
        return Rad*(float)180/(float)M_PI;
    }
    static float DegToRad(int Deg)
    {
        return (float)Deg/(float)(M_PI*180);
    }
    static bool isPerpendicular(Vector2D _v1,Vector2D _v2)
    {
        if(Vector2D::Dot(_v1.GetNormalise(),_v2.GetNormalise())==0.0)
            return true;
        else return false;
    }
    int vectorAngle(int _x, int _y)
    {
        if (_x == 0) // special cases
            return (_y > 0)? 90 : (_y == 0)? 0 : 270;
        else if (_y == 0) // special cases
            return (_x >= 0)? 0 : 180;
        int ret = RadToDeg(atanf((float)_y/_x));
        if (_x < 0 && _y < 0) // quadrant Ⅲ
            ret = 180 + ret;
        else if (_x < 0) // quadrant Ⅱ
            ret = 180 + ret; // it actually substracts
        else if (_y < 0) // quadrant Ⅳ
            ret = 270 + (90 + ret); // it actually substracts
        return ret;

    }
    static float GetAngle(int x1, int y1, int x2 ,int y2)
    {
        float angle = -90 + std::atan2(y1-y2,x1-x2)*(180/M_PI);
        return angle >= 0 ? angle : 360 + angle;
    }
    static int vectorAngle(Vector2D _v1,Vector2D _v2)
    {
        return  std::atan2(_v1.y +- _v2.y,_v1.x +- _v2.x)*180/M_PI;
    }
    void  Rotate(float deg)
    {
//        float ldeg = deg*(float)(180/(float)M_PI);
        float ldeg2 = deg*(float)M_PI/(float)180;
//        printf(" %f \n",ldeg);
      //  printf(" %f \n",ldeg2);
        // double angle = atan2f(y,x);
//        x = deg * cos(angle);
//        y = deg * sin(angle);
//        double c =  cos(deg);
//        double s =  sin(deg);
double cs = cos(ldeg2);
double sn = sin(ldeg2);

        double px = x * cs - y * sn;
        double py = x * sn + y * cs;
        x = px;

        y = py;

       // x' = xcosθ - ysinθ.
//        y' = xsinθ + ycosθ.
    }

     static Vector2D GetMidPoint(Vector2D v, Vector2D v1)
    {
return Vector2D((v.x+v1.x)/(float)2,(v.y+v1.y)/(float)2);
    }
    void Set(T x, T y)
    {
        this->x = x;
        this->y = y;
    }
    void SetEmpty()
    {
        this->x = 0.0;
        this->y = 0.0;
    }
    Vector2D GetNormalise()
    {
        Vector2D d(x,y);
        return d.Normalise();
    }
    static   Vector2D GetReflection(Vector2D NormSurface, Vector2D NormaInComingVector2D)
    {
        Vector2D n = NormSurface;
        Vector2D d = NormaInComingVector2D;
        float _2_dot = Dot(d,n);
        Vector2D r = Vector2D(d-(n*_2_dot)*2);
//=  Vector2D((2*Vector2D::Dot(d,n))d-n);
        return r;

////r=
////r = reflection vector
////d = normalised incoming vector
////n = normalised of surface its reflecting off
////(d.n) = is the dot product of d and n;
         }
   ////  std::cout  << std::acos(vec2f::Dot(a,b)/(float)(a.Length()*b.Length()))*180/M_PI << "\n"<< "\n";

    //    std::cout << vec2f::Dot(vec2f(1,2),vec2f(3,-8))/(float)std::sqrt((vec2f(3,-8).Length()*vec2f(3,-8).Length()))<< "           99999\n";

    Vector2D Normalise()
    {
        if(Length() == 0)

            return *this;


        *this *= (1.0 / Length());
        return *this;


    }
    float Dist(Vector2D _v) const
    {
        Vector2D d(_v.x - x, _v.y - y);
        return d.Length();
    }
    static float Dist(Vector2D _v,Vector2D _v2)
    {
        return _v.Dist(_v2);
    }
    static void Clamp(double Min, double Max,Vector2D &_v)
    {
       _v.Limit(Min);
        _v.Truncate(Max);
    }
    float Length() const
    {

        return std::sqrt( x * x + y * y);

    }
    Vector2D& Truncate(double length)
    {
       if (Length() > length)
        {
            Normalise();
  *this*=length;
            return *this;
        }
    }

    Vector2D GetOrtho() const
    {
        return Vector2D(y,-x);
    }
    void Ortho()
    {
        Vector2D temp = Vector2D(y,-x);
        y = temp.y;
        x = temp.x;
    }
    static  float Dot( Vector2D  _v1,Vector2D  _v2)
    {
        return (_v1.x * _v2.x) + (_v1.y * _v2.y);
    }
    float Cross( Vector2D & _v1,Vector2D & _v2)
    {
        return (_v1.x * _v2.y )- ( _v1.y * _v2.x);
    }
    Vector2D& Limit(float Min)
    {
         if (Length() < Min)
        {
            Normalise();
  *this*=Min;
            return *this;

    }
    }

    Vector2D& Floor(Vector2D  _V)
    {
          return Vector2D(std::floor(_V.x,_V.Y));
    }

Vector2D static Proj(Vector2D a,Vector2D b)
{
 Vector2D v;
 v = a * (Dot(a,b)/(float)(a.Length()*a.Length()));
return v;
}



    Vector2D static Lerp(Vector2D _v,Vector2D _v2, float amount)
    {

        Vector2D v;
        v.x = _v.x * amount + _v2.x* amount;
        v.y = _v.y * amount + _v2.y* amount;
        return v;
    }
    int GetArrayIndex(int Size_of_Rows,int tileSize = 0)
    {
        return x/tileSize + ((y/tileSize)*tileSize);
    }

    friend std::ostream& operator<< ( std::ostream& os, const Vector2D& c )
    {

        //std::fixed(os);
//  os   <<std::setprecision(0) <<" [" << c.x << "][" << c.y << "] " ;
        os   <<"[" << c.x << "][" << c.y << "]" ;
        return os;
    }
protected:

private:
};

typedef Vector2D<float> vec2f;
typedef Vector2D<double> vec2d;

typedef struct
{
    vec2f Min;
    vec2f Max;
} line;


typedef struct
{
    vec2f centre;
    float radius;
} circle;

typedef struct
{
    vec2f rectTopLeft;
    vec2f rectBottomRight;
} rectangle;

#endif // VECTOR2D_H
