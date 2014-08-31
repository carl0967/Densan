#include "Item.h"

class GoalFlag : public Item{
public:
	GoalFlag(double x,double y);
	void Affect(Character* character);
	void Think();
};