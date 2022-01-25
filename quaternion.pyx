# distutils: language = c++
# distutils: sources = mt19937.cpp

cdef extern from "quaternion.h" :
    cdef cppclass Quaternion:
        float w,x,y,z
        Quaternion(float, float, float, float)
        float dot(const Quaternion* q)
        int identity(const Quaternion* q)
        PyQuaternion conjugate(const Quaternion* pOut,const Quaternion* pIn)
       

cdef class PyQuaternion:
    cdef Quaternion*_thisptr
    def __cinit__(self, float _w, float _x, float _y, float _z):
        self._thisptr = new Quaternion(_w,_x,_y,_z)
        if self._thisptr == NULL:
            raise MemoryError()

    def __dealloc__(self):
        if self._thisptr != NULL:
            del self._thisptr

    @property 
    def w(self):
        return self._thisptr.w

    @w.setter
    def w(self, val):
        self._thisptr.w = val

    @property
    def x(self):
        return self._thisptr.x

    @x.setter
    def x(self,val):
        self._thisptr.x = val

    @property
    def y(self):
        return self._thisptr.y

    @y.setter
    def y(self,val):
        self._thisptr.y = val

    @property
    def z(self):
        return self._thisptr.z

    @z.setter
    def z(self,val):
        self._thisptr.z = val

    def dot(self, PyQuaternion q): 
        return self._thisptr.dot(q._thisptr)  

    def identity(self):
        return self._thisptr.identity(self._thisptr)
    
    def conjugate(self):
        return self._thisptr.conjugate(self._thisptr, self._thisptr)
    

