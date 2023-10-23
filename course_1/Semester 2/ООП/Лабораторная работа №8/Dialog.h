#include "Event.h"
#include "list.cpp"

class Dialog : public List {
public:
	Dialog();
	virtual ~Dialog();
	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);
	int Valid();
	void EndExec();
protected:
	int EndState;
};