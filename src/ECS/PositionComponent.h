#ifndef POSITION_COMPONENT_HPP_1234351223
#define POSITION_COMPONENT_HPP_1234351223

class PositionComponent: public Component{
public:
	int x() { return xpos; }
	
	int y() { return ypos; }
	
	PositionComponent(){
		xpos = 0;
		ypos = 0;
	}
	PositionComponent(int x, int y){
		xpos = x;
		ypos = y;
	}
	
	void update() override {
		xpos++;
		ypos++;
	}
	
	void setPos(int x, int y){
		xpos = x;
		ypos = y;
	}
	
private:
	int xpos;
	int ypos;
};

#endif