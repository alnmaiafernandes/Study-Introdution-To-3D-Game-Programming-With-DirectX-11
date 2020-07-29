// Chapter1-Vector-Algebra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>
#include <DirectXMath.h>

std::ostream& operator<<(std::ostream& os, const DirectX::XMFLOAT2& vVector)
{
    os << "(x: " << vVector.x << ", y: " << vVector.y << ")";
    return os;
}

class Vec2
{
public:
    float x, y;

    Vec2(float x, float y) noexcept : x(x), y(y) {}

    // Equality Operations
    const bool operator==(const Vec2& vToComp) noexcept
    {
        return x == vToComp.x && y == vToComp.y;
    }

    const bool operator!=(const Vec2& vToComp) noexcept
    {
        return !(*this == vToComp);
    }

    // Addition Operation
    Vec2 operator+(const Vec2& vToAdd) noexcept
    {
        return Vec2(x + vToAdd.x, y + vToAdd.y);
    }

    // Scalar Multiplication Operation
    Vec2 operator*(const float fScalar) noexcept
    {
        return Vec2(fScalar * x, fScalar * y);
    }

    // Subtraction Operation
    Vec2 operator-(const Vec2& vToSub) noexcept
    {
        return Vec2(x - vToSub.x, y - vToSub.y);
    }

    const float Magnitude() noexcept
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    const float Length() noexcept
    {
        const float fMagnitude = Magnitude();
        
        return 0.f;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec2& vec)
    {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

int main()
{
    Vec2 vFirstPoint(5.0f, 10.0f);
    Vec2 vSecondPoint(10.0f, 10.0f);
    Vec2 vFirstPlusSecond = vFirstPoint + vSecondPoint;
    Vec2 vFirstPlus2Scalar = vFirstPoint * 2;
    Vec2 vSecondSubFirst = vSecondPoint - vFirstPoint;

    std::cout << "First          : " << vFirstPoint << std::endl;
    std::cout << "Second         : " << vFirstPoint << std::endl;
    std::cout << "First + Second : " << vFirstPlusSecond << std::endl;
    std::cout << "First * 2f     : " << vFirstPlus2Scalar << std::endl;
    std::cout << "Second - First : " << vSecondSubFirst << std::endl;
    std::cout << "First.Magnitude: " << vFirstPoint.Magnitude() << std::endl;
    std::cout << "First.Length   : " << vFirstPoint.Magnitude() << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
