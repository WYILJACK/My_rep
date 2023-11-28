#include <iostream>

struct Figure
{
	Figure(std::string fill)
	{
		m_fill = fill;
	}
	std::string m_fill = "black";
};


struct Path : Figure {
	Path(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, std::string fill) : x1(x1),y1(y1),x2(x2),y2(y2),x3(x3),y3(y3),x4(x4),y4(y4), Figure(fill)
	{}
	int x1 = 0;
	int y1 = 0;
	int x2 = 0; 
	int y2 = 0; 
	int x3 = 0; 
	int y3 = 0; 
	int x4 = 0; 
	int y4 = 0; 
};

//output like "<circle cx="38.8" cy="30" r="10" fill="#591e3d"/>
std::ostream& operator <<(std::ostream& os, const Path& c)
{
	return os << "<path d=\"" << "M" << c.x1 << " " << c.y1 << " " << "L" << " " << c.x2 << " " << c.y2 << " " << "L" << " " << c.x3 << " " << c.y3 << " " << "L" << " " << c.x4 << " " << c.y4 << "fill =" << c.m_fill << "></path>";
}

int main()
{
	Path c1(90, 370, 170,220,220,245,138,395,"#001D3A");
	Path c2(116, 430, 259, 175, 268, 180, 125, 435, "#1670CA");
	Path c3(113, 455, 287, 145, 315, 160, 124, 461, "#E9C439");
	Path c4(134, 444, 360, 88, 460, 160, 190, 490,"black");
	Path c5(134, 444, 360, 88, 460, 160, 190, 490, "black");
	std::cout << c;
	return 0;
}

