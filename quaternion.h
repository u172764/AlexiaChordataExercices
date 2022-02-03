#ifndef __QUATERNION__
#define __QUATERNION__

struct Quaternion;

float dot(const Quaternion* q);
int identity(const Quaternion* q);
Quaternion* const conjugate(Quaternion* pOut, const Quaternion* pIn);
void conjugate2(Quaternion* const q);

struct Quaternion {
  Quaternion(float _w, float _x, float _y, float _z):
  w(_w), x(_x), y(_y), z(_z)
  {};

  float dot(const Quaternion* q){
    return (this->w * q->w +
        this->x * q->x +
        this->y * q->y +
        this->z * q->z);
  }

  int identity(const Quaternion* q){
    return (q->x == 0.0 && q->y == 0.0 && q->z == 0.0 &&
        q->w == 1.0);
  }

  Quaternion* const conjugate(Quaternion* pOut, const Quaternion* pIn){

    pOut->x = -pIn->x;
    pOut->y = -pIn->y;
    pOut->z = -pIn->z;
    pOut->w = pIn->w;

    return pOut;
  }

  void conjugate2(Quaternion* const q){
    this->x = -q->x;
    this->y = -q->y;
    this->z = -q->z;
    this->w = q->w

  
  }

"""
  Quaternion* const conjugate(Quaternion* q){

    Quaternion* q_conj = new Quaternion(0,0,0,0);

    q_conj->x = -q->x; //o pasar en vez de q, -this->x, -this->y, -this->z, this->w. 
    q_conj->y = -q->y;
    q_conj->z = -q->z;
    q_conj->w = q->w;

    return q_conj;
  }
"""
  float w,x,y,z;

};


#endif

