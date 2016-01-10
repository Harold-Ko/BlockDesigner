//-----------------------------------------------------------------------------
// Design								: Block Designer Command Queue 
// Autor								: Bryan.Choi 
// Email								: bryan.choi@twoblocktech.com 
// File		     					: CommandHandler.h
// Date	       					: 2015/1/4
// Reference            :
// ----------------------------------------------------------------------------
// Copyright (c) 2015 TwoBlockTechinologies Co.
// ----------------------------------------------------------------------------
// Description	: This class provide CommandHandler API 
// ----------------------------------------------------------------------------

#ifndef COMMANDHANDLER_H 
#define COMMANDHANDLER_H 

#include "BD_core/SimulationHandler/SimulationHandler.h"	
/*
 * namespace	: BDapi 
 * design	    : Block Designer API 
 * description	: support analyzing ESL platform based on systemc
 */

using namespace std;

namespace BDapi
{

/*
	 * class		: ExecutionManager 
	 * description	: Control Execution of simulation 
	 * version	    : v1.0 
	 */
	class CommandHandler 
	{
		public:
	

		/*
		 * function 	: 함수 명
		 * design	: 함수의 간략한 설명
		 * description	: 함수의 자세한 설명
		 * param	: 함수의 인자에 대한 설명 / void 시 줄 삭제
		 * return	: 함수의 반환 값에 대한 설명 / void 시 줄 삭제
		 * issue		: 함수의 필요성 혹은 함수에서 발견된 문제점 
		 * todo		: 함수의 수정이 필요한 부분 기술
		 * caller		: 이 함수를 호출하는 함수 명 표기
		 * callee		: 이 함수가 호출하는 함수 명 표기
		 * see		: 함수의 이해를 위해 참고할 만한 함수 혹은 라인을 표기
		 */
			void SetCommand(GUI_COMMAND st_Command);

			int Execute();
			int PutOperation();
			void ExcutionControl();

		private:
			GUI_COMMAND st_GUIcommand;
	};

} // namespace BDapi 

#endif 

