#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

/*被積分関数*/
double func(int n, double x, double phi)
{
  return cos(n * phi - x * sin(phi));
}

/*積分計算(台形和)*/
double bessel(int n, double x)
{
  double y;
  double phi;
  double d;
  int m = 10000; //分割数ちょうどいい

  d = M_PI / m;
  y = 0;
  for (int i = 0; i <= m; i++)
  {
    phi = d * i;
    y += (func(n, x, phi + d) + func(n, x, phi)) * d / 2;
  }
  return y / M_PI;
}

int main()
{
  int m;
  int mmax = 12; //あるnでの零点の数
  double al[] = {2.405, 5.5198, 8.654, 11.791, 14.931, 18.071, 21.212, 24.352, 27.494, 30.634, 33.777, 36.917};

  /*定義域を決める*/
  double r;
  double dr = 0.1; //ここ！
  double r0 = 0;
  double rmax = 1;
  /*定義域を決める*/
  double sita;
  double ds = 2 * M_PI * 0.1; //ここ！
  double s0 = 0;
  double smax = 2 * M_PI;
  /*定義域を決める*/
  double z;
  double dz = 0.1; ////ここ！
  double z0 = -1;
  double zmax = 1;

  /*fout出力*/
  ofstream fout;
  fout.open("d_bessel_function_laplace_m_test.dat");
  double phi;
  fout << "m=" << mmax << ",z=" << zmax << "\ndr,ds,dz=" << dr << "," << ds << "," << dz << "\nr*cos(sita)  r*sin(sita) z phi(r,sita,z)" << endl;
  for (int iz = 0; iz <= (zmax - z0) / dz; iz++)
  {
    z = z0 + dz * iz;
    cout << "z=" << z << endl;
    fout << "m=" << mmax << ",z=" << z << endl;
    for (int is = s0; is <= (smax - s0) / ds; is++)
    {
      sita = s0 + ds * is;
      for (int ir = 0; ir <= (rmax - r0) / dr; ir++)
      {
        r = r0 + dr * ir;
        phi = 0;
        for (m = 0; m < mmax; m++)
        {
          phi += 2 * bessel(0, al[m] * r) * cosh(al[m] * z) / al[m] / cosh(al[m]) / bessel(1, al[m]);
        }
        fout << r * cos(sita) << " " << r * sin(sita) << " " << z << " " << phi << endl;
      }
      fout << endl;
    }
    fout << endl;
  }
  fout.close();
}
