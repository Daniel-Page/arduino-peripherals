#ifndef MSG_H
#define MSG_H


class msg {
  public:
    void init();
    void stageBut(int num, ...);
    void stagePot(int num, ...);
    void transmit();
  private:
    String messageString;
};


#endif
