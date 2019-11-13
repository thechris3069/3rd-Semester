#ifndef COLOR_H
#define COLOR_H

#include <iostream>


class Color
{
public:
    Color(int red = 0, int green = 0, int blue = 0);
    Color(std::string farbe);
    uint8_t getRed() const
    {
        return m_red;
    }
    uint8_t getGreen() const
    {
        return m_green;
    }
    uint8_t getBlue() const
    {
        return m_blue;
    }

private:
  std::string m_farbe;
  uint8_t m_red;
  uint8_t m_green;
    uint8_t m_blue;
private:
   void setColor();
};

#endif // COLOR_H
