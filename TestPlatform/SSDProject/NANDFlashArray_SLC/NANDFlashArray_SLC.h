/*
 *    Class definition of the SoC Designer component <NANDFlashArray_SLC>
 *
 *    This code has been generated by the SoC Designer Component Wizard.
 *    Copyright (c)  2008-2010 Carbon Design Systems Inc.
 *
 * THIS SOFTWARE CONTAINS CONFIDENTIAL INFORMATION AND TRADE SECRETS OF CARBON
 * DESIGN SYSTEMS, INC.  PERMISSION IS HEREBY GRANTED TO USE, MODIFY, AND/OR COPY
 * THIS SOFTWARE FOR INTERNAL USE ONLY PROVIDED THAT THE ABOVE COPYRIGHT NOTICE
 * APPEARS IN ALL COPIES OF THIS SOFTWARE.
 */

#ifndef __NANDFlashArray_SLC_H__
#define __NANDFlashArray_SLC_H__

/////////////// NAND FLASH Configuration ///////////////
#define PAGE_SIZE							2048
#define DATA_IN_OUT_DELAY_CYCLES			1024
#define SECTORS_PER_PAGE					4
#define PAGES_PER_BLOCK					   	16 
#define BLOCKS_PER_CHIP					    512	
////////////////////////////////////////////////////////

//////////////////// Binary Signal ////////////////////
#define HIGH								1
#define LOW									0
///////////////////////////////////////////////////////

//////////////////// Command Sets ////////////////////
#define READ_CMD1							0x00
#define READ_CMD2							0x30
#define READ_COPYBACK_CMD1					0x00
#define READ_COPYBACK_CMD2					0x35
#define PROG_CMD1							0x80
#define PROG_CMD2							0x10
#define PROG_COPYBACK_CMD1					0x85
#define PROG_COPYBACK_CMD2					0x10
#define ERASE_CMD1							0x60
#define ERASE_CMD2							0xD0
#define STATUS_CMD							0x70
//////////////////////////////////////////////////////

//////////////////// Debugging ////////////////////
#define DEBUG_VALUE							0xFF
#define COLUMN_ADDR							0x7D0
///////////////////////////////////////////////////

//////////////////// Read Status ////////////////////
#define SUCCESS								0xC0
#define FAIL								0xC1
/////////////////////////////////////////////////////

#include "BlockDesigner.h"
#include <stdio.h>
#include <string.h>

// for BDDI
#include "NANDFlashArray_SLC_BDDI.h"
#include "MemoryArray.h"

SC_MODULE(NANDFlashArray_SLC){

	/********** [port] **********/
	sc_in<bool>		HCLK;
	sc_in<bool>		HRESETn;

	// Place instance declarations for the Ports here:
	sc_in<unsigned int> D_in_SSlave;
	sc_in<unsigned int> S_in_SSlave;
	sc_out<unsigned int> D_out_SMaster;
	sc_out<unsigned int> RBn_SMaster;

	BDDI *bddi;

	//////////////////// NAND FLASH ////////////////////
	MemoryArray m_blocks[BLOCKS_PER_CHIP];
	////////////////////////////////////////////////////

	char temp_buffers[PAGE_SIZE];
	int m_indexes[BLOCKS_PER_CHIP];

	enum StateInfo {
		IDLE = 0,
		COMMAND,
		ADDRESS,
		BUSY,
		DATA,
		STATUS
	};

	enum SignalInfo {
		R_CMD = 44,
		R_ADDR = 41,
		W_CMD = 440,				// Not Used
		W_ADDR = 410,				// Not Used
		D_IN = 40,
		D_OUT = 48,
		R_BUSY = 1818,				// Not Used
		W_BUSY = 1819,				// Not Used
		E_BUSY = 1820,				// Not Used
		W_PROTECT = 1821,			// Not Used
		STAND_BY = 34
	};

	///// Pin /////
	uint32_t p_ALE;
	uint32_t p_CEn;
	uint32_t p_CLE;
	uint32_t p_RBn;
	uint32_t p_REn;
	uint32_t p_WEn;
	uint32_t p_WPn;
	///////////////

	///// Delay /////
	uint32_t p_tADL;
	uint32_t p_tBERS;
	uint32_t p_tPROG;
	uint32_t p_tR;
	uint32_t p_tRC;
	uint32_t p_tRR;
	uint32_t p_tWB;
	uint32_t p_tWC;
	/////////////////

	///// Global /////
	uint32_t state;

	uint32_t RWAddr_DelayCycles;
	uint32_t EAddr_DelayCycles;

	//	uint32_t RBusy_DelayCycles;
	//	uint32_t WBusy_DelayCycles;
	//	uint32_t EBusy_DelayCycles;
	//	uint32_t Copy_R_DelayCycles;
	//	uint32_t Copy_W_DelayCycles;

	enum BusyMode {
		NOT_BUSY = 0,
		BUSY_READ,
		BUSY_WRITE,
		BUSY_ERASE,
		BUSY_CB_READ, //copy-back read
		BUSY_CB_WRITE
	};

	uint32_t busy_mode;
	uint32_t busy_delay;

	uint32_t Dout_DelayCycles;
	uint32_t erase_page;
	uint16_t temp_data;
	uint16_t temp_signal;
	uint16_t temp_reg;
	int temp_page_n;
	int temp_blk_n;
	uint16_t check_signal;

	bool b_RWaddr_first_state;
	bool b_Eaddr_first_state;

	bool b_prepared_busy;
	//	bool b_Rbusy_first_state;
	//	bool b_Wbusy_first_state;
	//	bool b_CRbusy_first_state;
	//	bool b_Ebusy_first_state;
	//////////////////

	// Declare CADI Interface
	uint16_t r_DataReg;
	uint16_t r_CmdReg;
	uint16_t r_C_AddrReg;
	uint16_t r_P_AddrReg;
	uint16_t r_B_AddrReg;
	uint16_t r_StatusReg;

	// overloaded methods for clocked components
	void communicate();
	void update();

	//My functions
	void MyInit();
	void excuteCommand();
	void driveSignal();

	BDDI* GetBDDI();
	char* GetModuleName();
	void BDInit();

	~NANDFlashArray_SLC();

	SC_CTOR(NANDFlashArray_SLC)	{
		BDInit();

		SC_METHOD(communicate);
		sensitive << HCLK.pos();
		sensitive << HRESETn.neg();

		SC_METHOD(update);
		sensitive << HCLK.pos();
		sensitive << HRESETn.neg();

		SC_METHOD(driveSignal);
		sensitive << D_in_SSlave; 
	}
};

#endif
