#ifndef COLOR_H
#define COLOR_H

#include <iostream>


class Color
{
public:
    Color(int red = 0, int green = 0, int blue = 0, int alpha = 0);
    Color(std::string farbe, int alpha = 0);
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
    uint8_t getalpha() const
    {
        return m_alpha;
    }

private:
  std::string m_farbe;
  uint8_t m_red;
  uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;
private:
   void setColor();
};

#endif // COLOR_H
