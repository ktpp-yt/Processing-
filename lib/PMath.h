#ifndef MATH_H
#define MATH_H

#include <random>

namespace PMath{

    #define PI          3.14159265358979323846
    #define HALF_PI     PI/2.0
    #define QUARTER_PI  PI/4.0
    #define TWO_PI      PI*2.0
    #define TAU         TWO_PI

    #define max(a,b) a > b ? a : b
    #define min(a,b) a < b ? a : b

// normal_distribution<double>

    template<class T> T rand(T min, T max){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> distr(min, max);
        return static_cast<T>(distr(gen));
    }

    double randomGaussian(){
        std::default_random_engine gen;
        std::normal_distribution<double> distr;
        return distr(gen);
    }

    template<class T> T map(T val,T rmin,T rmax,T min,T max){
            T OldRange = rmax - rmin;
            T NewRange = max - min;
            return (((val - rmin) * NewRange) / OldRange) + min;
    }

    template<class T> T constrain(T val,T min,T max){
           if(val <= min) return min;
           else if(val >= max) return max;
           else return val;
    }

    template<class T> T norm(T val,T min,T max){
        return map<T>(val,min,max,0.f,1.f);
    }

    template<class T> T random(T x)       { return rand<T>(0,x); }
    template<class T> T random(T x,T y)   { return rand<T>(x,y); }

    template<class T> T dist(T x1,T y1,T x2,T y2){
        T x = (x2 - x1) * (x2 - x1);
        T y = (y2 - y1) * (y2 - y1);
        return sqrt(x + y);
    }

    template<class T> T dist(T x1,T y1,T z1,
                  T x2,T y2,T z2){
        T x = (x2 - x1) * (x2 - x1);
        T y = (y2 - y1) * (y2 - y1);
        T z = (z2 - z1) * (z2 - z1);
        return sqrt(x + y + z);
    }

    template<class T> T lerp(T start,T end, T amt){
        return start + (end-start) * amt;
    }

    template<class T> T mag(T x,T y){
        return dist<T>(0,0,x,y);
    }

    template<class T> T sq(T val){
        return val * val;
    }

    template<class T> T deg(T val){
        return val * (180.0/PI);
    }
    template<class T> T rad(T val){
        return val * (PI/180.0);
    }
}

#endif
