#pragma once

class Point{
  int x = 0, y = 0;
  
  public:
  	
  int getX() { return x; }
  int getY() { return y; }

  void setX(int x) { this->x = x; }
  void setY(int y) { this->y = y; }

}; // class Point

class Line {
	Point p1,p2;
	
	public:
		
	Point getP1(){ return p1; }
	Point getP2(){ return p2; }
	
	void setP1(Point p1) { this->p1 = p1; }
	void setP2(Point p2) { this->p2 = p2; }
}; //class Line