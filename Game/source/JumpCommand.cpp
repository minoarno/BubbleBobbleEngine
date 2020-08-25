#include "JumpCommand.h"
#include "Character.h"
void JumpCommand::Execute() const
{
	receiver->Jump();
}
