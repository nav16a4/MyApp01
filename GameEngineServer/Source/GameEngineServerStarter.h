#pragma once

namespace My
{
	namespace MyEngineServerStarter
	{

		class GameEngineServerStarter;
	}
}

class My::MyEngineServerStarter::GameEngineServerStarter
{

public:

	GameEngineServerStarter() = default;

	bool operator==(const GameEngineServerStarter& other) const
	{
		return false;
	}


	static void Test();

};

