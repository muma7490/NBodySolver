//
// Created by marco on 05.12.17.
//

#include "mvector.h"
#include <math.h>

/**
 * Assignment operator for MVector class. Assigns std::vector to current instance. Full copy of vector
 * @param vec Vector to assigned with
 * @return Instance of this class
 */
MVector& MVector::operator=(const MVector &vec)
{
    if(this == &vec)
        return *this;
    m_vector = vec.m_vector;
    return *this;
}

/**
 * Absolute value of vector. Iterates over components of vector, squares it and takes the squareroot of the sum.
 * @return Scalar absolute value of vector.
 */
double MVector::abs()
{
    double val = 0;

    for(auto it = m_vector.begin();it!=m_vector.end();++it)
    {
        val += pow((*it),2);
    }

    return sqrt(val);
}

/**
 * Plus operator for MVector class. Adds a scalar to every item of the vector
 * @note This could be improved using a lamda function (std::for_each or std::transform)
 * @param vec vector to be added with
 * @param val scalar value to be added
 * @return vector of size of vec
 */
MVector operator+(const MVector &vec,const double &val)
{
    MVector retVec;
    for(auto it = vec.m_vector.begin();it !=vec.m_vector.end();++it)
    {
        retVec.append((*it)+val);
    }
    return retVec;
}

/**
 * Minus operator for MVector class. Subtracts a scalar for every item of the vector
 * @param vec  vector to be subracted from
 * @param val  scalar value to be subtracted
 * @return vector of size of vec
 */
MVector operator-(const MVector &vec,const double &val)
{
    MVector retVec;
    for(auto it = vec.m_vector.begin();it !=vec.m_vector.end();++it)
    {
        retVec.append((*it)-val);
    }
    return retVec;
}

/**
 * Multiplication of vector with scalar.
 * @param vec vector to be multiplied with
 * @param val scalar value to be multiplied with
 * @return vector of size vec
 */
MVector operator*(const MVector &vec,const double &val)
{
    MVector retVec;
    for(auto it = vec.m_vector.begin();it !=vec.m_vector.end();++it)
    {
        retVec.append((*it)*val);
    }
    return retVec;
}

/**
 * Redundant class to allow scalar*vector
 * @see operator*
 */
MVector operator*(const double &val,const MVector &vec)
{
    return vec*val;
}

/**
 * Itemwhise multiplication of two vectors. Both vectors have to have equal size. Otherwhise will return empty vector
 * @return Vector of size vec1 and 2.
 */
MVector operator*(MVector vec1, MVector vec2)
{
    MVector retVec;
    if (vec1.size() == vec2.size())
    {
        auto itObj1 = vec1.begin();
        auto itObj2 = vec2.begin();

        while(itObj1 != vec1.end() && itObj2 != vec2.end())
        {
            retVec.append((*itObj1)*(*itObj2));
            ++itObj1;
            ++itObj2;
        }
    }
    return retVec;
}

/**
 * Divides a Vector through a scalar value
 */
MVector operator/(const MVector &vec,const double &val)
{
    MVector retVec;
    for(auto it = vec.m_vector.begin();it !=vec.m_vector.end();++it)
    {
        retVec.append((*it)/val);
    }
    return retVec;
}

/**
 * Itemwhise addition of two vectors.
 */
MVector operator+(MVector vec1,MVector vec2)
{
    MVector retVec;
    if (vec1.size() == vec2.size())
    {
        auto itVec1 = vec1.begin();
        auto itVec2 = vec2.begin();

        while(itVec1 != vec1.end() && itVec2 != vec2.end())
        {
            retVec.append((*itVec1)+(*itVec2));

            ++itVec1;
            ++itVec2;
        }
    }
    return retVec;
}

/**
 * Itemwhise subtraction of two vectors
 */
MVector operator-(MVector vec1,MVector vec2)
{
    MVector retVec;
    if (vec1.size() == vec2.size())
    {
        auto itVec1 = vec1.begin();
        auto itVec2 = vec2.begin();

        while(itVec1 != vec1.end() && itVec2 != vec2.end())
        {
            retVec.append((*itVec1)-(*itVec2));

            ++itVec1;
            ++itVec2;
        }
    }
    return retVec;
}

double dot(MVector vec1,MVector vec2)
{
    double retVal = 0.0;

    if (vec1.size() == vec2.size())
    {
        auto itVec1 = vec1.begin();
        auto itVec2 = vec2.begin();

        while(itVec1 != vec1.end() && itVec2 != vec2.end())
        {
            retVal += (*itVec1) * (*itVec2);

            ++itVec1;
            ++itVec2;
        }
    }
    return retVal;
}

MVector operator+=(const MVector &vec,const double &val)
{
    return vec + val;
}

MVector operator-=(const MVector &vec,const double &val)
{
    return vec - val;
}

MVector operator*=(const MVector &vec,const double &val)
{
    return vec*val;
}

MVector operator*=(const double &val,const MVector &vec)
{
    return vec*val;
}

MVector operator*=( MVector vec1, MVector vec2)
{
    return vec1*vec2;
}

MVector operator/=(const MVector &vec, const double &val)
{
    return vec/val;
}

MVector operator+=(MVector vec1,MVector vec2)
{
    return vec1 + vec2;
}

MVector operator-=(MVector vec1,MVector vec2)
{
    return vec1 - vec2;
}

bool operator==(const MVector &vec1,const MVector &vec2)
{
    return vec1.m_vector == vec2.m_vector;
}

