//
// Created by facuh on 8/30/25.
//

//Prevencion de multiples inclusiones en header
#ifndef TIME_H
#define TIME_H
//Definimos la clase TIME
class Time
{
  public:
    Time();
    void setTime( int, int, int);
    void printUniversal() const;
    void printStandard() const;
  private:
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
};

#endif //TIME_H
