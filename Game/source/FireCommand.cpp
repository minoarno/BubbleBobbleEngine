#include "FireCommand.h"
#include "Character.h"
void FireCommand::Execute() const
{
	receiver->ShootBubble();
}
