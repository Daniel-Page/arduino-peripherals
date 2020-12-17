#ifndef IO_H
#define IO_H


class io {
  public:
    int pinAdr;
};


class button : io {
  public:
    button(int Adr, int mode);
    void invert();
    void poll();
    bool getState();
  private:
    int trigger;
    int state;
};


class led : io {
  public:
    led(int Adr, int mode);
    void on();
    void off();
};


class pot : io {
  public:
    pot(int Adr, int mode, int ADC_BITS, float VCC);
    float getVoltage();
  private:
    float VCC;
    int ADC_BITS;
    float voltage;
};


void invertTrigger(int num, ...);


void pollInputs(int num, ...);


int stageBut(int num, ...);


#endif
