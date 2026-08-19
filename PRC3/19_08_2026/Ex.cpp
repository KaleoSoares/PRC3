#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>

using namespace std;

typedef enum {
	A_IGUAL_B = -1,
	A_MENOR_B,
	A_MAIOR_B
} tEnumRel;

typedef enum {
	F24, F12
} tFormato;

typedef struct {
	int h;
	int m;
	int s;
	tFormato f;
} tRelogio;


class Relogio {
    private:
        int _h;
	    int _m;
	    int _s;
	    tFormato _f;

	    void _norm() {
        	_m = _m + _s / 60;
        	_s = _s % 60;
        	_h = _h + _m/60;
        	_m = _m % 60;
        	_h = _h % 24;
        }

    public:
        Relogio(int h = 0, int m = 0, int s = 0, tFormato f = F24) :
            _h(h), _m(m), _s(s), _f(f)
        {
        _norm();
        }

        void print() {
        	if(_f == F24) {
        		printf("%02d:%02d:%02d\n", _h, _m, _s);
        	} else {
        		int h = _h % 12;
        		if(h==0) h = 12;
        		printf("%02d:%02d:%02d %s\n", h, _m, _s, _h<12? "AM":"PM");
        	}
        }

        int clk() {
        	if((_s)++ >= 59) {
        		_s = 0;
        		if((_m)++ >= 59) {
        			_m = 0;
        			//*h = (*h+1) % 24;
        
        			if((_h)++>=23) {
        				_h = 0;
        				return 1;
        			}
        		}
        	}
	        return 0;
        }

        int set(Relogio r) {
            _h = r._h;
            _m = r._m;
            _s = r._s;
            _f = r._f;
	        _norm();
	        return r._h > 23 || r._m > 59|| r._s > 59;
        }

        Relogio soma(Relogio r2) {
            Relogio res;
            res._h = _h + r2._h;
            res._m = _m + r2._m;
            res._s = _s + r2._s;
            res._f = _f;
            res._norm();
            return res;
        }
};

/*
tEnumRel comparaRelogio(tRelogio r1, tRelogio r2) {
	if(r1.h != r2.h) {
	    if(r1.h > r2.h)
	        return A_MAIOR_B;
	   else
	        return A_MENOR_B;
	}
    if(r1.m != r2.m) {
        if(r1.m > r2.m)
            return A_MAIOR_B;
        else
            return A_MENOR_B;
    }
    if(r1.s != r2.s) {
        if(r1.s > r2.s)
            return A_MAIOR_B;
        else
            return A_MENOR_B;
    }
    return A_IGUAL_B;
}





/*
tRelogio somaNRelogios(int count, ...) {

}

int paraSegundos(tRelogio r) {
    return r.s + r.m * 60 + r.h*3600;
}

float paraMinutos(tRelogio r) {
    return r.m + r.s/60.0 + r.h*60;
}

float paraHoras(tRelogio r) {
    return r.h + r.s/3600.0 + r.m/60.;
}

tRelogio segundosPara(int s) {
    tRelogio x = {.s = s};
    return normRelogio(x);
}


tRelogio minutosPara(float m) {
    tRelogio x = {.m = m};
    return normRelogio(x);
}


tRelogio horasPara(float h) {
    tRelogio x = {.h = h};
    return normRelogio(x);
}

tRelogio togleFRelogio(tRelogio r) {
    if(r.f == F24){
        r.f = F12;
    } else {
        r.f = F24;
    }
    return r;
}

tRelogio setFRelogio(tRelogio* r, tFormato f) {
    r->f = f;
    return *r;
}
*/

int main()
{
    Relogio r1(0, 0, 0, F12);
    Relogio r2(r1);
    
    r1.print();
    r2.print();
}