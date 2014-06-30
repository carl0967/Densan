
class AObject{
public:
	AObject(double x,double y);
	void Move();                  //自身のスピード分移動する
	void Draw(int offset);
	void Think();
}