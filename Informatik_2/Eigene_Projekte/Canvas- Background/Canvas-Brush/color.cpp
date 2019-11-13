#include "color.h"

Color::Color(const std::string farbe)
    :m_farbe(farbe)
{
    setColor();
}

Color::Color(int red, int green, int blue)
    :m_red(red), m_green(green), m_blue(blue)
{
    m_farbe = "Neue Farbe";
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

    else if (m_farbe == "weiß")
    {
        m_red = 255;
        m_green = 255;
        m_blue = 255;
    }
    else if (m_farbe == "schwarz")
    {
        m_red = 0;
        m_green = 0;
        m_blue = 0;
    }
    else
    {
        std::cerr << "Farbe unbekannt" << std::endl <<"Farbe blau gewählt" <<std::endl;
        m_farbe = "blue";
        m_red = 0;
        m_green = 100;
        m_blue = 240;
    }
}
