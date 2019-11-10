#include "color.h"

Color::Color(const std::string farbe)
    :m_farbe(farbe)
{
    setColor();
}

Color::Color(int red, int green, int blue)
    :m_red(red), m_green(green), m_blue(blue)
{
}

void Color::setColor()
{
    if(m_farbe == "red")
    {
        m_red = 255;
        m_green = 0;
        m_blue = 0;
    }
    else if (m_farbe == "yellow")
    {
        m_red = 255;
        m_green = 204;
        m_blue = 0;
    }
    else
    {
        m_farbe = "blue";
        m_red = 0;
        m_green = 100;
        m_blue = 240;
    }
}
